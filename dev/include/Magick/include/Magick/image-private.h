/*
  Copyright (C) 2018 - 2019 GraphicsMagick Group

  This program is covered by multiple licenses, which are described in
  Copyright.txt. You should have received a copy of Copyright.txt with this
  package; otherwise see http://www.graphicsmagick.org/www/Copyright.html.

  GraphicsMagick Image Private declarations.
*/

/*
  ImageExtra allows for expansion of Image without increasing its
  size.  The internals are defined only in this private header file.
  Clients using the library can access the internals via the access
  functions provided by image.h.
*/
typedef struct _ImageExtra
{
  Image
    *clip_mask,       /* Private, clipping mask to apply when updating pixels */
    *composite_mask;  /* Private, compositing mask to apply when updating pixels */
} ImageExtra;

#define ImageGetClipMaskInlined(i) (&i->extra->clip_mask)

#define ImageGetCompositeMaskInlined(i) (&i->extra->composite_mask)
