/*
  Copyright (C) 2003 - 2018 GraphicsMagick Group
  Copyright (C) 2002 ImageMagick Studio

  This program is covered by multiple licenses, which are described in
  Copyright.txt. You should have received a copy of Copyright.txt with this
  package; otherwise see http://www.graphicsmagick.org/www/Copyright.html.

  GraphicsMagick Pixel Cache Private Methods.
*/

  /****
   *
   * Private interfaces.
   *
   ****/

  /*
    Access the default view
  */
  extern MagickExport ViewInfo
  *AccessDefaultCacheView(const Image *image);

  /*
    Destroy a thread view set.
  */
  extern void
  DestroyThreadViewSet(_ThreadViewSetPtr_ view_set);

  /*
    Allocate a thread view set.
  */
  extern _ThreadViewSetPtr_
  AllocateThreadViewSet(Image *image,ExceptionInfo *exception);

  /*
    Return one pixel at the the specified (x,y) location via a pointer
    reference.
  */
  extern MagickExport MagickPassFail
  AcquireOnePixelByReference(const Image *image,PixelPacket *pixel,
                             const long x,const long y,
                             ExceptionInfo *exception);

  /*
    DestroyImagePixels() deallocates memory associated with the pixel cache.

    Used only by DestroyImage().
  */
  extern MagickExport void
  DestroyImagePixels(Image *image);

  /*
    DestroyCacheInfo() deallocates memory associated with the pixel
    cache.

    Used only by DestroyImageInfo() to destroy a pixel cache
    associated with ImageInfo.
  */
  extern void
  DestroyCacheInfo(Cache cache);

  /*
    GetCacheInfo() initializes the Cache structure.

    Used only by AllocateImage() and CloneImage().
  */
  extern void
  GetCacheInfo(Cache *cache);

  /*
    GetPixelCacheInCore() tests to see the pixel cache is based on
    allocated memory and therefore supports efficient random access.
  */
  extern MagickBool
  GetPixelCacheInCore(const Image *image) MAGICK_FUNC_PURE;

  /*
    GetPixelCachePresent() tests to see the pixel cache is present
    and contains pixels.
  */
  extern MagickExport MagickBool
  GetPixelCachePresent(const Image *image) MAGICK_FUNC_PURE;

  /*
    Obtain an interpolated pixel value via bi-linear interpolation.
  */
  extern MagickExport PixelPacket
    InterpolateColor(const Image *image,const double x_offset,
      const double y_offset,ExceptionInfo *exception)
      MAGICK_FUNC_DEPRECATED;

  extern MagickExport MagickPassFail
    InterpolateViewColor(ViewInfo *view,PixelPacket *color,
       const double x_offset,const double y_offset,
       ExceptionInfo *exception);

  /*
    Modify cache ensures that there is only one reference to the
    pixel cache so that it may be safely modified.
  */
  extern MagickPassFail
  ModifyCache(Image *image, ExceptionInfo *exception);

  /*
    PersistCache() attaches to or initializes a persistent pixel cache.

    Used only by ReadMPCImage() and WriteMPCImage().
  */
  extern MagickExport MagickPassFail
  PersistCache(Image *image,const char *filename,const MagickBool attach,
               magick_off_t *offset,ExceptionInfo *exception);

  /*
    ReferenceCache() increments the reference count associated with
    the pixel cache.  Thread safe.

    Used only by CloneImage() and CloneImageInfo().
  */
  extern Cache
  ReferenceCache(Cache cache);

  /*
    Check image dimensions to see if they exceed current limits.
  */
  extern MagickExport MagickPassFail
  CheckImagePixelLimits(const Image *image, ExceptionInfo *exception);
