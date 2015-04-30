// stdafx.cpp : source file that includes just the standard includes
// ThumbFishTests.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <pantheios/frontend.h>

ExecuteFuncType pExecuteFunc;

// Custom Pantheios FrontEnd implementation to filter messages
PANTHEIOS_CALL(int) pantheios_fe_init(void* /* reserved */, void** ptoken)
{
	*ptoken = NULL;
	return 0;
}

PANTHEIOS_CALL(void) pantheios_fe_uninit(void* /* token */) {}
PANTHEIOS_CALL(PAN_CHAR_T const*) pantheios_fe_getProcessIdentity(void* /* token */) { return _T("ThumbFish"); }

PANTHEIOS_CALL(int) pantheios_fe_isSeverityLogged(void* /* token */, int severity, int /* backEndId */)
{
	return 1;	// log all messages
}

VERIFYDATA VerifyData[] = {
	{ false, fmtMOLV2, " V2000" },
	{ false, fmtMOLV3, " V3000" },
	{ false, fmtRXNV2, " V2000" },
	{ false, fmtRXNV3, " V3000" },
	{ true, fmtINCHI, "InChI=" },
	{ true, fmtCDXML, "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n<!DOCTYPE CDXML " },
	{ false, fmtEMF, "EMF" },
	{ true, fmtPNG, "�PNG" },
	{ true, fmtPDF, "%PDF" },
	{ true, fmtSVG, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg" },
	{ false, fmtMDLCT, " V3000" },
	{ true, fmtCML, "<?xml version=\"1.0\" ?>\n<cml>" },
	{ false, fmtMOLV2, " V2000" }
};

extern INPUT_MOLECULES InputMols[] = {
	{ fmtMOLV2, "Benzene\r\n  \r\n\r\n  6  6  0  0  0  0  0  0  0  0999 V2000\r\n   -0.7145    0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.7145   -0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.0000   -0.8250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.7145   -0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.7145    0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.0000    0.8250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n  1  2  2  0      \r\n  2  3  1  0      \r\n  3  4  2  0      \r\n  4  5  1  0      \r\n  5  6  2  0      \r\n  6  1  1  0      \r\nM  END\r\n" },
	{ fmtMOLV2, "Glucose\r\n  \r\n\r\n 12 11  0  0  0  0  0  0  0  0999 V2000\r\n    2.5006    0.2062    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0\r\n    1.7862   -0.2062    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    1.0717    0.2062    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    1.0717    1.0313    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.3572   -0.2062    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.3572   -1.0313    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.3572    0.2062    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.3572    1.0313    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -1.0717   -0.2062    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -1.0717   -1.0313    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -1.7862    0.2062    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -2.5006   -0.2062    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0\r\n  1  2  2  0      \r\n  2  3  1  0      \r\n  3  4  1  1      \r\n  3  5  1  0      \r\n  5  6  1  1      \r\n  5  7  1  0      \r\n  7  8  1  1      \r\n  7  9  1  0      \r\n  9 10  1  6      \r\n  9 11  1  0      \r\n 11 12  1  0      \r\nM  END\r\n" },
	{ fmtMOLV3, "Nonose V3000\r\n  \r\n\r\n  0  0  0     0  0              0 V3000\r\nM  V30 BEGIN CTAB\r\nM  V30 COUNTS 18 17 0 0 0\r\nM  V30 BEGIN ATOM\r\nM  V30 1 O -3.572355 -0.206250 0.000000 0\r\nM  V30 2 C -2.857884 0.206250 0.000000 0\r\nM  V30 3 C -2.143413 -0.206250 0.000000 0\r\nM  V30 4 O -2.143413 -1.031250 0.000000 0\r\nM  V30 5 C -1.428942 0.206250 0.000000 0\r\nM  V30 6 O -1.428942 1.031250 0.000000 0\r\nM  V30 7 C -0.714471 -0.206250 0.000000 0\r\nM  V30 8 O -0.714471 -1.031250 0.000000 0\r\nM  V30 9 C 0.000000 0.206250 0.000000 0\r\nM  V30 10 O 0.000000 1.031250 0.000000 0\r\nM  V30 11 C 0.714471 -0.206250 0.000000 0\r\nM  V30 12 O 0.714471 -1.031250 0.000000 0\r\nM  V30 13 C 1.428942 0.206250 0.000000 0\r\nM  V30 14 O 1.428942 1.031250 0.000000 0\r\nM  V30 15 C 2.143413 -0.206250 0.000000 0\r\nM  V30 16 O 2.143413 -1.031250 0.000000 0\r\nM  V30 17 C 2.857884 0.206250 0.000000 0\r\nM  V30 18 O 3.572355 -0.206250 0.000000 0\r\nM  V30 END ATOM\r\nM  V30 BEGIN BOND\r\nM  V30 1 2 1 2\r\nM  V30 2 1 3 4\r\nM  V30 3 1 3 2\r\nM  V30 4 1 5 6\r\nM  V30 5 1 5 3\r\nM  V30 6 1 7 8\r\nM  V30 7 1 7 5\r\nM  V30 8 1 9 10\r\nM  V30 9 1 9 7\r\nM  V30 10 1 11 12\r\nM  V30 11 1 11 9\r\nM  V30 12 1 13 14\r\nM  V30 13 1 13 11\r\nM  V30 14 1 15 16\r\nM  V30 15 1 15 13\r\nM  V30 16 1 17 18\r\nM  V30 17 1 17 15\r\nM  V30 END BOND\r\nM  V30 END CTAB\r\nM  END\r\n" },
	{ fmtRXNV2, "$RXN\r\nDiels Alder V2000\r\n  \r\n\r\n  2  1\r\n$MOL\r\n\r\n\r\n\r\n  6  5  0  0  0  0  0  0  0  0999 V2000\r\n    0.6489    0.9959    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.0656    0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.0656   -0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.6489   -0.9959    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.6489    0.8250    0.0000 R1  0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.6489   -0.8250    0.0000 R2  0  0  0  0  0  0  0  0  0  0  0  0\r\n  1  2  2  0        0\r\n  2  3  1  0        0\r\n  3  4  2  0        0\r\n  2  5  1  0        0\r\n  3  6  1  0        0\r\nM  END\r\n$MOL\r\n\r\n\r\n\r\n  4  3  0  0  0  0  0  0  0  0999 V2000\r\n   -0.2917    0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.2917   -0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.2917    0.9959    0.0000 R3  0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.2917   -0.9959    0.0000 R4  0  0  0  0  0  0  0  0  0  0  0  0\r\n  1  2  2  0        0\r\n  1  3  1  0        0\r\n  2  4  1  0        0\r\nM  END\r\n$MOL\r\n\r\n\r\n\r\n 10 10  0  0  0  0  0  0  0  0999 V2000\r\n   -0.7145    0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.7145   -0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.0000   -0.8250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.7145   -0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    0.7145    0.4125    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -0.0000    0.8250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n    1.4289    0.8250    0.0000 R3  0  0  0  0  0  0  0  0  0  0  0  0\r\n    1.4289   -0.8250    0.0000 R4  0  0  0  0  0  0  0  0  0  0  0  0\r\n   -1.4289    0.8250    0.0000 R1  0  0  0  0  0  0  0  0  0  0  0  0\r\n   -1.4289   -0.8250    0.0000 R2  0  0  0  0  0  0  0  0  0  0  0  0\r\n  1  2  2  0        0\r\n  2  3  1  0        0\r\n  3  4  1  0        0\r\n  4  5  1  0        0\r\n  5  6  1  0        0\r\n  6  1  1  0        0\r\n  5  7  1  0        0\r\n  4  8  1  0        0\r\n  1  9  1  0        0\r\n  2 10  1  0        0\r\nM  END\r\n" },
	{ fmtRXNV3, "$RXN V3000\r\nAmide Reaction V3000\r\n  \r\n\r\nM  V30 COUNTS 2 1\r\nM  V30 BEGIN REACTANT\r\nM  V30 BEGIN CTAB\r\nM  V30 COUNTS 5 4 0 0 0\r\nM  V30 BEGIN ATOM\r\nM  V30 1 C -0.714471 0.206250 0.000000 0\r\nM  V30 2 C 0.000000 -0.206250 0.000000 0\r\nM  V30 3 C -0.714471 1.031250 0.000000 0\r\nM  V30 4 O 0.714471 0.206250 0.000000 0\r\nM  V30 5 O 0.000000 -1.031250 0.000000 0\r\nM  V30 END ATOM\r\nM  V30 BEGIN BOND\r\nM  V30 1 1 1 2\r\nM  V30 2 1 1 3\r\nM  V30 3 1 2 4\r\nM  V30 4 2 2 5\r\nM  V30 END BOND\r\nM  V30 END CTAB\r\nM  V30 BEGIN CTAB\r\nM  V30 COUNTS 3 2 0 0 0\r\nM  V30 BEGIN ATOM\r\nM  V30 1 N -0.206250 -0.000001 0.000000 0\r\nM  V30 2 R2 0.206250 0.714471 0.000000 0\r\nM  V30 3 R1 0.206250 -0.714471 0.000000 0\r\nM  V30 END ATOM\r\nM  V30 BEGIN BOND\r\nM  V30 1 1 1 2\r\nM  V30 2 1 1 3\r\nM  V30 END BOND\r\nM  V30 END CTAB\r\nM  V30 END REACTANT\r\nM  V30 BEGIN PRODUCT\r\nM  V30 BEGIN CTAB\r\nM  V30 COUNTS 7 6 0 0 0\r\nM  V30 BEGIN ATOM\r\nM  V30 1 C -1.071707 0.206250 0.000000 0\r\nM  V30 2 C -0.357235 -0.206250 0.000000 0\r\nM  V30 3 C -1.071707 1.031250 0.000000 0\r\nM  V30 4 N 0.357236 0.206250 0.000000 0\r\nM  V30 5 O -0.357235 -1.031250 0.000000 0\r\nM  V30 6 R1 1.071707 -0.206249 0.000000 0\r\nM  V30 7 R2 0.357235 1.031250 0.000000 0\r\nM  V30 END ATOM\r\nM  V30 BEGIN BOND\r\nM  V30 1 1 1 2\r\nM  V30 2 1 1 3\r\nM  V30 3 1 2 4\r\nM  V30 4 2 2 5\r\nM  V30 5 1 4 6\r\nM  V30 6 1 4 7\r\nM  V30 END BOND\r\nM  V30 END CTAB\r\nM  V30 END PRODUCT\r\nM  END\r\n" },
	{ fmtSMILES, "C1CCCCC1\r\n" },		/* ending /r/n is a must */
	{ fmtSMILES, "Cn1cnc2n(C)c(=O)n(C)c(=O)c12\r\n" },
	{ fmtSMARTS, "C1=CC=CC=C1\r\n" },	/* ending /r/n is a must */
	{ fmtUnknown, "Untitled Document\r\n  \r\n\r\n 16 16  0  0  0  0  0  0  0  0999" },
	{ fmtUnknown, "" },
	{ fmtCML, "<?xml version=\"1.0\"?>\n<molecule xmlns=\"http://www.xml-cml.org/schema/cml2/core\" id=\"CS_chlorobenzene\">\n <formula concise=\" C 6 H 5 Cl 1 \"/>\n <identifier version=\"InChI/1\">\n  <basic>1/C6H5Cl/c7-6-4-2-1-3-5-6/h1-5H</basic>\n </identifier>\n <name convention=\"IUPAC\">Chlorobenzene</name>\n <atomArray>\n  <atom id=\"a1\" elementType=\"C\" x3=\"-0.169343\" y3=\"1.363035\" z3=\"0.000000\"/>\n  <atom id=\"a2\" elementType=\"C\" x3=\"1.126862\" y3=\"0.859946\" z3=\"0.000000\"/>\n  <atom id=\"a3\" elementType=\"C\" x3=\"1.343146\" y3=\"-0.514841\" z3=\"0.000000\"/>\n  <atom id=\"a4\" elementType=\"C\" x3=\"0.263390\" y3=\"-1.392785\" z3=\"0.000000\"/>\n  <atom id=\"a5\" elementType=\"C\" x3=\"-1.037001\" y3=\"-0.900580\" z3=\"0.000000\"/>\n  <atom id=\"a6\" elementType=\"C\" x3=\"-1.243609\" y3=\"0.476713\" z3=\"0.000000\"/>\n  <atom id=\"a7\" elementType=\"H\" x3=\"-0.351008\" y3=\"2.443119\" z3=\"0.000000\"/>\n  <atom id=\"a8\" elementType=\"H\" x3=\"1.978154\" y3=\"1.548584\" z3=\"0.000000\"/>\n  <atom id=\"a9\" elementType=\"H\" x3=\"2.365467\" y3=\"-0.906824\" z3=\"0.000000\"/>\n  <atom id=\"a10\" elementType=\"H\" x3=\"0.436227\" y3=\"-2.473988\" z3=\"0.000000\"/>\n <atom id=\"a11\" elementType=\"H\" x3=\"-1.894016\" y3=\"-1.582533\" z3=\"0.000000\"/>\n  <atom id=\"a12\" elementType=\"Cl\" x3=\"-2.818268\" y3=\"1.080154\" z3=\"0.000000\"/>\n </atomArray>\n <bondArray>\n  <bond atomRefs2=\"a1 a2\" order=\"2\"/>\n  <bond atomRefs2=\"a2 a3\" order=\"1\"/>\n  <bond atomRefs2=\"a3 a4\" order=\"2\"/>\n  <bond atomRefs2=\"a4 a5\" order=\"1\"/>\n  <bond atomRefs2=\"a5 a6\" order=\"2\"/>\n  <bond atomRefs2=\"a6 a1\" order=\"1\"/>\n  <bond atomRefs2=\"a1 a7\" order=\"1\"/>\n  <bond atomRefs2=\"a2 a8\" order=\"1\"/>\n  <bond atomRefs2=\"a3 a9\" order=\"1\"/>\n  <bond atomRefs2=\"a4 a10\" order=\"1\"/>\n  <bond atomRefs2=\"a5 a11\" order=\"1\"/>\n  <bond atomRefs2=\"a6 a12\" order=\"1\"/>\n </bondArray>\n</molecule>" },
	{ fmtCML, "<?xml version=\"1.0\"?>\r\n<cml xmlns=\"http://www.xml-cml.org/schema\">\r\n<molecule>\r\n<atomArray>\r\n<atom elementType=\"C\" id=\"a2\" x2=\"7.45733\" y2=\"-2.62717\"/>\r\n<atom elementType=\"C\" id=\"a4\" x2=\"7.45733\" y2=\"-4.15017\"/>\r\n<atom elementType=\"C\" id=\"a6\" x2=\"8.77629\" y2=\"-4.91167\"/>\r\n<atom elementType=\"C\" id=\"a8\" x2=\"10.0952\" y2=\"-4.15017\"/>\r\n<atom elementType=\"C\" id=\"a10\" x2=\"10.0952\" y2=\"-2.62717\"/>\r\n<atom elementType=\"C\" id=\"a12\" x2=\"8.77629\" y2=\"-1.86568\"/>\r\n</atomArray>\r\n<bondArray>\r\n<bond atomRefs2=\"a2 a4\" id=\"b14\" order=\"2\"/>\r\n<bond atomRefs2=\"a4 a6\" id=\"b15\" order=\"1\"/>\r\n<bond atomRefs2=\"a6 a8\" id=\"b16\" order=\"2\"/>\r\n<bond atomRefs2=\"a8 a10\" id=\"b17\" order=\"1\"/>\r\n<bond atomRefs2=\"a10 a12\" id=\"b18\" order=\"2\"/>\r\n<bond atomRefs2=\"a12 a2\" id=\"b19\" order=\"1\"/>\r\n</bondArray>\r\n</molecule>\r\n<molecule>\r\n<atomArray>\r\n<atom elementType=\"C\" id=\"a21\" x2=\"7.60963\" y2=\"-7.4627\"/>\r\n<atom elementType=\"C\" id=\"a22\" x2=\"7.60963\" y2=\"-8.9857\"/>\r\n<atom elementType=\"C\" id=\"a23\" x2=\"8.92859\" y2=\"-9.7472\"/>\r\n<atom elementType=\"C\" id=\"a24\" x2=\"10.2475\" y2=\"-8.9857\"/>\r\n<atom elementType=\"C\" id=\"a25\" x2=\"10.2475\" y2=\"-7.4627\"/>\r\n<atom elementType=\"C\" id=\"a26\" x2=\"8.92859\" y2=\"-6.7012\"/>\r\n<atom elementType=\"C\" id=\"a33\" x2=\"11.5665\" y2=\"-9.7472\"/>\r\n<atom elementType=\"C\" id=\"a35\" x2=\"12.8855\" y2=\"-8.9857\"/>\r\n<atom elementType=\"C\" id=\"a37\" x2=\"12.8855\" y2=\"-7.4627\"/>\r\n<atom elementType=\"C\" id=\"a39\" x2=\"11.5665\" y2=\"-6.7012\"/>\r\n<atom elementType=\"C\" id=\"a46\" x2=\"14.2044\" y2=\"-9.7472\"/>\r\n<atom elementType=\"C\" id=\"a48\" x2=\"15.5234\" y2=\"-8.9857\"/>\r\n<atom elementType=\"C\" id=\"a50\" x2=\"15.5234\" y2=\"-7.4627\"/>\r\n<atom elementType=\"C\" id=\"a52\" x2=\"14.2044\" y2=\"-6.7012\"/>\r\n<atom elementType=\"C\" hydrogenCount=\"3\" id=\"a59\" x2=\"16.8423\" y2=\"-6.7012\"/>\r\n<atom elementType=\"C\" hydrogenCount=\"3\" id=\"a61\" x2=\"6.29067\" y2=\"-9.7472\"/>\r\n</atomArray>\r\n<bondArray>\r\n<bond atomRefs2=\"a21 a22\" id=\"b27\" order=\"2\"/>\r\n<bond atomRefs2=\"a22 a23\" id=\"b28\" order=\"1\"/>\r\n<bond atomRefs2=\"a23 a24\" id=\"b29\" order=\"2\"/>\r\n<bond atomRefs2=\"a24 a25\" id=\"b30\" order=\"1\"/><bond atomRefs2=\"a25 a26\" id=\"b31\" order=\"2\"/>\r\n<bond atomRefs2=\"a26 a21\" id=\"b32\" order=\"1\"/>\r\n<bond atomRefs2=\"a24 a33\" id=\"b41\" order=\"1\"/>\r\n<bond atomRefs2=\"a33 a35\" id=\"b42\" order=\"2\"/>\r\n<bond atomRefs2=\"a35 a37\" id=\"b43\" order=\"1\"/>\r\n<bond atomRefs2=\"a37 a39\" id=\"b44\" order=\"2\"/>\r\n<bond atomRefs2=\"a39 a25\" id=\"b45\" order=\"1\"/>\r\n<bond atomRefs2=\"a35 a46\" id=\"b54\" order=\"1\"/>\r\n<bond atomRefs2=\"a46 a48\" id=\"b55\" order=\"2\"/>\r\n<bond atomRefs2=\"a48 a50\" id=\"b56\" order=\"1\"/>\r\n<bond atomRefs2=\"a50 a52\" id=\"b57\" order=\"2\"/>\r\n<bond atomRefs2=\"a52 a37\" id=\"b58\" order=\"1\"/>\r\n<bond atomRefs2=\"a50 a59\" id=\"b60\" order=\"1\"/>\r\n<bond atomRefs2=\"a22 a61\" id=\"b62\" order=\"1\"/>\r\n</bondArray>\r\n</molecule>" },
	{ fmtMOLV2, "\r\n  Ketcher 07061416122D 1   1.00000     0.00000     0\r\n\r\n  7  7  0     0  0            999 V2000\r\n   -3.7250    2.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -2.8590    2.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -2.8590    1.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -3.7250    0.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -4.5910    1.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -4.5910    2.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n   -1.9929    2.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0\r\n  1  2  1  0     0  0\r\n  2  3  2  0     0  0\r\n  3  4  1  0     0  0\r\n  4  5  2  0     0  0\r\n  5  6  1  0     0  0\r\n  6  1  2  0     0  0\r\n  2  7  1  0     0  0\r\nM  CHG  1   7   5\r\nM  END\r\n" }
};
