/*
  Copyright (C) 2003, 2005, 2008, 2013 GraphicsMagick Group
  Copyright (C) 2002 ImageMagick Studio

  This program is covered by multiple licenses, which are described in
  Copyright.txt. You should have received a copy of Copyright.txt with this
  package; otherwise see http://www.graphicsmagick.org/www/Copyright.html.

  GraphicsMagick Alpha Composite Methods.
*/

/*
  References on compositing:

    Porter, Thomas; Tom Duff (1984). "Compositing Digital Images". Computer Graphics.
      18 (3): 253.259. ISBN 0-89791-138-5. doi:10.1145/800031.808606

    SVG specification REC-SVG11-20110816.pdf, "Simple alpha compositing"
*/

#ifndef _MAGICK_ALPHA_COMPOSITE_H
#define _MAGICK_ALPHA_COMPOSITE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* defined(__cplusplus) || defined(c_plusplus) */

#if defined(MAGICK_IMPLEMENTATION)

static inline magick_uint32_t BlendQuantumOpacity(magick_uint32_t q,
  const magick_uint32_t opacity)
{
  magick_uint32_t
    result = 0U;

  if (opacity != 0U)
    {
      /*
        The 0==transparent/MaxRGB==opaque value for "opacity" is o = (MaxRGB-opacity),
        and the value for "q" is a = (MaxRGB-q), so the output value is o * a / MaxRGB.
        This value must be inverted to conform to the  0==opaque/MaxRGB==transparent
        convention used in this code.  When you work through the algebra you get
        result = opacity + q - opacity * q / MaxRGB.
      */
#if QuantumDepth > 16
#define _TCAST_  magick_uint64_t
#else
#define _TCAST_  magick_uint32_t
#endif
      result = opacity + q - ((_TCAST_)opacity * (_TCAST_)q + /*round*/(MaxRGB>>1))/MaxRGB;
#undef _TCAST_
    }
  return result;
}

static inline void BlendCompositePixel(PixelPacket *composite,
                                       const PixelPacket *p,
                                       const PixelPacket *q,
                                       const double alpha)
{
  double
    color,
    opacity;

  if (q->opacity == TransparentOpacity)
    {
          composite->red=p->red;
          composite->green=p->green;
          composite->blue=p->blue;
    }
  else if (p->opacity == TransparentOpacity)
    {
          composite->red=q->red;
          composite->green=q->green;
          composite->blue=q->blue;
    }
  else
    {
          color=((double) p->red*(MaxRGBDouble-alpha)+q->red*alpha)/MaxRGBDouble;
          composite->red=RoundDoubleToQuantum(color);

          color=((double) p->green*(MaxRGBDouble-alpha)+q->green*alpha)/MaxRGBDouble;
          composite->green=RoundDoubleToQuantum(color);

          color=((double) p->blue*(MaxRGBDouble-alpha)+q->blue*alpha)/MaxRGBDouble;
          composite->blue=RoundDoubleToQuantum(color);
    }

  opacity=((double) p->opacity*(MaxRGBDouble-alpha)+q->opacity*alpha)/MaxRGBDouble;
  composite->opacity=RoundDoubleToQuantum(opacity);
}

/*
  Alpha compose pixel 'change' over pixel 'base'.

  The result will be the union of the two image shapes, with
  opaque areas of change-image obscuring base-image in the
  region of overlap.
*/

/*
  Documentation for macro MagickAlphaCompositeQuantum:

    (1) GM uses the alpha value convention of 0 for opaque and MaxRGB for transparent, which is
    the opposite of the "standard" usage (see Porter/Duff and SVG references above).
    (2) Using the standard terminology of fg (foreground) and bg (background), and the standard
    representation of 0 for transparent and 1 for opaque, let:

      fg_alpha = (1.0 - change_alpha / MaxRGBDouble)
      bg_alpha = (1.0 - base_alpha / MaxRGBDouble)

    then MagickAlphaCompositeQuantum computes the following result:

      result = fg_alpha * fg + (1 - fg_alpha) * (bg_alpha * bg)

    This is the "standard" compositing equation when the fg and bg colors have not been premultiplied
    by their alpha values.  For reference, note that when the fg and bg colors HAVE been premultiplied,
    the compositing equation becomes the simple and elegant:

      result = fg + (1 - fg_alpha) * bg

    and this equation works for both the color components AND the alpha channel.  For the
    non-premultiplied case, the alpha equation is:

      result_alpha = fg_alpha + (1 - fg_alpha) * bg_alpha
*/

#define  MagickAlphaCompositeQuantum(change,change_alpha,base,base_alpha) \
   ((1.0-(change_alpha/MaxRGBDouble))*(double) change+(1.0-(base_alpha/MaxRGBDouble))*(double) base*(change_alpha/MaxRGBDouble))

static inline void AlphaCompositePixel(PixelPacket *composite, const PixelPacket *change,
                                       const double change_alpha,const PixelPacket *base,
                                       const double base_alpha)
{
  if (change_alpha == (double) TransparentOpacity)
    {
      if (composite != base)
        *composite=*base;
    }
  else
    {
      double
        delta,
        value;

      /*
        "delta" is the 0==transparent/1==opaque opacity value for the composited
        pixel (I checked the algebra).
      */
      delta=1.0-(change_alpha/MaxRGBDouble)*(base_alpha/MaxRGBDouble);

      value=MaxRGBDouble*(1.0-delta);   /* invert so 0==opaque, MaxRGB==transparent */
      composite->opacity=RoundDoubleToQuantum(value);

      /*
        The multiplicative inverse of "delta" is used to rescale the red, green, and
        blue composited pixel values so that they are not premultiplied by the alpha
        value.  Note the protection against divide-by-zero in case the composited pixel
        is completely transparent.
      */
      delta=1.0/(delta <= MagickEpsilon ? 1.0 : delta);

      value=delta*MagickAlphaCompositeQuantum(change->red,change_alpha,base->red,base_alpha);
      composite->red=RoundDoubleToQuantum(value);

      value=delta*MagickAlphaCompositeQuantum(change->green,change_alpha,base->green,base_alpha);
      composite->green=RoundDoubleToQuantum(value);

      value=delta*MagickAlphaCompositeQuantum(change->blue,change_alpha,base->blue,base_alpha);
      composite->blue=RoundDoubleToQuantum(value);
    }
}

/*
  The result is the same shape as base-image, with change-image
  obscuring base-image where the image shapes overlap. Note this
  differs from over because the portion of change-image outside
  base-image's shape does not appear in the result.
*/
static inline void AtopCompositePixel(PixelPacket *composite,
                                      const PixelPacket *base,
                                      const PixelPacket *change)
{
  double
    color,
    opacity;

  opacity=((double)(MaxRGBDouble-change->opacity)*
           (MaxRGBDouble-base->opacity)+(double) change->opacity*
           (MaxRGBDouble-base->opacity))/MaxRGBDouble;

  color=((double) (MaxRGBDouble-change->opacity)*
         (MaxRGBDouble-base->opacity)*change->red/MaxRGBDouble+(double)
         change->opacity*(MaxRGBDouble-base->opacity)*
         base->red/MaxRGBDouble)/opacity;
  composite->red=RoundDoubleToQuantum(color);

  color=((double) (MaxRGBDouble-change->opacity)*
         (MaxRGBDouble-base->opacity)*change->green/MaxRGBDouble+(double)
         change->opacity*(MaxRGBDouble-base->opacity)*
         base->green/MaxRGBDouble)/opacity;
  composite->green=RoundDoubleToQuantum(color);

  color=((double) (MaxRGBDouble-change->opacity)*
         (MaxRGBDouble-base->opacity)*change->blue/MaxRGBDouble+(double)
         change->opacity*(MaxRGBDouble-base->opacity)*
         base->blue/MaxRGBDouble)/opacity;
  composite->blue=RoundDoubleToQuantum(color);

  composite->opacity=MaxRGB-RoundDoubleToQuantum(opacity);
}


#endif /* defined(MAGICK_IMPLEMENTATION) */

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* defined(__cplusplus) || defined(c_plusplus) */

#endif /* _MAGICK_ALPHA_COMPOSITE_H */

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 2
 * fill-column: 78
 * End:
 */
