/*
  Copyright (C) 2003-2019 GraphicsMagick Group
  Copyright (C) 2002 ImageMagick Studio
  Copyright 1991-1999 E. I. du Pont de Nemours and Company

  This program is covered by multiple licenses, which are described in
  Copyright.txt. You should have received a copy of Copyright.txt with this
  package; otherwise see http://www.graphicsmagick.org/www/Copyright.html.

  X11 User Interface Methods for GraphicsMagick.
*/
#ifndef _MAGICK_WIDGET_H
#define _MAGICK_WIDGET_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

/*
  Enum declarations.
*/
typedef enum
{
  ControlState = 0x0001,
  InactiveWidgetState = 0x0004,
  JumpListState = 0x0008,
  RedrawActionState = 0x0010,
  RedrawListState = 0x0020,
  RedrawWidgetState = 0x0040,
  UpdateListState = 0x0100
} WidgetState;

/*
  Typedef declarations.
*/
typedef struct _MagickXWidgetInfo
{
  char
    *cursor,
    *text,
    *marker;

  int
    id;

  unsigned int
    bevel_width,
    width,
    height;

  int
    x,
    y,
    min_y,
    max_y;

  unsigned int
    raised,
    active,
    center,
    trough,
    highlight;
} MagickXWidgetInfo;

/*
  X utilities routines.
*/
extern int
  MagickXCommandWidget(Display *display,MagickXWindows *windows,
    const char * const *selections,XEvent *event),
  MagickXConfirmWidget(Display *display,MagickXWindows *windows,
    const char *reason,const char *description),
  MagickXDialogWidget(Display *display,MagickXWindows *windows,
    const char *action,const char *query,char *reply),
  MagickXMenuWidget(Display *display,MagickXWindows *windows,
    const char *title,const char * const *selections,char *item);

extern unsigned int
  MagickXPreferencesWidget(Display *display,
    MagickXResourceInfo *resource_info,MagickXWindows *windows);

extern void
  MagickXColorBrowserWidget(Display *display,MagickXWindows *windows,
    const char *action,char *reply),
  MagickXFileBrowserWidget(Display *display,MagickXWindows *windows,
    const char *action,char *reply),
  MagickXFontBrowserWidget(Display *display,MagickXWindows *windows,
    const char *action,char *reply),
  MagickXInfoWidget(Display *display,MagickXWindows *windows,
    const char *activity),
  MagickXListBrowserWidget(Display *display,MagickXWindows *windows,
  MagickXWindowInfo *window_info,const char * const *list,const char *action,
    const char *query,char *reply),
  MagickXMonitorWidget(Display *display,MagickXWindows *windows,
    const char *task,const magick_int64_t quantum,const magick_uint64_t span),
  MagickXNoticeWidget(Display *display,MagickXWindows *windows,
    const char *reason,const char *description),
  MagickXTextViewWidget(Display *display,
    const MagickXResourceInfo *resource_info,MagickXWindows *windows,
    const unsigned int mono,const char *title,const char * const *textlist),
  MagickXTextViewWidgetNDL(Display *display,const MagickXResourceInfo *resource_info,
    MagickXWindows *windows,const unsigned int mono,const char *title,
    const char *text_ndl,const size_t text_ndl_size);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 2
 * fill-column: 78
 * End:
 */
