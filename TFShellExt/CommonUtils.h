
#pragma once

#define MAX_FORMAT 10
#define MAX_EXTENSION 10
#define MAX_FORMAT_LONG 255
#define FOREACH_FORMATINFO(x) for(int index = 0; index < (sizeof(cFormatInfo)/sizeof(cFormatInfo[0])); index++) { x }

typedef struct
{
	ChemFormat format;
	TCHAR extension[MAX_EXTENSION];
	TCHAR formatTag[MAX_FORMAT];
	TCHAR formatTagLong[MAX_FORMAT_LONG];
} FORMATINFO, *LPFORMATINFO;

// FORMAT - EXTENSION - SHORT NAME - LONG NAME
const FORMATINFO cFormatInfo[] = {
	{ fmtMOLV2, _T(".mol"), _T("MOL V2000"), _T("MDL MOL V2000") },
	{ fmtMOLV3, _T(".mol"), _T("MOL V3000"), _T("MDL MOL V3000") },
	{ fmtRXNV2, _T(".rxn"), _T("RXN V2000"), _T("MDL RXN V2000") },
	{ fmtRXNV2, _T(".rxn"), _T("RXN V3000"), _T("MDL RXN V3000") },
	{ fmtCDXML, _T(".cdxml"), _T("CDXML"), _T("ChemDraw XML") },
	{ fmtSMILES, _T(".smi"), _T("SMILES"), _T("SMILES") },
	{ fmtSMILES, _T(".smiles"), _T("SMILES"), _T("SMILES") },
	{ fmtSMARTS, _T(".sma"), _T("SMARTS"), _T("SMARTS") },
	{ fmtSMARTS, _T(".smarts"), _T("SMARTS"), _T("SMARTS") },
	{ fmtSDFV2, _T(".sdf"), _T("SDF"), _T("Structure Data File") },
	{ fmtSDFV3, _T(".sdf"), _T("SDF V3000"), _T("Structure Data File (V3000)") },
	{ fmtRDFV2, _T(".rdf"), _T("RDF"), _T("Reaction Data File") },
	{ fmtRDFV3, _T(".rdf"), _T("RDF V3000"), _T("Reaction Data File (V3000)") },
	{ fmtEMF, _T(".emf"), _T("EMF"), _T("Enhanced Meta File") },
	{ fmtCML, _T(".cml"), _T("CML"), _T("Chemical Markup Language") },
	{ fmtPNG, _T(".png"), _T("PNG"), _T("Portable Network Graphics") },
	{ fmtPDF, _T(".pdf"), _T("PDF"), _T("Portable Document Format") },
	{ fmtSVG, _T(".svg"), _T("SVG"), _T("Scalable Vector Graphics") },
	{ fmtINCHI, _T(".inchi"), _T("INCHI"), _T("InChi") },
	{ fmtINCHIKEY, _T(".inchik"), _T("INCHIKEY"), _T("InChi Key") },
	{ fmtMDLCT, _T(".ct"), _T("MDLCT"), _T("MDL Connection Table") }
};

/**
	Contains helper functions common between the main dll and provider.
*/
class CommonUtils
{
public:
	static ChemFormat GetFormatFromFileName(TCHAR* fileName)
	{
		LPWSTR ext = ::PathFindExtension(fileName);
		FOREACH_FORMATINFO(if(TEQUAL(ext, cFormatInfo[index].extension)) return cFormatInfo[index].format;)
		return fmtUnknown;
	}

	static bool GetFormatString(ChemFormat fmt, TCHAR* outBuffer, int bufferLength)
	{
		FOREACH_FORMATINFO(if(fmt == cFormatInfo[index].format) 
			return (_tcscpy_s(outBuffer, bufferLength, cFormatInfo[index].formatTag) == 0);)
		return false;
	}

	static bool GetFormatExtension(ChemFormat fmt, TCHAR* outBuffer, int bufferLength)
	{
		FOREACH_FORMATINFO(if(fmt == cFormatInfo[index].format)
				return (_tcscpy_s(outBuffer, bufferLength, cFormatInfo[index].extension) == 0);)
		return false;
	}

	static bool IsMultiMolFormat(ChemFormat format)
	{
		return ((format == fmtSDFV2) || (format == fmtSDFV3) || (format == fmtRDFV2) || (format == fmtRDFV3) 
			|| (format == fmtCML) || (format == fmtSMILES));
	}

	static bool IsReadableFormat(ChemFormat format)
	{
		return ((format == fmtMOLV2) || (format == fmtMOLV3) || (format == fmtRXNV2) || (format == fmtRXNV3) 
			|| (format == fmtSDFV2)|| (format == fmtSDFV3) || (format == fmtRDFV2) || (format == fmtRDFV3) 
			|| (format == fmtCML) || (format == fmtSMILES) || (format == fmtSMARTS));
	}

	static bool IsMOLV2000Format(ChemFormat format)
	{
		return ((format == fmtMOLV2) || (format == fmtRXNV2) || (format == fmtSDFV2) || (format == fmtRDFV2));
	}

	static bool IsMOLV3000Format(ChemFormat format)
	{
		return ((format == fmtMOLV3) || (format == fmtRXNV3) || (format == fmtSDFV3) || (format == fmtRDFV3));
	}

	//-------------------------------------------------------------------------
	// Identifies the connection table version in a MOL or RXN file
	// Returns: 1=V2000, 2=V3000
	//-------------------------------------------------------------------------
	static int IdentifyCTVersion(PCHAR data, size_t dataLength, int lineNum)
	{
		int line = 0;
		for(int index = 0; index < dataLength; index++)
		{
			if(data[index] == '\n')
			{
				line++;

				// when we are at the end of desired line, check if the last few 
				// chars corresponds to some version number
				if(line == lineNum)
				{
					// if the LF char is preceded by a CR then we have to shift our compare index
					int shiftIndex = (data[index - 1] == '\r') ? 6 : 5;

					// compare the last 5/6 characters to get the version number
					// For V3000 format, the text 'V3000' will always be there. This is not true
					// for V2000 which could be missing in a RXN file
					if (_strnicmp(&(data[index - shiftIndex]), "V3000", 5) == 0) return 2;
					else return 1;	// default to V2000
				}
			}
		}

		return 1;	// v2000
	}
};
