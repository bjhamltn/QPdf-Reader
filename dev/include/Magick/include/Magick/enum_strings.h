/*
% Copyright (C) 2008 - 2018 GraphicsMagick Group
%
% This program is covered by multiple licenses, which are described in
% Copyright.txt. You should have received a copy of Copyright.txt with this
% package; otherwise see http://www.graphicsmagick.org/www/Copyright.html.
%
% Interfaces to convert to and from the string form of enumeration values.
%
% Written by Bob Friesenhahn, June 2008.
%
*/

#ifndef _ENUM_STRINGS_H
#define _ENUM_STRINGS_H

#include "magick/image.h"
#include "magick/blob.h"
#include "magick/compare.h"
#include "magick/confirm_access.h"
#include "magick/constitute.h"
#include "magick/operator.h"
#include "magick/pixel_cache.h"
#include "magick/render.h"
#include "magick/resource.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif


  extern MagickExport ChannelType StringToChannelType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport ColorspaceType StringToColorspaceType(const char *colorspace_string) MAGICK_FUNC_PURE;
  extern MagickExport CompositeOperator StringToCompositeOperator(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport CompressionType StringToCompressionType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport EndianType StringToEndianType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport FilterTypes StringToFilterTypes(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport GravityType StringToGravityType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport HighlightStyle StringToHighlightStyle(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport ImageType StringToImageType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport InterlaceType StringToInterlaceType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport MetricType StringToMetricType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport NoiseType StringToNoiseType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport OrientationType StringToOrientationType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport PreviewType StringToPreviewType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport ResolutionType StringToResolutionType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport QuantumOperator StringToQuantumOperator(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport ResourceType StringToResourceType(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport VirtualPixelMethod StringToVirtualPixelMethod(const char *option) MAGICK_FUNC_PURE;
  extern MagickExport const char *BlobModeToString(BlobMode blob_mode) MAGICK_FUNC_CONST;
  extern MagickExport const char *ChannelTypeToString(const ChannelType channel) MAGICK_FUNC_CONST;
  extern MagickExport const char *ClassTypeToString(const ClassType class_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *ColorspaceTypeToString(const ColorspaceType colorspace) MAGICK_FUNC_CONST;
  extern MagickExport const char *CompositeOperatorToString(const CompositeOperator composite_op) MAGICK_FUNC_CONST;
  extern MagickExport const char *CompressionTypeToString(const CompressionType compression_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *ConfirmAccessModeToString(const ConfirmAccessMode access_mode) MAGICK_FUNC_CONST;
  extern MagickExport const char *EndianTypeToString(const EndianType endian_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *HighlightStyleToString(const HighlightStyle difference_algorithm) MAGICK_FUNC_CONST;
  extern MagickExport const char *ImageTypeToString(const ImageType image_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *InterlaceTypeToString(const InterlaceType interlace_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *MapModeToString(MapMode map_mode) MAGICK_FUNC_CONST;
  extern MagickExport const char *MetricTypeToString(MetricType metric) MAGICK_FUNC_CONST;
  extern MagickExport const char *NoiseTypeToString(NoiseType noise_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *OrientationTypeToString(const OrientationType orientation_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *QuantumOperatorToString(const QuantumOperator quantum_operator) MAGICK_FUNC_CONST;
  extern MagickExport const char *QuantumSampleTypeToString(const QuantumSampleType sample_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *QuantumTypeToString(const QuantumType quantum_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *ResizeFilterToString(const FilterTypes filter) MAGICK_FUNC_CONST;
  extern MagickExport const char *ResolutionTypeToString(const ResolutionType resolution_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *StorageTypeToString(const StorageType storage_type) MAGICK_FUNC_CONST;
  extern MagickExport const char *StretchTypeToString(StretchType stretch) MAGICK_FUNC_CONST;
  extern MagickExport const char *StyleTypeToString(StyleType style) MAGICK_FUNC_CONST;

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif /* _ENUM_STRINGS_H */

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 2
 * fill-column: 78
 * End:
 */
