#pragma once

struct OPTIONS
{
		bool			Changed;					// specifies whether options have changed
	
		unsigned short  RenderMarginX;				// render-margins XY
		unsigned short	RenderMarginY;				// render-margins XY

		float			RenderRelativeThickness;	// render-relative-thickness D=1.0

		bool			RenderColoring;				// render-coloring BOOL D=False
		bool			RenderImplicitH;			// render-implicit-hydrogens-visible BOOL D=True
		bool			RenderShowAtomID;			// render-atom-ids-visible BOOL D=False
		bool			RenderShowBondID;			// render-bond-ids-visible BOOL D=False
		bool			RenderAtomBondIDFromOne;	// render-atom-bond-ids-from-one BOOL D=False

		COLORREF		RenderBaseColor;			// render-base-color STRING "r,g,b" D=BLACK
		COLORREF		RenderBackgroundColor;		// render-background-color STRING "r,g,b" D=TRANSPARENT

		unsigned short	RenderLabelMode;			// render-label-mode STRING "terminal-hetero"(D), "hetero", "none"
		unsigned short	RenderStereoStyle;			// render-stereo-style STRING "old"(D), "ext", "none"

public:
	OPTIONS() : Changed(true), RenderMarginX(20), RenderMarginY(20), RenderColoring(false), RenderImplicitH(true),
				RenderShowAtomID(false), RenderShowBondID(false), RenderAtomBondIDFromOne(true), 
				RenderBaseColor(RGB(0, 0, 0)), RenderBackgroundColor(RGB(255, 255, 255)), RenderLabelMode(0),
				RenderStereoStyle(1), RenderRelativeThickness(1.0)
	{
		//TODO: Init
	}

	//TODO: ReadOptions and SaveOptions
};
typedef OPTIONS* LPOPTIONS;

struct Buffer
{
	void*			pData;
	bool			isStream;
	ULONG			DataLength;
	TCHAR			FileName[MAX_PATH];

public:
	Buffer() : pData(NULL), isStream(false), DataLength(0) {}
};

typedef Buffer BUFFER, *LPBUFFER;

typedef bool (__cdecl *DrawFuncType)(HDC hDC, LPRECT lpRect, LPBUFFER buffer, LPOPTIONS options);
typedef int	 (__cdecl *GetPropertiesFuncType)(LPBUFFER buffer, TCHAR*** properties, LPOPTIONS options);

//typedef std::basic_string<TCHAR> tstring;
//typedef std::basic_ofstream<TCHAR> tofstream;
//
//typedef struct
//{
//	void*		pData;
//	ULONG		DataLength;
//	tstring		FileName;
//} BUFFER, *LPBUFFER;
//
//typedef struct
//{
//	wchar_t		FileName[MAX_PATH];		// file name without path
//	wchar_t		Format[255];			// info on format type
//	wchar_t		MolName[255];
//	wchar_t		Formula[255];
//	wchar_t		FormulaHTML[255];
//	wchar_t		SMILES[512];
//	wchar_t		InChI[512];
//	wchar_t		InChIKey[512];
//	wchar_t		Composition[255];
//	int			HBDonor;
//	int			HBAcceptor;
//	int			NumAtoms;
//	double		MolWeight;
//	long		MolCount;				// for SDF preview
//} PROPS, *LPPROPS;
//
//struct USEROPTIONS
//{
//	//bool		P_DrawBorder;			// whether to draw border around molecules in preview
//	bool		SDFDrawMolBorder;		// whether to draw border around molecules for SDF
//	//int		P_SDFMaxMolsDraw;		// specifies the maximum molecules to draw in SDF preview
//	int			SDFMaxMolsDraw;			// specifies the maximum molecules to draw on SDF thumbnail
//	int			SDFMaxMolsRead;			// specifies the maximum molecules to read from SDF file
//										// In case of preview, the SDF buffer decides max mols read
//	//bool		P_SDFDrawMolCount;		// whether to draw molecule count in SDF preview
//	bool		SDFDrawMolCount;		// whether to draw molecule count on SDF thumbnail
//	//COLORREF	P_BGColor;				// background color of molecule preview in preview window
//	COLORREF	BGColor;				// background color of molecule thumbnail
//	int			SDFThumbnailMolXY;		// width and height of each molecule in a SDF thumbnail
//	int			SDFMolBufferSize;		// size in bytes of buffer for mols read from SDF
//
//	// ctor for default Thumbnail options
//	USEROPTIONS() : SDFDrawMolBorder(false), SDFMaxMolsDraw(4), SDFMaxMolsRead(1000), 
//		SDFDrawMolCount(true), BGColor(RGB(255, 255, 255)), SDFThumbnailMolXY(112), 
//		SDFMolBufferSize(8 * 1024)
//	{
//	}
//
//	// ctor for default Preview options
//	USEROPTIONS(bool preview) : SDFDrawMolBorder(true), SDFMaxMolsDraw(INT_MAX), 
//		SDFMaxMolsRead(1000), SDFDrawMolCount(false), BGColor(RGB(255, 255, 255)), 
//		SDFThumbnailMolXY(112), SDFMolBufferSize(8 * 1024)
//	{
//	}
//};
//
//typedef USEROPTIONS* LPUSEROPTIONS;
