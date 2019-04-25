/*
    Copyright 2015 Wolfgang Thaller.

    This file is part of Retro68.

    Retro68 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Retro68 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Retro68.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <MacWindows.h>
#include <Quickdraw.h>
#include <Dialogs.h>
#include <Fonts.h>



#ifndef TARGET_API_MAC_CARBON
    /* NOTE: this is checking whether the Dialogs.h we use *knows* about Carbon,
             not whether we are actually compiling for Cabon.
             If Dialogs.h is older, we add a define to be able to use the new name
             for NewUserItemUPP, which used to be NewUserItemProc. */
#define NewUserItemUPP NewUserItemProc
#endif

pascal void ButtonFrameProc(DialogRef dlg, DialogItemIndex itemNo)
{
    DialogItemType type;
    Handle itemH;
    Rect box;

    GetDialogItem(dlg, 1, &type, &itemH, &box);
    InsetRect(&box, -4, -4);
    PenSize(3,3);
    FrameRoundRect(&box,16,16);
}

// Initialize
void Initialize() {
#if !TARGET_API_MAC_CARBON
InitGraf(&qd.thePort);
InitFonts();
InitWindows();
InitMenus();
TEInit();
InitDialogs(NULL);
#endif

//Handle menubar = GetNewMBar(defaultMenubar);
//SetMenuBar(menubar);
//DrawMenuBar();
InitCursor();
}

int main()
{
    Initialize();

    DialogPtr dlg = GetNewDialog(128,0,(WindowPtr)-1);
    DialogItemType type;
    Handle itemH;
    Rect box;

    GetDialogItem(dlg, 2, &type, &itemH, &box);
    SetDialogItem(dlg, 2, type, (Handle) NewUserItemUPP(&ButtonFrameProc), &box);
    short item;
    do {
        ModalDialog(NULL, &item);
    } while(item != 1);

    FlushEvents(everyEvent, -1);
    return 0;
}
