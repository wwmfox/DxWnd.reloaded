// debug functions to make the log more readable

extern void DumpRect(char *, LPRECT, int);
extern char *ExplainFlags(DWORD);
extern char *ExplainDDSCaps(DWORD);
extern char *ExplainCoopFlags(DWORD);
extern char *ExplainPixelFormatFlags(DWORD);
extern char *ExplainFlipFlags(DWORD);
extern char *ExplainFlipStatusFlags(DWORD);
extern char *ExplainBltFlags(DWORD);
extern char *ExplainBltFastFlags(DWORD);
extern char *ExplainCreatePaletteFlags(DWORD);
extern char *ExplainLockFlags(DWORD);
extern char *ExplainStyle(DWORD);
extern char *ExplainExStyle(DWORD);
extern char *ExplainShowCmd(int);
extern char *ExplainBltStatus(DWORD);
extern char *ExplainDDError(DWORD);
extern char *ExplainPixelFlags(DWORD);
extern char *ExplainWinMessage(DWORD);
extern char *ExplainResizing(DWORD);
extern char *ExplainDeviceCaps(DWORD);
extern char *ExplainDisplaySettingsRetcode(DWORD);
extern char *ExplainSetWindowIndex(DWORD);
extern char *ExplainColorKeyFlag(DWORD);
extern char *ExplainGUID(GUID FAR *);
extern char *ExplainROP(DWORD);
extern char *ExplainNChitTest(DWORD);
extern char *ExplainDDEnumerateFlags(DWORD);
