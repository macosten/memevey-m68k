#include "Dialogs.r"

#define MemeveyDITL 128

resource 'DLOG' (MemeveyDITL) {
	//Top Left Bottom Right
	{ 100, 125, 145+110, 385+100 },
	dBoxProc,
 	visible,
 	noGoAway,
 	0,
 	128,
 	"",
 	centerMainScreen
};

resource 'DITL' (MemeveyDITL) {
	{
		// Top Left Bottom Right 
		{ 110, 200, 130, 320 },
		Button { enabled, "Yes, Master" };

		{ 110-5, 200-5, 130+5, 320+5 },
		UserItem {enabled};

		{ 30, 110, 100, 350 },
		StaticText {enabled, "This is Memevey. Copy and paste Memevey to 10 other resource forks or she will never be a meme..."};
		
		{25, 10, 95, 105},
		Picture {enabled, 128};

	}
};

#include "Processes.r"

resource 'SIZE' (-1) {
	dontSaveScreen,
	acceptSuspendResumeEvents,
	enableOptionSwitch,
	canBackground,
	multiFinderAware,
	backgroundAndForeground,
	dontGetFrontClicks,
	ignoreChildDiedEvents,
	is32BitCompatible,
	isHighLevelEventAware,
	onlyLocalHLEvents,
	notStationeryAware,
	reserved,
	reserved,
	reserved,
	reserved,
#ifdef TARGET_API_MAC_CARBON
	500 * 1024,	// Carbon apparently needs additional memory.
	500 * 1024
#else
	100 * 1024,
	100 * 1024
#endif
};
