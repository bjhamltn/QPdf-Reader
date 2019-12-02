#ifndef _LOCAL_C_H
#define _LOCAL_C_H

extern MagickExport const char *GetLocaleMessageFromID(const int) MAGICK_FUNC_CONST;

#define MAX_LOCALE_MSGS 579

#define MGK_BlobErrorUnableToCreateBlob 1
#define MGK_BlobErrorUnableToDeduceImageFormat 2
#define MGK_BlobErrorUnableToObtainOffset 3
#define MGK_BlobErrorUnableToOpenFile 4
#define MGK_BlobErrorUnableToReadFile 5
#define MGK_BlobErrorUnableToReadToOffset 6
#define MGK_BlobErrorUnableToSeekToOffset 7
#define MGK_BlobErrorUnableToWriteBlob 8
#define MGK_BlobErrorUnrecognizedImageFormat 9
#define MGK_BlobFatalErrorDefault 10
#define MGK_BlobWarningDefault 11
#define MGK_CacheErrorEmptyCacheNexus 12
#define MGK_CacheErrorInconsistentPersistentCacheDepth 13
#define MGK_CacheErrorPixelCacheDimensionsMisMatch 14
#define MGK_CacheErrorPixelCacheIsNotOpen 15
#define MGK_CacheErrorUnableToAllocateCacheView 16
#define MGK_CacheErrorUnableToCloneCache 17
#define MGK_CacheErrorUnableToExtendCache 18
#define MGK_CacheErrorUnableToGetCacheNexus 19
#define MGK_CacheErrorUnableToGetPixelsFromCache 20
#define MGK_CacheErrorUnableToOpenCache 21
#define MGK_CacheErrorUnableToPeristPixelCache 22
#define MGK_CacheErrorUnableToReadPixelCache 23
#define MGK_CacheErrorUnableToSyncCache 24
#define MGK_CacheFatalErrorDiskAllocationFailed 25
#define MGK_CacheFatalErrorUnableToExtendPixelCache 26
#define MGK_CacheWarningDefault 27
#define MGK_CoderErrorArithmeticOverflow 28
#define MGK_CoderErrorColormapTooLarge 29
#define MGK_CoderErrorColormapTypeNotSupported 30
#define MGK_CoderErrorColorspaceModelIsNotSupported 31
#define MGK_CoderErrorColorTypeNotSupported 32
#define MGK_CoderErrorCompressionNotValid 33
#define MGK_CoderErrorDataEncodingSchemeIsNotSupported 34
#define MGK_CoderErrorDataStorageTypeIsNotSupported 35
#define MGK_CoderErrorDecodedImageNotReturned 36
#define MGK_CoderErrorDeltaPNGNotSupported 37
#define MGK_CoderErrorDivisionByZero 38
#define MGK_CoderErrorEncryptedWPGImageFileNotSupported 39
#define MGK_CoderErrorFractalCompressionNotSupported 40
#define MGK_CoderErrorImageColumnOrRowSizeIsNotSupported 41
#define MGK_CoderErrorImageDoesNotHaveAMatteChannel 42
#define MGK_CoderErrorImageIsNotTiled 43
#define MGK_CoderErrorImageTypeNotSupported 44
#define MGK_CoderErrorIncompatibleSizeOfDouble 45
#define MGK_CoderErrorIrregularChannelGeometryNotSupported 46
#define MGK_CoderErrorJNGCompressionNotSupported 47
#define MGK_CoderErrorJPEGCompressionNotSupported 48
#define MGK_CoderErrorJPEGEmbeddingFailed 49
#define MGK_CoderErrorLocationTypeIsNotSupported 50
#define MGK_CoderErrorMapStorageTypeIsNotSupported 51
#define MGK_CoderErrorMSBByteOrderNotSupported 52
#define MGK_CoderErrorMultidimensionalMatricesAreNotSupported 53
#define MGK_CoderErrorMultipleRecordListNotSupported 54
#define MGK_CoderErrorNo8BIMDataIsAvailable 55
#define MGK_CoderErrorNoAPP1DataIsAvailable 56
#define MGK_CoderErrorNoBitmapOnClipboard 57
#define MGK_CoderErrorNoColorProfileAvailable 58
#define MGK_CoderErrorNoDataReturned 59
#define MGK_CoderErrorNoImageVectorGraphics 60
#define MGK_CoderErrorNoIPTCInfoWasFound 61
#define MGK_CoderErrorNoIPTCProfileAvailable 62
#define MGK_CoderErrorNumberOfImagesIsNotSupported 63
#define MGK_CoderErrorOnlyContinuousTonePictureSupported 64
#define MGK_CoderErrorOnlyLevelZerofilesSupported 65
#define MGK_CoderErrorPNGCompressionNotSupported 66
#define MGK_CoderErrorPNGLibraryTooOld 67
#define MGK_CoderErrorRLECompressionNotSupported 68
#define MGK_CoderErrorSubsamplingRequiresEvenWidth 69
#define MGK_CoderErrorUnableToCopyProfile 70
#define MGK_CoderErrorUnableToCreateADC 71
#define MGK_CoderErrorUnableToCreateBitmap 72
#define MGK_CoderErrorUnableToDecompressImage 73
#define MGK_CoderErrorUnableToInitializeFPXLibrary 74
#define MGK_CoderErrorUnableToOpenBlob 75
#define MGK_CoderErrorUnableToReadAspectRatio 76
#define MGK_CoderErrorUnableToReadCIELABImages 77
#define MGK_CoderErrorUnableToReadSummaryInfo 78
#define MGK_CoderErrorUnableToSetAffineMatrix 79
#define MGK_CoderErrorUnableToSetAspectRatio 80
#define MGK_CoderErrorUnableToSetColorTwist 81
#define MGK_CoderErrorUnableToSetContrast 82
#define MGK_CoderErrorUnableToSetFilteringValue 83
#define MGK_CoderErrorUnableToSetImageComments 84
#define MGK_CoderErrorUnableToSetImageTitle 85
#define MGK_CoderErrorUnableToSetJPEGLevel 86
#define MGK_CoderErrorUnableToSetRegionOfInterest 87
#define MGK_CoderErrorUnableToSetSummaryInfo 88
#define MGK_CoderErrorUnableToTranslateText 89
#define MGK_CoderErrorUnableToWriteMPEGParameters 90
#define MGK_CoderErrorUnableToWriteTemporaryFile 91
#define MGK_CoderErrorUnableToZipCompressImage 92
#define MGK_CoderErrorUnsupportedBitsPerSample 93
#define MGK_CoderErrorUnsupportedCellTypeInTheMatrix 94
#define MGK_CoderErrorUnsupportedSamplesPerPixel 95
#define MGK_CoderErrorWebPDecodingFailedUserAbort 96
#define MGK_CoderErrorWebPEncodingFailed 97
#define MGK_CoderErrorWebPEncodingFailedBadDimension 98
#define MGK_CoderErrorWebPEncodingFailedBadWrite 99
#define MGK_CoderErrorWebPEncodingFailedBitstreamOutOfMemory 100
#define MGK_CoderErrorWebPEncodingFailedFileTooBig 101
#define MGK_CoderErrorWebPEncodingFailedInvalidConfiguration 102
#define MGK_CoderErrorWebPEncodingFailedNULLParameter 103
#define MGK_CoderErrorWebPEncodingFailedOutOfMemory 104
#define MGK_CoderErrorWebPEncodingFailedPartition0Overflow 105
#define MGK_CoderErrorWebPEncodingFailedPartitionOverflow 106
#define MGK_CoderErrorWebPEncodingFailedUserAbort 107
#define MGK_CoderErrorWebPInvalidConfiguration 108
#define MGK_CoderErrorWebPInvalidParameter 109
#define MGK_CoderErrorZipCompressionNotSupported 110
#define MGK_CoderFatalErrorDefault 111
#define MGK_CoderWarningLosslessToLossyJPEGConversion 112
#define MGK_ConfigureErrorIncludeElementNestedTooDeeply 113
#define MGK_ConfigureErrorRegistryKeyLookupFailed 114
#define MGK_ConfigureErrorStringTokenLengthExceeded 115
#define MGK_ConfigureErrorUnableToAccessConfigureFile 116
#define MGK_ConfigureErrorUnableToAccessFontFile 117
#define MGK_ConfigureErrorUnableToAccessLogFile 118
#define MGK_ConfigureErrorUnableToAccessModuleFile 119
#define MGK_ConfigureFatalErrorDefault 120
#define MGK_ConfigureFatalErrorUnableToChangeToWorkingDirectory 121
#define MGK_ConfigureFatalErrorUnableToGetCurrentDirectory 122
#define MGK_ConfigureFatalErrorUnableToRestoreCurrentDirectory 123
#define MGK_ConfigureWarningDefault 124
#define MGK_CorruptImageErrorAnErrorHasOccurredReadingFromFile 125
#define MGK_CorruptImageErrorAnErrorHasOccurredWritingToFile 126
#define MGK_CorruptImageErrorColormapExceedsColorsLimit 127
#define MGK_CorruptImageErrorCompressionNotValid 128
#define MGK_CorruptImageErrorCorruptImage 129
#define MGK_CorruptImageErrorImageFileDoesNotContainAnyImageData 130
#define MGK_CorruptImageErrorImageFileHasNoScenes 131
#define MGK_CorruptImageErrorImageTypeNotSupported 132
#define MGK_CorruptImageErrorImproperImageHeader 133
#define MGK_CorruptImageErrorInsufficientImageDataInFile 134
#define MGK_CorruptImageErrorInvalidColormapIndex 135
#define MGK_CorruptImageErrorInvalidFileFormatVersion 136
#define MGK_CorruptImageErrorLengthAndFilesizeDoNotMatch 137
#define MGK_CorruptImageErrorMissingImageChannel 138
#define MGK_CorruptImageErrorNegativeOrZeroImageSize 139
#define MGK_CorruptImageErrorNonOS2HeaderSizeError 140
#define MGK_CorruptImageErrorNotEnoughTiles 141
#define MGK_CorruptImageErrorStaticPlanesValueNotEqualToOne 142
#define MGK_CorruptImageErrorSubsamplingRequiresEvenWidth 143
#define MGK_CorruptImageErrorTooMuchImageDataInFile 144
#define MGK_CorruptImageErrorUnableToReadColormapFromDumpFile 145
#define MGK_CorruptImageErrorUnableToReadColorProfile 146
#define MGK_CorruptImageErrorUnableToReadExtensionBlock 147
#define MGK_CorruptImageErrorUnableToReadGenericProfile 148
#define MGK_CorruptImageErrorUnableToReadImageData 149
#define MGK_CorruptImageErrorUnableToReadImageHeader 150
#define MGK_CorruptImageErrorUnableToReadIPTCProfile 151
#define MGK_CorruptImageErrorUnableToReadPixmapFromDumpFile 152
#define MGK_CorruptImageErrorUnableToReadSubImageData 153
#define MGK_CorruptImageErrorUnableToReadVIDImage 154
#define MGK_CorruptImageErrorUnableToReadWindowNameFromDumpFile 155
#define MGK_CorruptImageErrorUnableToRunlengthDecodeImage 156
#define MGK_CorruptImageErrorUnableToUncompressImage 157
#define MGK_CorruptImageErrorUnexpectedEndOfFile 158
#define MGK_CorruptImageErrorUnexpectedSamplingFactor 159
#define MGK_CorruptImageErrorUnknownPatternType 160
#define MGK_CorruptImageErrorUnrecognizedBitsPerPixel 161
#define MGK_CorruptImageErrorUnrecognizedImageCompression 162
#define MGK_CorruptImageErrorUnrecognizedNumberOfColors 163
#define MGK_CorruptImageErrorUnrecognizedXWDHeader 164
#define MGK_CorruptImageErrorUnsupportedBitsPerSample 165
#define MGK_CorruptImageErrorUnsupportedNumberOfPlanes 166
#define MGK_CorruptImageFatalErrorUnableToPersistKey 167
#define MGK_CorruptImageWarningCompressionNotValid 168
#define MGK_CorruptImageWarningCorruptImage 169
#define MGK_CorruptImageWarningImproperImageHeader 170
#define MGK_CorruptImageWarningInvalidColormapIndex 171
#define MGK_CorruptImageWarningLengthAndFilesizeDoNotMatch 172
#define MGK_CorruptImageWarningNegativeOrZeroImageSize 173
#define MGK_CorruptImageWarningNonOS2HeaderSizeError 174
#define MGK_CorruptImageWarningSkipToSyncByte 175
#define MGK_CorruptImageWarningStaticPlanesValueNotEqualToOne 176
#define MGK_CorruptImageWarningUnableToParseEmbeddedProfile 177
#define MGK_CorruptImageWarningUnrecognizedBitsPerPixel 178
#define MGK_CorruptImageWarningUnrecognizedImageCompression 179
#define MGK_DelegateErrorDelegateFailed 180
#define MGK_DelegateErrorFailedToAllocateArgumentList 181
#define MGK_DelegateErrorFailedToAllocateGhostscriptInterpreter 182
#define MGK_DelegateErrorFailedToComputeOutputSize 183
#define MGK_DelegateErrorFailedToFindGhostscript 184
#define MGK_DelegateErrorFailedToRenderFile 185
#define MGK_DelegateErrorFailedToScanFile 186
#define MGK_DelegateErrorNoTagFound 187
#define MGK_DelegateErrorPostscriptDelegateFailed 188
#define MGK_DelegateErrorUnableToCreateImage 189
#define MGK_DelegateErrorUnableToCreateImageComponent 190
#define MGK_DelegateErrorUnableToDecodeImageFile 191
#define MGK_DelegateErrorUnableToEncodeImageFile 192
#define MGK_DelegateErrorUnableToInitializeFPXLibrary 193
#define MGK_DelegateErrorUnableToInitializeWMFLibrary 194
#define MGK_DelegateErrorUnableToManageJP2Stream 195
#define MGK_DelegateErrorUnableToWriteSVGFormat 196
#define MGK_DelegateErrorWebPABIMismatch 197
#define MGK_DelegateFatalErrorDefault 198
#define MGK_DelegateWarningDefault 199
#define MGK_DrawErrorAlreadyPushingPatternDefinition 200
#define MGK_DrawErrorDrawingRecursionDetected 201
#define MGK_DrawErrorFloatValueConversionError 202
#define MGK_DrawErrorIntegerValueConversionError 203
#define MGK_DrawErrorInvalidPrimitiveArgument 204
#define MGK_DrawErrorNonconformingDrawingPrimitiveDefinition 205
#define MGK_DrawErrorPrimitiveArithmeticOverflow 206
#define MGK_DrawErrorTooManyCoordinates 207
#define MGK_DrawErrorUnableToPrint 208
#define MGK_DrawErrorUnbalancedGraphicContextPushPop 209
#define MGK_DrawErrorUnreasonableGradientSize 210
#define MGK_DrawErrorVectorPathTruncated 211
#define MGK_DrawFatalErrorDefault 212
#define MGK_DrawWarningNotARelativeURL 213
#define MGK_DrawWarningNotCurrentlyPushingPatternDefinition 214
#define MGK_DrawWarningURLNotFound 215
#define MGK_FileOpenErrorUnableToCreateTemporaryFile 216
#define MGK_FileOpenErrorUnableToOpenFile 217
#define MGK_FileOpenErrorUnableToWriteFile 218
#define MGK_FileOpenFatalErrorDefault 219
#define MGK_FileOpenWarningDefault 220
#define MGK_ImageErrorAngleIsDiscontinuous 221
#define MGK_ImageErrorCMYKAImageLacksAlphaChannel 222
#define MGK_ImageErrorColorspaceColorProfileMismatch 223
#define MGK_ImageErrorImageColorspaceDiffers 224
#define MGK_ImageErrorImageColorspaceMismatch 225
#define MGK_ImageErrorImageDifferenceExceedsLimit 226
#define MGK_ImageErrorImageDoesNotContainResolution 227
#define MGK_ImageErrorImageIsNotColormapped 228
#define MGK_ImageErrorImageOpacityDiffers 229
#define MGK_ImageErrorImageSequenceIsRequired 230
#define MGK_ImageErrorImageSizeDiffers 231
#define MGK_ImageErrorInvalidColormapIndex 232
#define MGK_ImageErrorLeftAndRightImageSizesDiffer 233
#define MGK_ImageErrorNoImagesWereFound 234
#define MGK_ImageErrorNoImagesWereLoaded 235
#define MGK_ImageErrorNoLocaleImageAttribute 236
#define MGK_ImageErrorTooManyClusters 237
#define MGK_ImageErrorUnableToAppendImage 238
#define MGK_ImageErrorUnableToAssignProfile 239
#define MGK_ImageErrorUnableToAverageImage 240
#define MGK_ImageErrorUnableToCoalesceImage 241
#define MGK_ImageErrorUnableToCompareImages 242
#define MGK_ImageErrorUnableToCreateImageMosaic 243
#define MGK_ImageErrorUnableToCreateStereoImage 244
#define MGK_ImageErrorUnableToDeconstructImageSequence 245
#define MGK_ImageErrorUnableToExportImagePixels 246
#define MGK_ImageErrorUnableToFlattenImage 247
#define MGK_ImageErrorUnableToGetClipMask 248
#define MGK_ImageErrorUnableToGetCompositeMask 249
#define MGK_ImageErrorUnableToHandleImageChannel 250
#define MGK_ImageErrorUnableToImportImagePixels 251
#define MGK_ImageErrorUnableToResizeImage 252
#define MGK_ImageErrorUnableToSegmentImage 253
#define MGK_ImageErrorUnableToSetClipMask 254
#define MGK_ImageErrorUnableToSetCompositeMask 255
#define MGK_ImageErrorUnableToShearImage 256
#define MGK_ImageErrorWidthOrHeightExceedsLimit 257
#define MGK_ImageFatalErrorUnableToPersistKey 258
#define MGK_ImageWarningDefault 259
#define MGK_MissingDelegateErrorDPSLibraryIsNotAvailable 260
#define MGK_MissingDelegateErrorFPXLibraryIsNotAvailable 261
#define MGK_MissingDelegateErrorFreeTypeLibraryIsNotAvailable 262
#define MGK_MissingDelegateErrorJPEGLibraryIsNotAvailable 263
#define MGK_MissingDelegateErrorLCMSLibraryIsNotAvailable 264
#define MGK_MissingDelegateErrorLZWEncodingNotEnabled 265
#define MGK_MissingDelegateErrorNoDecodeDelegateForThisImageFormat 266
#define MGK_MissingDelegateErrorNoEncodeDelegateForThisImageFormat 267
#define MGK_MissingDelegateErrorTIFFLibraryIsNotAvailable 268
#define MGK_MissingDelegateErrorXMLLibraryIsNotAvailable 269
#define MGK_MissingDelegateErrorXWindowLibraryIsNotAvailable 270
#define MGK_MissingDelegateErrorZipLibraryIsNotAvailable 271
#define MGK_MissingDelegateFatalErrorDefault 272
#define MGK_MissingDelegateWarningDefault 273
#define MGK_ModuleErrorFailedToCloseModule 274
#define MGK_ModuleErrorFailedToFindSymbol 275
#define MGK_ModuleErrorUnableToLoadModule 276
#define MGK_ModuleErrorUnableToRegisterImageFormat 277
#define MGK_ModuleErrorUnrecognizedModule 278
#define MGK_ModuleFatalErrorUnableToInitializeModuleLoader 279
#define MGK_ModuleWarningDefault 280
#define MGK_MonitorErrorDefault 281
#define MGK_MonitorFatalErrorDefault 282
#define MGK_MonitorFatalErrorUserRequestedTerminationBySignal 283
#define MGK_MonitorWarningDefault 284
#define MGK_OptionErrorBevelWidthIsNegative 285
#define MGK_OptionErrorColorSeparatedImageRequired 286
#define MGK_OptionErrorFrameIsLessThanImageSize 287
#define MGK_OptionErrorGeometryDimensionsAreZero 288
#define MGK_OptionErrorGeometryDoesNotContainImage 289
#define MGK_OptionErrorHaldClutImageDimensionsInvalid 290
#define MGK_OptionErrorImagesAreNotTheSameSize 291
#define MGK_OptionErrorImageSizeMustExceedBevelWidth 292
#define MGK_OptionErrorImageSmallerThanKernelWidth 293
#define MGK_OptionErrorImageSmallerThanRadius 294
#define MGK_OptionErrorImageWidthsOrHeightsDiffer 295
#define MGK_OptionErrorInputImagesAlreadySpecified 296
#define MGK_OptionErrorInvalidSubimageSpecification 297
#define MGK_OptionErrorKernelRadiusIsTooSmall 298
#define MGK_OptionErrorKernelWidthMustBeAnOddNumber 299
#define MGK_OptionErrorMatrixIsNotSquare 300
#define MGK_OptionErrorMatrixOrderOutOfRange 301
#define MGK_OptionErrorMissingAnImageFilename 302
#define MGK_OptionErrorMissingArgument 303
#define MGK_OptionErrorMustSpecifyAnImageName 304
#define MGK_OptionErrorMustSpecifyImageSize 305
#define MGK_OptionErrorNoBlobDefined 306
#define MGK_OptionErrorNoImagesDefined 307
#define MGK_OptionErrorNonzeroWidthAndHeightRequired 308
#define MGK_OptionErrorNoProfileNameWasGiven 309
#define MGK_OptionErrorNullBlobArgument 310
#define MGK_OptionErrorReferenceImageRequired 311
#define MGK_OptionErrorReferenceIsNotMyType 312
#define MGK_OptionErrorRegionAreaExceedsLimit 313
#define MGK_OptionErrorRequestDidNotReturnAnImage 314
#define MGK_OptionErrorSteganoImageRequired 315
#define MGK_OptionErrorStereoImageRequired 316
#define MGK_OptionErrorSubimageSpecificationReturnsNoImages 317
#define MGK_OptionErrorTileNotBoundedByImageDimensions 318
#define MGK_OptionErrorUnableToAddOrRemoveProfile 319
#define MGK_OptionErrorUnableToAverageImageSequence 320
#define MGK_OptionErrorUnableToBlurImage 321
#define MGK_OptionErrorUnableToChopImage 322
#define MGK_OptionErrorUnableToColorMatrixImage 323
#define MGK_OptionErrorUnableToConstituteImage 324
#define MGK_OptionErrorUnableToConvolveImage 325
#define MGK_OptionErrorUnableToEdgeImage 326
#define MGK_OptionErrorUnableToEqualizeImage 327
#define MGK_OptionErrorUnableToFilterImage 328
#define MGK_OptionErrorUnableToFormatImageMetadata 329
#define MGK_OptionErrorUnableToFrameImage 330
#define MGK_OptionErrorUnableToOilPaintImage 331
#define MGK_OptionErrorUnableToPaintImage 332
#define MGK_OptionErrorUnableToRaiseImage 333
#define MGK_OptionErrorUnableToSharpenImage 334
#define MGK_OptionErrorUnableToThresholdImage 335
#define MGK_OptionErrorUnableToWaveImage 336
#define MGK_OptionErrorUnrecognizedAttribute 337
#define MGK_OptionErrorUnrecognizedChannelType 338
#define MGK_OptionErrorUnrecognizedColor 339
#define MGK_OptionErrorUnrecognizedColormapType 340
#define MGK_OptionErrorUnrecognizedColorspace 341
#define MGK_OptionErrorUnrecognizedCommand 342
#define MGK_OptionErrorUnrecognizedComposeOperator 343
#define MGK_OptionErrorUnrecognizedDisposeMethod 344
#define MGK_OptionErrorUnrecognizedElement 345
#define MGK_OptionErrorUnrecognizedEndianType 346
#define MGK_OptionErrorUnrecognizedGravityType 347
#define MGK_OptionErrorUnrecognizedHighlightStyle 348
#define MGK_OptionErrorUnrecognizedImageCompression 349
#define MGK_OptionErrorUnrecognizedImageFilter 350
#define MGK_OptionErrorUnrecognizedImageFormat 351
#define MGK_OptionErrorUnrecognizedImageMode 352
#define MGK_OptionErrorUnrecognizedImageType 353
#define MGK_OptionErrorUnrecognizedIntentType 354
#define MGK_OptionErrorUnrecognizedInterlaceType 355
#define MGK_OptionErrorUnrecognizedListType 356
#define MGK_OptionErrorUnrecognizedMetric 357
#define MGK_OptionErrorUnrecognizedModeType 358
#define MGK_OptionErrorUnrecognizedNoiseType 359
#define MGK_OptionErrorUnrecognizedOperator 360
#define MGK_OptionErrorUnrecognizedOption 361
#define MGK_OptionErrorUnrecognizedPerlMagickMethod 362
#define MGK_OptionErrorUnrecognizedPixelMap 363
#define MGK_OptionErrorUnrecognizedPreviewType 364
#define MGK_OptionErrorUnrecognizedResourceType 365
#define MGK_OptionErrorUnrecognizedType 366
#define MGK_OptionErrorUnrecognizedUnitsType 367
#define MGK_OptionErrorUnrecognizedVirtualPixelMethod 368
#define MGK_OptionErrorUnsupportedSamplingFactor 369
#define MGK_OptionErrorUsageError 370
#define MGK_OptionFatalErrorInvalidColorspaceType 371
#define MGK_OptionFatalErrorInvalidEndianType 372
#define MGK_OptionFatalErrorInvalidImageType 373
#define MGK_OptionFatalErrorInvalidInterlaceType 374
#define MGK_OptionFatalErrorMissingAnImageFilename 375
#define MGK_OptionFatalErrorMissingArgument 376
#define MGK_OptionFatalErrorNoImagesWereLoaded 377
#define MGK_OptionFatalErrorOptionLengthExceedsLimit 378
#define MGK_OptionFatalErrorRequestDidNotReturnAnImage 379
#define MGK_OptionFatalErrorUnableToOpenXServer 380
#define MGK_OptionFatalErrorUnableToPersistKey 381
#define MGK_OptionFatalErrorUnrecognizedColormapType 382
#define MGK_OptionFatalErrorUnrecognizedColorspaceType 383
#define MGK_OptionFatalErrorUnrecognizedDisposeMethod 384
#define MGK_OptionFatalErrorUnrecognizedEndianType 385
#define MGK_OptionFatalErrorUnrecognizedFilterType 386
#define MGK_OptionFatalErrorUnrecognizedImageCompressionType 387
#define MGK_OptionFatalErrorUnrecognizedImageType 388
#define MGK_OptionFatalErrorUnrecognizedInterlaceType 389
#define MGK_OptionFatalErrorUnrecognizedOption 390
#define MGK_OptionFatalErrorUnrecognizedResourceType 391
#define MGK_OptionFatalErrorUnrecognizedVirtualPixelMethod 392
#define MGK_OptionWarningUnrecognizedColor 393
#define MGK_RegistryErrorImageExpected 394
#define MGK_RegistryErrorImageInfoExpected 395
#define MGK_RegistryErrorStructureSizeMismatch 396
#define MGK_RegistryErrorUnableToGetRegistryID 397
#define MGK_RegistryErrorUnableToLocateImage 398
#define MGK_RegistryErrorUnableToSetRegistry 399
#define MGK_RegistryFatalErrorDefault 400
#define MGK_RegistryWarningDefault 401
#define MGK_ResourceLimitErrorCacheResourcesExhausted 402
#define MGK_ResourceLimitErrorImagePixelHeightLimitExceeded 403
#define MGK_ResourceLimitErrorImagePixelLimitExceeded 404
#define MGK_ResourceLimitErrorImagePixelWidthLimitExceeded 405
#define MGK_ResourceLimitErrorMemoryAllocationFailed 406
#define MGK_ResourceLimitErrorNexusPixelHeightLimitExceeded 407
#define MGK_ResourceLimitErrorNexusPixelLimitExceeded 408
#define MGK_ResourceLimitErrorNexusPixelWidthLimitExceeded 409
#define MGK_ResourceLimitErrorNoPixelsDefinedInCache 410
#define MGK_ResourceLimitErrorPixelCacheAllocationFailed 411
#define MGK_ResourceLimitErrorUnableToAddColorProfile 412
#define MGK_ResourceLimitErrorUnableToAddGenericProfile 413
#define MGK_ResourceLimitErrorUnableToAddIPTCProfile 414
#define MGK_ResourceLimitErrorUnableToAddOrRemoveProfile 415
#define MGK_ResourceLimitErrorUnableToAllocateCoefficients 416
#define MGK_ResourceLimitErrorUnableToAllocateColormap 417
#define MGK_ResourceLimitErrorUnableToAllocateICCProfile 418
#define MGK_ResourceLimitErrorUnableToAllocateImage 419
#define MGK_ResourceLimitErrorUnableToAllocateString 420
#define MGK_ResourceLimitErrorUnableToAnnotateImage 421
#define MGK_ResourceLimitErrorUnableToAverageImageSequence 422
#define MGK_ResourceLimitErrorUnableToCloneDrawingWand 423
#define MGK_ResourceLimitErrorUnableToCloneImage 424
#define MGK_ResourceLimitErrorUnableToComputeImageSignature 425
#define MGK_ResourceLimitErrorUnableToConstituteImage 426
#define MGK_ResourceLimitErrorUnableToConvertFont 427
#define MGK_ResourceLimitErrorUnableToConvertStringToTokens 428
#define MGK_ResourceLimitErrorUnableToCreateColormap 429
#define MGK_ResourceLimitErrorUnableToCreateColorTransform 430
#define MGK_ResourceLimitErrorUnableToCreateCommandWidget 431
#define MGK_ResourceLimitErrorUnableToCreateImageGroup 432
#define MGK_ResourceLimitErrorUnableToCreateImageMontage 433
#define MGK_ResourceLimitErrorUnableToCreateXWindow 434
#define MGK_ResourceLimitErrorUnableToCropImage 435
#define MGK_ResourceLimitErrorUnableToDespeckleImage 436
#define MGK_ResourceLimitErrorUnableToDetermineImageClass 437
#define MGK_ResourceLimitErrorUnableToDetermineTheNumberOfImageColors 438
#define MGK_ResourceLimitErrorUnableToDitherImage 439
#define MGK_ResourceLimitErrorUnableToDrawOnImage 440
#define MGK_ResourceLimitErrorUnableToEdgeImage 441
#define MGK_ResourceLimitErrorUnableToEmbossImage 442
#define MGK_ResourceLimitErrorUnableToEnhanceImage 443
#define MGK_ResourceLimitErrorUnableToFloodfillImage 444
#define MGK_ResourceLimitErrorUnableToGammaCorrectImage 445
#define MGK_ResourceLimitErrorUnableToGetBestIconSize 446
#define MGK_ResourceLimitErrorUnableToGetFromRegistry 447
#define MGK_ResourceLimitErrorUnableToGetPackageInfo 448
#define MGK_ResourceLimitErrorUnableToLevelImage 449
#define MGK_ResourceLimitErrorUnableToMagnifyImage 450
#define MGK_ResourceLimitErrorUnableToManageColor 451
#define MGK_ResourceLimitErrorUnableToMapImage 452
#define MGK_ResourceLimitErrorUnableToMapImageSequence 453
#define MGK_ResourceLimitErrorUnableToMedianFilterImage 454
#define MGK_ResourceLimitErrorUnableToMotionBlurImage 455
#define MGK_ResourceLimitErrorUnableToNoiseFilterImage 456
#define MGK_ResourceLimitErrorUnableToNormalizeImage 457
#define MGK_ResourceLimitErrorUnableToOpenColorProfile 458
#define MGK_ResourceLimitErrorUnableToQuantizeImage 459
#define MGK_ResourceLimitErrorUnableToQuantizeImageSequence 460
#define MGK_ResourceLimitErrorUnableToReadTextChunk 461
#define MGK_ResourceLimitErrorUnableToReadXImage 462
#define MGK_ResourceLimitErrorUnableToReadXServerColormap 463
#define MGK_ResourceLimitErrorUnableToResizeImage 464
#define MGK_ResourceLimitErrorUnableToRotateImage 465
#define MGK_ResourceLimitErrorUnableToSampleImage 466
#define MGK_ResourceLimitErrorUnableToScaleImage 467
#define MGK_ResourceLimitErrorUnableToSelectImage 468
#define MGK_ResourceLimitErrorUnableToSharpenImage 469
#define MGK_ResourceLimitErrorUnableToShaveImage 470
#define MGK_ResourceLimitErrorUnableToShearImage 471
#define MGK_ResourceLimitErrorUnableToSortImageColormap 472
#define MGK_ResourceLimitErrorUnableToThresholdImage 473
#define MGK_ResourceLimitErrorUnableToTransformColorspace 474
#define MGK_ResourceLimitFatalErrorMemoryAllocationFailed 475
#define MGK_ResourceLimitFatalErrorSemaporeOperationFailed 476
#define MGK_ResourceLimitFatalErrorUnableToAllocateAscii85Info 477
#define MGK_ResourceLimitFatalErrorUnableToAllocateCacheInfo 478
#define MGK_ResourceLimitFatalErrorUnableToAllocateCacheView 479
#define MGK_ResourceLimitFatalErrorUnableToAllocateColorInfo 480
#define MGK_ResourceLimitFatalErrorUnableToAllocateDashPattern 481
#define MGK_ResourceLimitFatalErrorUnableToAllocateDelegateInfo 482
#define MGK_ResourceLimitFatalErrorUnableToAllocateDerivatives 483
#define MGK_ResourceLimitFatalErrorUnableToAllocateDrawContext 484
#define MGK_ResourceLimitFatalErrorUnableToAllocateDrawInfo 485
#define MGK_ResourceLimitFatalErrorUnableToAllocateDrawingWand 486
#define MGK_ResourceLimitFatalErrorUnableToAllocateGammaMap 487
#define MGK_ResourceLimitFatalErrorUnableToAllocateImage 488
#define MGK_ResourceLimitFatalErrorUnableToAllocateImagePixels 489
#define MGK_ResourceLimitFatalErrorUnableToAllocateLogInfo 490
#define MGK_ResourceLimitFatalErrorUnableToAllocateMagicInfo 491
#define MGK_ResourceLimitFatalErrorUnableToAllocateMagickInfo 492
#define MGK_ResourceLimitFatalErrorUnableToAllocateMagickMap 493
#define MGK_ResourceLimitFatalErrorUnableToAllocateModuleInfo 494
#define MGK_ResourceLimitFatalErrorUnableToAllocateMontageInfo 495
#define MGK_ResourceLimitFatalErrorUnableToAllocateQuantizeInfo 496
#define MGK_ResourceLimitFatalErrorUnableToAllocateRandomKernel 497
#define MGK_ResourceLimitFatalErrorUnableToAllocateRegistryInfo 498
#define MGK_ResourceLimitFatalErrorUnableToAllocateSemaphoreInfo 499
#define MGK_ResourceLimitFatalErrorUnableToAllocateString 500
#define MGK_ResourceLimitFatalErrorUnableToAllocateTypeInfo 501
#define MGK_ResourceLimitFatalErrorUnableToAllocateWand 502
#define MGK_ResourceLimitFatalErrorUnableToAnimateImageSequence 503
#define MGK_ResourceLimitFatalErrorUnableToCloneBlobInfo 504
#define MGK_ResourceLimitFatalErrorUnableToCloneCacheInfo 505
#define MGK_ResourceLimitFatalErrorUnableToCloneImage 506
#define MGK_ResourceLimitFatalErrorUnableToCloneImageInfo 507
#define MGK_ResourceLimitFatalErrorUnableToConcatenateString 508
#define MGK_ResourceLimitFatalErrorUnableToConvertText 509
#define MGK_ResourceLimitFatalErrorUnableToCreateColormap 510
#define MGK_ResourceLimitFatalErrorUnableToDestroySemaphore 511
#define MGK_ResourceLimitFatalErrorUnableToDisplayImage 512
#define MGK_ResourceLimitFatalErrorUnableToEscapeString 513
#define MGK_ResourceLimitFatalErrorUnableToInitializeSemaphore 514
#define MGK_ResourceLimitFatalErrorUnableToInterpretMSLImage 515
#define MGK_ResourceLimitFatalErrorUnableToLockSemaphore 516
#define MGK_ResourceLimitFatalErrorUnableToObtainRandomEntropy 517
#define MGK_ResourceLimitFatalErrorUnableToUnlockSemaphore 518
#define MGK_ResourceLimitWarningMemoryAllocationFailed 519
#define MGK_StreamErrorImageDoesNotContainTheStreamGeometry 520
#define MGK_StreamErrorNoStreamHandlerIsDefined 521
#define MGK_StreamErrorPixelCacheIsNotOpen 522
#define MGK_StreamErrorUnableToAcquirePixelStream 523
#define MGK_StreamErrorUnableToSetPixelStream 524
#define MGK_StreamErrorUnableToSyncPixelStream 525
#define MGK_StreamFatalErrorDefault 526
#define MGK_StreamWarningDefault 527
#define MGK_TypeErrorFontNotSpecified 528
#define MGK_TypeErrorFontSubstitutionRequired 529
#define MGK_TypeErrorUnableToGetTypeMetrics 530
#define MGK_TypeErrorUnableToInitializeFreetypeLibrary 531
#define MGK_TypeErrorUnableToReadFont 532
#define MGK_TypeErrorUnrecognizedFontEncoding 533
#define MGK_TypeFatalErrorDefault 534
#define MGK_TypeWarningDefault 535
#define MGK_WandErrorInvalidColormapIndex 536
#define MGK_WandErrorWandAPINotImplemented 537
#define MGK_WandErrorWandContainsNoImageIndexs 538
#define MGK_WandErrorWandContainsNoImages 539
#define MGK_XServerErrorColorIsNotKnownToServer 540
#define MGK_XServerErrorNoWindowWithSpecifiedIDExists 541
#define MGK_XServerErrorStandardColormapIsNotInitialized 542
#define MGK_XServerErrorUnableToConnectToRemoteDisplay 543
#define MGK_XServerErrorUnableToCreateBitmap 544
#define MGK_XServerErrorUnableToCreateColormap 545
#define MGK_XServerErrorUnableToCreatePixmap 546
#define MGK_XServerErrorUnableToCreateProperty 547
#define MGK_XServerErrorUnableToCreateStandardColormap 548
#define MGK_XServerErrorUnableToDisplayImageInfo 549
#define MGK_XServerErrorUnableToGetProperty 550
#define MGK_XServerErrorUnableToGetStandardColormap 551
#define MGK_XServerErrorUnableToGetVisual 552
#define MGK_XServerErrorUnableToGrabMouse 553
#define MGK_XServerErrorUnableToLoadFont 554
#define MGK_XServerErrorUnableToMatchVisualToStandardColormap 555
#define MGK_XServerErrorUnableToOpenXServer 556
#define MGK_XServerErrorUnableToReadXAttributes 557
#define MGK_XServerErrorUnableToReadXWindowImage 558
#define MGK_XServerErrorUnrecognizedColormapType 559
#define MGK_XServerErrorUnrecognizedGravityType 560
#define MGK_XServerErrorUnrecognizedVisualSpecifier 561
#define MGK_XServerFatalErrorUnableToAllocateXHints 562
#define MGK_XServerFatalErrorUnableToCreateCursor 563
#define MGK_XServerFatalErrorUnableToCreateGraphicContext 564
#define MGK_XServerFatalErrorUnableToCreateStandardColormap 565
#define MGK_XServerFatalErrorUnableToCreateTextProperty 566
#define MGK_XServerFatalErrorUnableToCreateXImage 567
#define MGK_XServerFatalErrorUnableToCreateXPixmap 568
#define MGK_XServerFatalErrorUnableToCreateXWindow 569
#define MGK_XServerFatalErrorUnableToDisplayImage 570
#define MGK_XServerFatalErrorUnableToDitherImage 571
#define MGK_XServerFatalErrorUnableToGetPixelInfo 572
#define MGK_XServerFatalErrorUnableToGetVisual 573
#define MGK_XServerFatalErrorUnableToLoadFont 574
#define MGK_XServerFatalErrorUnableToMakeXWindow 575
#define MGK_XServerFatalErrorUnableToOpenXServer 576
#define MGK_XServerFatalErrorUnableToViewFonts 577
#define MGK_XServerWarningUnableToGetVisual 578
#define MGK_XServerWarningUsingDefaultVisual 579

#endif

#if defined(_INCLUDE_CATEGORYMAP_TABLE_)
typedef struct _CategoryInfo{
  const char name[17];
  unsigned int offset;
} CategoryInfo;

static const CategoryInfo category_map[] =
  {
    { "Blob", 0 },
    { "Cache", 3 },
    { "Coder", 6 },
    { "Configure", 9 },
    { "Corrupt/Image", 12 },
    { "Delegate", 15 },
    { "Draw", 18 },
    { "File/Open", 21 },
    { "Image", 24 },
    { "Missing/Delegate", 27 },
    { "Module", 30 },
    { "Monitor", 33 },
    { "Option", 36 },
    { "Registry", 39 },
    { "Resource/Limit", 42 },
    { "Stream", 45 },
    { "Type", 48 },
    { "Wand", 51 },
    { "XServer", 52 },
    { "", 54 }
  };
#endif

#if defined(_INCLUDE_SEVERITYMAP_TABLE_)
typedef struct _SeverityInfo{
  const char name[28];
  unsigned int offset;
  ExceptionType severityid;
} SeverityInfo;

static const SeverityInfo severity_map[] =
  {
    { "Blob/Error", 0, BlobError },
    { "Blob/FatalError", 9, BlobFatalError },
    { "Blob/Warning", 10, BlobWarning },
    { "Cache/Error", 11, CacheError },
    { "Cache/FatalError", 24, CacheFatalError },
    { "Cache/Warning", 26, CacheWarning },
    { "Coder/Error", 27, CoderError },
    { "Coder/FatalError", 110, CoderFatalError },
    { "Coder/Warning", 111, CoderWarning },
    { "Configure/Error", 112, ConfigureError },
    { "Configure/FatalError", 119, ConfigureFatalError },
    { "Configure/Warning", 123, ConfigureWarning },
    { "Corrupt/Image/Error", 124, CorruptImageError },
    { "Corrupt/Image/FatalError", 166, CorruptImageFatalError },
    { "Corrupt/Image/Warning", 167, CorruptImageWarning },
    { "Delegate/Error", 179, DelegateError },
    { "Delegate/FatalError", 197, DelegateFatalError },
    { "Delegate/Warning", 198, DelegateWarning },
    { "Draw/Error", 199, DrawError },
    { "Draw/FatalError", 211, DrawFatalError },
    { "Draw/Warning", 212, DrawWarning },
    { "File/Open/Error", 215, FileOpenError },
    { "File/Open/FatalError", 218, FileOpenFatalError },
    { "File/Open/Warning", 219, FileOpenWarning },
    { "Image/Error", 220, ImageError },
    { "Image/FatalError", 257, ImageFatalError },
    { "Image/Warning", 258, ImageWarning },
    { "Missing/Delegate/Error", 259, MissingDelegateError },
    { "Missing/Delegate/FatalError", 271, MissingDelegateFatalError },
    { "Missing/Delegate/Warning", 272, MissingDelegateWarning },
    { "Module/Error", 273, ModuleError },
    { "Module/FatalError", 278, ModuleFatalError },
    { "Module/Warning", 279, ModuleWarning },
    { "Monitor/Error", 280, MonitorError },
    { "Monitor/FatalError", 281, MonitorFatalError },
    { "Monitor/Warning", 283, MonitorWarning },
    { "Option/Error", 284, OptionError },
    { "Option/FatalError", 370, OptionFatalError },
    { "Option/Warning", 392, OptionWarning },
    { "Registry/Error", 393, RegistryError },
    { "Registry/FatalError", 399, RegistryFatalError },
    { "Registry/Warning", 400, RegistryWarning },
    { "Resource/Limit/Error", 401, ResourceLimitError },
    { "Resource/Limit/FatalError", 474, ResourceLimitFatalError },
    { "Resource/Limit/Warning", 518, ResourceLimitWarning },
    { "Stream/Error", 519, StreamError },
    { "Stream/FatalError", 525, StreamFatalError },
    { "Stream/Warning", 526, StreamWarning },
    { "Type/Error", 527, TypeError },
    { "Type/FatalError", 533, TypeFatalError },
    { "Type/Warning", 534, TypeWarning },
    { "Wand/Error", 535, WandError },
    { "XServer/Error", 539, XServerError },
    { "XServer/FatalError", 561, XServerFatalError },
    { "XServer/Warning", 577, XServerWarning },
    { "", 579, UndefinedException }
  };
#endif

#if defined(_INCLUDE_TAGMAP_TABLE_)
typedef struct _MessageInfo
{
  const char name[40];
  unsigned int messageid;
} MessageInfo;

static const MessageInfo message_map[] =
  {
    { "UnableToCreateBlob", MGK_BlobErrorUnableToCreateBlob },
    { "UnableToDeduceImageFormat", MGK_BlobErrorUnableToDeduceImageFormat },
    { "UnableToObtainOffset", MGK_BlobErrorUnableToObtainOffset },
    { "UnableToOpenFile", MGK_BlobErrorUnableToOpenFile },
    { "UnableToReadFile", MGK_BlobErrorUnableToReadFile },
    { "UnableToReadToOffset", MGK_BlobErrorUnableToReadToOffset },
    { "UnableToSeekToOffset", MGK_BlobErrorUnableToSeekToOffset },
    { "UnableToWriteBlob", MGK_BlobErrorUnableToWriteBlob },
    { "UnrecognizedImageFormat", MGK_BlobErrorUnrecognizedImageFormat },
    { "Default", MGK_BlobFatalErrorDefault },
    { "Default", MGK_BlobWarningDefault },
    { "EmptyCacheNexus", MGK_CacheErrorEmptyCacheNexus },
    { "InconsistentPersistentCacheDepth", MGK_CacheErrorInconsistentPersistentCacheDepth },
    { "PixelCacheDimensionsMisMatch", MGK_CacheErrorPixelCacheDimensionsMisMatch },
    { "PixelCacheIsNotOpen", MGK_CacheErrorPixelCacheIsNotOpen },
    { "UnableToAllocateCacheView", MGK_CacheErrorUnableToAllocateCacheView },
    { "UnableToCloneCache", MGK_CacheErrorUnableToCloneCache },
    { "UnableToExtendCache", MGK_CacheErrorUnableToExtendCache },
    { "UnableToGetCacheNexus", MGK_CacheErrorUnableToGetCacheNexus },
    { "UnableToGetPixelsFromCache", MGK_CacheErrorUnableToGetPixelsFromCache },
    { "UnableToOpenCache", MGK_CacheErrorUnableToOpenCache },
    { "UnableToPeristPixelCache", MGK_CacheErrorUnableToPeristPixelCache },
    { "UnableToReadPixelCache", MGK_CacheErrorUnableToReadPixelCache },
    { "UnableToSyncCache", MGK_CacheErrorUnableToSyncCache },
    { "DiskAllocationFailed", MGK_CacheFatalErrorDiskAllocationFailed },
    { "UnableToExtendPixelCache", MGK_CacheFatalErrorUnableToExtendPixelCache },
    { "Default", MGK_CacheWarningDefault },
    { "ArithmeticOverflow", MGK_CoderErrorArithmeticOverflow },
    { "ColormapTooLarge", MGK_CoderErrorColormapTooLarge },
    { "ColormapTypeNotSupported", MGK_CoderErrorColormapTypeNotSupported },
    { "ColorspaceModelIsNotSupported", MGK_CoderErrorColorspaceModelIsNotSupported },
    { "ColorTypeNotSupported", MGK_CoderErrorColorTypeNotSupported },
    { "CompressionNotValid", MGK_CoderErrorCompressionNotValid },
    { "DataEncodingSchemeIsNotSupported", MGK_CoderErrorDataEncodingSchemeIsNotSupported },
    { "DataStorageTypeIsNotSupported", MGK_CoderErrorDataStorageTypeIsNotSupported },
    { "DecodedImageNotReturned", MGK_CoderErrorDecodedImageNotReturned },
    { "DeltaPNGNotSupported", MGK_CoderErrorDeltaPNGNotSupported },
    { "DivisionByZero", MGK_CoderErrorDivisionByZero },
    { "EncryptedWPGImageFileNotSupported", MGK_CoderErrorEncryptedWPGImageFileNotSupported },
    { "FractalCompressionNotSupported", MGK_CoderErrorFractalCompressionNotSupported },
    { "ImageColumnOrRowSizeIsNotSupported", MGK_CoderErrorImageColumnOrRowSizeIsNotSupported },
    { "ImageDoesNotHaveAMatteChannel", MGK_CoderErrorImageDoesNotHaveAMatteChannel },
    { "ImageIsNotTiled", MGK_CoderErrorImageIsNotTiled },
    { "ImageTypeNotSupported", MGK_CoderErrorImageTypeNotSupported },
    { "IncompatibleSizeOfDouble", MGK_CoderErrorIncompatibleSizeOfDouble },
    { "IrregularChannelGeometryNotSupported", MGK_CoderErrorIrregularChannelGeometryNotSupported },
    { "JNGCompressionNotSupported", MGK_CoderErrorJNGCompressionNotSupported },
    { "JPEGCompressionNotSupported", MGK_CoderErrorJPEGCompressionNotSupported },
    { "JPEGEmbeddingFailed", MGK_CoderErrorJPEGEmbeddingFailed },
    { "LocationTypeIsNotSupported", MGK_CoderErrorLocationTypeIsNotSupported },
    { "MapStorageTypeIsNotSupported", MGK_CoderErrorMapStorageTypeIsNotSupported },
    { "MSBByteOrderNotSupported", MGK_CoderErrorMSBByteOrderNotSupported },
    { "MultidimensionalMatricesAreNotSupported", MGK_CoderErrorMultidimensionalMatricesAreNotSupported },
    { "MultipleRecordListNotSupported", MGK_CoderErrorMultipleRecordListNotSupported },
    { "No8BIMDataIsAvailable", MGK_CoderErrorNo8BIMDataIsAvailable },
    { "NoAPP1DataIsAvailable", MGK_CoderErrorNoAPP1DataIsAvailable },
    { "NoBitmapOnClipboard", MGK_CoderErrorNoBitmapOnClipboard },
    { "NoColorProfileAvailable", MGK_CoderErrorNoColorProfileAvailable },
    { "NoDataReturned", MGK_CoderErrorNoDataReturned },
    { "NoImageVectorGraphics", MGK_CoderErrorNoImageVectorGraphics },
    { "NoIPTCInfoWasFound", MGK_CoderErrorNoIPTCInfoWasFound },
    { "NoIPTCProfileAvailable", MGK_CoderErrorNoIPTCProfileAvailable },
    { "NumberOfImagesIsNotSupported", MGK_CoderErrorNumberOfImagesIsNotSupported },
    { "OnlyContinuousTonePictureSupported", MGK_CoderErrorOnlyContinuousTonePictureSupported },
    { "OnlyLevelZerofilesSupported", MGK_CoderErrorOnlyLevelZerofilesSupported },
    { "PNGCompressionNotSupported", MGK_CoderErrorPNGCompressionNotSupported },
    { "PNGLibraryTooOld", MGK_CoderErrorPNGLibraryTooOld },
    { "RLECompressionNotSupported", MGK_CoderErrorRLECompressionNotSupported },
    { "SubsamplingRequiresEvenWidth", MGK_CoderErrorSubsamplingRequiresEvenWidth },
    { "UnableToCopyProfile", MGK_CoderErrorUnableToCopyProfile },
    { "UnableToCreateADC", MGK_CoderErrorUnableToCreateADC },
    { "UnableToCreateBitmap", MGK_CoderErrorUnableToCreateBitmap },
    { "UnableToDecompressImage", MGK_CoderErrorUnableToDecompressImage },
    { "UnableToInitializeFPXLibrary", MGK_CoderErrorUnableToInitializeFPXLibrary },
    { "UnableToOpenBlob", MGK_CoderErrorUnableToOpenBlob },
    { "UnableToReadAspectRatio", MGK_CoderErrorUnableToReadAspectRatio },
    { "UnableToReadCIELABImages", MGK_CoderErrorUnableToReadCIELABImages },
    { "UnableToReadSummaryInfo", MGK_CoderErrorUnableToReadSummaryInfo },
    { "UnableToSetAffineMatrix", MGK_CoderErrorUnableToSetAffineMatrix },
    { "UnableToSetAspectRatio", MGK_CoderErrorUnableToSetAspectRatio },
    { "UnableToSetColorTwist", MGK_CoderErrorUnableToSetColorTwist },
    { "UnableToSetContrast", MGK_CoderErrorUnableToSetContrast },
    { "UnableToSetFilteringValue", MGK_CoderErrorUnableToSetFilteringValue },
    { "UnableToSetImageComments", MGK_CoderErrorUnableToSetImageComments },
    { "UnableToSetImageTitle", MGK_CoderErrorUnableToSetImageTitle },
    { "UnableToSetJPEGLevel", MGK_CoderErrorUnableToSetJPEGLevel },
    { "UnableToSetRegionOfInterest", MGK_CoderErrorUnableToSetRegionOfInterest },
    { "UnableToSetSummaryInfo", MGK_CoderErrorUnableToSetSummaryInfo },
    { "UnableToTranslateText", MGK_CoderErrorUnableToTranslateText },
    { "UnableToWriteMPEGParameters", MGK_CoderErrorUnableToWriteMPEGParameters },
    { "UnableToWriteTemporaryFile", MGK_CoderErrorUnableToWriteTemporaryFile },
    { "UnableToZipCompressImage", MGK_CoderErrorUnableToZipCompressImage },
    { "UnsupportedBitsPerSample", MGK_CoderErrorUnsupportedBitsPerSample },
    { "UnsupportedCellTypeInTheMatrix", MGK_CoderErrorUnsupportedCellTypeInTheMatrix },
    { "UnsupportedSamplesPerPixel", MGK_CoderErrorUnsupportedSamplesPerPixel },
    { "WebPDecodingFailedUserAbort", MGK_CoderErrorWebPDecodingFailedUserAbort },
    { "WebPEncodingFailed", MGK_CoderErrorWebPEncodingFailed },
    { "WebPEncodingFailedBadDimension", MGK_CoderErrorWebPEncodingFailedBadDimension },
    { "WebPEncodingFailedBadWrite", MGK_CoderErrorWebPEncodingFailedBadWrite },
    { "WebPEncodingFailedBitstreamOutOfMemory", MGK_CoderErrorWebPEncodingFailedBitstreamOutOfMemory },
    { "WebPEncodingFailedFileTooBig", MGK_CoderErrorWebPEncodingFailedFileTooBig },
    { "WebPEncodingFailedInvalidConfiguration", MGK_CoderErrorWebPEncodingFailedInvalidConfiguration },
    { "WebPEncodingFailedNULLParameter", MGK_CoderErrorWebPEncodingFailedNULLParameter },
    { "WebPEncodingFailedOutOfMemory", MGK_CoderErrorWebPEncodingFailedOutOfMemory },
    { "WebPEncodingFailedPartition0Overflow", MGK_CoderErrorWebPEncodingFailedPartition0Overflow },
    { "WebPEncodingFailedPartitionOverflow", MGK_CoderErrorWebPEncodingFailedPartitionOverflow },
    { "WebPEncodingFailedUserAbort", MGK_CoderErrorWebPEncodingFailedUserAbort },
    { "WebPInvalidConfiguration", MGK_CoderErrorWebPInvalidConfiguration },
    { "WebPInvalidParameter", MGK_CoderErrorWebPInvalidParameter },
    { "ZipCompressionNotSupported", MGK_CoderErrorZipCompressionNotSupported },
    { "Default", MGK_CoderFatalErrorDefault },
    { "LosslessToLossyJPEGConversion", MGK_CoderWarningLosslessToLossyJPEGConversion },
    { "IncludeElementNestedTooDeeply", MGK_ConfigureErrorIncludeElementNestedTooDeeply },
    { "RegistryKeyLookupFailed", MGK_ConfigureErrorRegistryKeyLookupFailed },
    { "StringTokenLengthExceeded", MGK_ConfigureErrorStringTokenLengthExceeded },
    { "UnableToAccessConfigureFile", MGK_ConfigureErrorUnableToAccessConfigureFile },
    { "UnableToAccessFontFile", MGK_ConfigureErrorUnableToAccessFontFile },
    { "UnableToAccessLogFile", MGK_ConfigureErrorUnableToAccessLogFile },
    { "UnableToAccessModuleFile", MGK_ConfigureErrorUnableToAccessModuleFile },
    { "Default", MGK_ConfigureFatalErrorDefault },
    { "UnableToChangeToWorkingDirectory", MGK_ConfigureFatalErrorUnableToChangeToWorkingDirectory },
    { "UnableToGetCurrentDirectory", MGK_ConfigureFatalErrorUnableToGetCurrentDirectory },
    { "UnableToRestoreCurrentDirectory", MGK_ConfigureFatalErrorUnableToRestoreCurrentDirectory },
    { "Default", MGK_ConfigureWarningDefault },
    { "AnErrorHasOccurredReadingFromFile", MGK_CorruptImageErrorAnErrorHasOccurredReadingFromFile },
    { "AnErrorHasOccurredWritingToFile", MGK_CorruptImageErrorAnErrorHasOccurredWritingToFile },
    { "ColormapExceedsColorsLimit", MGK_CorruptImageErrorColormapExceedsColorsLimit },
    { "CompressionNotValid", MGK_CorruptImageErrorCompressionNotValid },
    { "CorruptImage", MGK_CorruptImageErrorCorruptImage },
    { "ImageFileDoesNotContainAnyImageData", MGK_CorruptImageErrorImageFileDoesNotContainAnyImageData },
    { "ImageFileHasNoScenes", MGK_CorruptImageErrorImageFileHasNoScenes },
    { "ImageTypeNotSupported", MGK_CorruptImageErrorImageTypeNotSupported },
    { "ImproperImageHeader", MGK_CorruptImageErrorImproperImageHeader },
    { "InsufficientImageDataInFile", MGK_CorruptImageErrorInsufficientImageDataInFile },
    { "InvalidColormapIndex", MGK_CorruptImageErrorInvalidColormapIndex },
    { "InvalidFileFormatVersion", MGK_CorruptImageErrorInvalidFileFormatVersion },
    { "LengthAndFilesizeDoNotMatch", MGK_CorruptImageErrorLengthAndFilesizeDoNotMatch },
    { "MissingImageChannel", MGK_CorruptImageErrorMissingImageChannel },
    { "NegativeOrZeroImageSize", MGK_CorruptImageErrorNegativeOrZeroImageSize },
    { "NonOS2HeaderSizeError", MGK_CorruptImageErrorNonOS2HeaderSizeError },
    { "NotEnoughTiles", MGK_CorruptImageErrorNotEnoughTiles },
    { "StaticPlanesValueNotEqualToOne", MGK_CorruptImageErrorStaticPlanesValueNotEqualToOne },
    { "SubsamplingRequiresEvenWidth", MGK_CorruptImageErrorSubsamplingRequiresEvenWidth },
    { "TooMuchImageDataInFile", MGK_CorruptImageErrorTooMuchImageDataInFile },
    { "UnableToReadColormapFromDumpFile", MGK_CorruptImageErrorUnableToReadColormapFromDumpFile },
    { "UnableToReadColorProfile", MGK_CorruptImageErrorUnableToReadColorProfile },
    { "UnableToReadExtensionBlock", MGK_CorruptImageErrorUnableToReadExtensionBlock },
    { "UnableToReadGenericProfile", MGK_CorruptImageErrorUnableToReadGenericProfile },
    { "UnableToReadImageData", MGK_CorruptImageErrorUnableToReadImageData },
    { "UnableToReadImageHeader", MGK_CorruptImageErrorUnableToReadImageHeader },
    { "UnableToReadIPTCProfile", MGK_CorruptImageErrorUnableToReadIPTCProfile },
    { "UnableToReadPixmapFromDumpFile", MGK_CorruptImageErrorUnableToReadPixmapFromDumpFile },
    { "UnableToReadSubImageData", MGK_CorruptImageErrorUnableToReadSubImageData },
    { "UnableToReadVIDImage", MGK_CorruptImageErrorUnableToReadVIDImage },
    { "UnableToReadWindowNameFromDumpFile", MGK_CorruptImageErrorUnableToReadWindowNameFromDumpFile },
    { "UnableToRunlengthDecodeImage", MGK_CorruptImageErrorUnableToRunlengthDecodeImage },
    { "UnableToUncompressImage", MGK_CorruptImageErrorUnableToUncompressImage },
    { "UnexpectedEndOfFile", MGK_CorruptImageErrorUnexpectedEndOfFile },
    { "UnexpectedSamplingFactor", MGK_CorruptImageErrorUnexpectedSamplingFactor },
    { "UnknownPatternType", MGK_CorruptImageErrorUnknownPatternType },
    { "UnrecognizedBitsPerPixel", MGK_CorruptImageErrorUnrecognizedBitsPerPixel },
    { "UnrecognizedImageCompression", MGK_CorruptImageErrorUnrecognizedImageCompression },
    { "UnrecognizedNumberOfColors", MGK_CorruptImageErrorUnrecognizedNumberOfColors },
    { "UnrecognizedXWDHeader", MGK_CorruptImageErrorUnrecognizedXWDHeader },
    { "UnsupportedBitsPerSample", MGK_CorruptImageErrorUnsupportedBitsPerSample },
    { "UnsupportedNumberOfPlanes", MGK_CorruptImageErrorUnsupportedNumberOfPlanes },
    { "UnableToPersistKey", MGK_CorruptImageFatalErrorUnableToPersistKey },
    { "CompressionNotValid", MGK_CorruptImageWarningCompressionNotValid },
    { "CorruptImage", MGK_CorruptImageWarningCorruptImage },
    { "ImproperImageHeader", MGK_CorruptImageWarningImproperImageHeader },
    { "InvalidColormapIndex", MGK_CorruptImageWarningInvalidColormapIndex },
    { "LengthAndFilesizeDoNotMatch", MGK_CorruptImageWarningLengthAndFilesizeDoNotMatch },
    { "NegativeOrZeroImageSize", MGK_CorruptImageWarningNegativeOrZeroImageSize },
    { "NonOS2HeaderSizeError", MGK_CorruptImageWarningNonOS2HeaderSizeError },
    { "SkipToSyncByte", MGK_CorruptImageWarningSkipToSyncByte },
    { "StaticPlanesValueNotEqualToOne", MGK_CorruptImageWarningStaticPlanesValueNotEqualToOne },
    { "UnableToParseEmbeddedProfile", MGK_CorruptImageWarningUnableToParseEmbeddedProfile },
    { "UnrecognizedBitsPerPixel", MGK_CorruptImageWarningUnrecognizedBitsPerPixel },
    { "UnrecognizedImageCompression", MGK_CorruptImageWarningUnrecognizedImageCompression },
    { "DelegateFailed", MGK_DelegateErrorDelegateFailed },
    { "FailedToAllocateArgumentList", MGK_DelegateErrorFailedToAllocateArgumentList },
    { "FailedToAllocateGhostscriptInterpreter", MGK_DelegateErrorFailedToAllocateGhostscriptInterpreter },
    { "FailedToComputeOutputSize", MGK_DelegateErrorFailedToComputeOutputSize },
    { "FailedToFindGhostscript", MGK_DelegateErrorFailedToFindGhostscript },
    { "FailedToRenderFile", MGK_DelegateErrorFailedToRenderFile },
    { "FailedToScanFile", MGK_DelegateErrorFailedToScanFile },
    { "NoTagFound", MGK_DelegateErrorNoTagFound },
    { "PostscriptDelegateFailed", MGK_DelegateErrorPostscriptDelegateFailed },
    { "UnableToCreateImage", MGK_DelegateErrorUnableToCreateImage },
    { "UnableToCreateImageComponent", MGK_DelegateErrorUnableToCreateImageComponent },
    { "UnableToDecodeImageFile", MGK_DelegateErrorUnableToDecodeImageFile },
    { "UnableToEncodeImageFile", MGK_DelegateErrorUnableToEncodeImageFile },
    { "UnableToInitializeFPXLibrary", MGK_DelegateErrorUnableToInitializeFPXLibrary },
    { "UnableToInitializeWMFLibrary", MGK_DelegateErrorUnableToInitializeWMFLibrary },
    { "UnableToManageJP2Stream", MGK_DelegateErrorUnableToManageJP2Stream },
    { "UnableToWriteSVGFormat", MGK_DelegateErrorUnableToWriteSVGFormat },
    { "WebPABIMismatch", MGK_DelegateErrorWebPABIMismatch },
    { "Default", MGK_DelegateFatalErrorDefault },
    { "Default", MGK_DelegateWarningDefault },
    { "AlreadyPushingPatternDefinition", MGK_DrawErrorAlreadyPushingPatternDefinition },
    { "DrawingRecursionDetected", MGK_DrawErrorDrawingRecursionDetected },
    { "FloatValueConversionError", MGK_DrawErrorFloatValueConversionError },
    { "IntegerValueConversionError", MGK_DrawErrorIntegerValueConversionError },
    { "InvalidPrimitiveArgument", MGK_DrawErrorInvalidPrimitiveArgument },
    { "NonconformingDrawingPrimitiveDefinition", MGK_DrawErrorNonconformingDrawingPrimitiveDefinition },
    { "PrimitiveArithmeticOverflow", MGK_DrawErrorPrimitiveArithmeticOverflow },
    { "TooManyCoordinates", MGK_DrawErrorTooManyCoordinates },
    { "UnableToPrint", MGK_DrawErrorUnableToPrint },
    { "UnbalancedGraphicContextPushPop", MGK_DrawErrorUnbalancedGraphicContextPushPop },
    { "UnreasonableGradientSize", MGK_DrawErrorUnreasonableGradientSize },
    { "VectorPathTruncated", MGK_DrawErrorVectorPathTruncated },
    { "Default", MGK_DrawFatalErrorDefault },
    { "NotARelativeURL", MGK_DrawWarningNotARelativeURL },
    { "NotCurrentlyPushingPatternDefinition", MGK_DrawWarningNotCurrentlyPushingPatternDefinition },
    { "URLNotFound", MGK_DrawWarningURLNotFound },
    { "UnableToCreateTemporaryFile", MGK_FileOpenErrorUnableToCreateTemporaryFile },
    { "UnableToOpenFile", MGK_FileOpenErrorUnableToOpenFile },
    { "UnableToWriteFile", MGK_FileOpenErrorUnableToWriteFile },
    { "Default", MGK_FileOpenFatalErrorDefault },
    { "Default", MGK_FileOpenWarningDefault },
    { "AngleIsDiscontinuous", MGK_ImageErrorAngleIsDiscontinuous },
    { "CMYKAImageLacksAlphaChannel", MGK_ImageErrorCMYKAImageLacksAlphaChannel },
    { "ColorspaceColorProfileMismatch", MGK_ImageErrorColorspaceColorProfileMismatch },
    { "ImageColorspaceDiffers", MGK_ImageErrorImageColorspaceDiffers },
    { "ImageColorspaceMismatch", MGK_ImageErrorImageColorspaceMismatch },
    { "ImageDifferenceExceedsLimit", MGK_ImageErrorImageDifferenceExceedsLimit },
    { "ImageDoesNotContainResolution", MGK_ImageErrorImageDoesNotContainResolution },
    { "ImageIsNotColormapped", MGK_ImageErrorImageIsNotColormapped },
    { "ImageOpacityDiffers", MGK_ImageErrorImageOpacityDiffers },
    { "ImageSequenceIsRequired", MGK_ImageErrorImageSequenceIsRequired },
    { "ImageSizeDiffers", MGK_ImageErrorImageSizeDiffers },
    { "InvalidColormapIndex", MGK_ImageErrorInvalidColormapIndex },
    { "LeftAndRightImageSizesDiffer", MGK_ImageErrorLeftAndRightImageSizesDiffer },
    { "NoImagesWereFound", MGK_ImageErrorNoImagesWereFound },
    { "NoImagesWereLoaded", MGK_ImageErrorNoImagesWereLoaded },
    { "NoLocaleImageAttribute", MGK_ImageErrorNoLocaleImageAttribute },
    { "TooManyClusters", MGK_ImageErrorTooManyClusters },
    { "UnableToAppendImage", MGK_ImageErrorUnableToAppendImage },
    { "UnableToAssignProfile", MGK_ImageErrorUnableToAssignProfile },
    { "UnableToAverageImage", MGK_ImageErrorUnableToAverageImage },
    { "UnableToCoalesceImage", MGK_ImageErrorUnableToCoalesceImage },
    { "UnableToCompareImages", MGK_ImageErrorUnableToCompareImages },
    { "UnableToCreateImageMosaic", MGK_ImageErrorUnableToCreateImageMosaic },
    { "UnableToCreateStereoImage", MGK_ImageErrorUnableToCreateStereoImage },
    { "UnableToDeconstructImageSequence", MGK_ImageErrorUnableToDeconstructImageSequence },
    { "UnableToExportImagePixels", MGK_ImageErrorUnableToExportImagePixels },
    { "UnableToFlattenImage", MGK_ImageErrorUnableToFlattenImage },
    { "UnableToGetClipMask", MGK_ImageErrorUnableToGetClipMask },
    { "UnableToGetCompositeMask", MGK_ImageErrorUnableToGetCompositeMask },
    { "UnableToHandleImageChannel", MGK_ImageErrorUnableToHandleImageChannel },
    { "UnableToImportImagePixels", MGK_ImageErrorUnableToImportImagePixels },
    { "UnableToResizeImage", MGK_ImageErrorUnableToResizeImage },
    { "UnableToSegmentImage", MGK_ImageErrorUnableToSegmentImage },
    { "UnableToSetClipMask", MGK_ImageErrorUnableToSetClipMask },
    { "UnableToSetCompositeMask", MGK_ImageErrorUnableToSetCompositeMask },
    { "UnableToShearImage", MGK_ImageErrorUnableToShearImage },
    { "WidthOrHeightExceedsLimit", MGK_ImageErrorWidthOrHeightExceedsLimit },
    { "UnableToPersistKey", MGK_ImageFatalErrorUnableToPersistKey },
    { "Default", MGK_ImageWarningDefault },
    { "DPSLibraryIsNotAvailable", MGK_MissingDelegateErrorDPSLibraryIsNotAvailable },
    { "FPXLibraryIsNotAvailable", MGK_MissingDelegateErrorFPXLibraryIsNotAvailable },
    { "FreeTypeLibraryIsNotAvailable", MGK_MissingDelegateErrorFreeTypeLibraryIsNotAvailable },
    { "JPEGLibraryIsNotAvailable", MGK_MissingDelegateErrorJPEGLibraryIsNotAvailable },
    { "LCMSLibraryIsNotAvailable", MGK_MissingDelegateErrorLCMSLibraryIsNotAvailable },
    { "LZWEncodingNotEnabled", MGK_MissingDelegateErrorLZWEncodingNotEnabled },
    { "NoDecodeDelegateForThisImageFormat", MGK_MissingDelegateErrorNoDecodeDelegateForThisImageFormat },
    { "NoEncodeDelegateForThisImageFormat", MGK_MissingDelegateErrorNoEncodeDelegateForThisImageFormat },
    { "TIFFLibraryIsNotAvailable", MGK_MissingDelegateErrorTIFFLibraryIsNotAvailable },
    { "XMLLibraryIsNotAvailable", MGK_MissingDelegateErrorXMLLibraryIsNotAvailable },
    { "XWindowLibraryIsNotAvailable", MGK_MissingDelegateErrorXWindowLibraryIsNotAvailable },
    { "ZipLibraryIsNotAvailable", MGK_MissingDelegateErrorZipLibraryIsNotAvailable },
    { "Default", MGK_MissingDelegateFatalErrorDefault },
    { "Default", MGK_MissingDelegateWarningDefault },
    { "FailedToCloseModule", MGK_ModuleErrorFailedToCloseModule },
    { "FailedToFindSymbol", MGK_ModuleErrorFailedToFindSymbol },
    { "UnableToLoadModule", MGK_ModuleErrorUnableToLoadModule },
    { "UnableToRegisterImageFormat", MGK_ModuleErrorUnableToRegisterImageFormat },
    { "UnrecognizedModule", MGK_ModuleErrorUnrecognizedModule },
    { "UnableToInitializeModuleLoader", MGK_ModuleFatalErrorUnableToInitializeModuleLoader },
    { "Default", MGK_ModuleWarningDefault },
    { "Default", MGK_MonitorErrorDefault },
    { "Default", MGK_MonitorFatalErrorDefault },
    { "UserRequestedTerminationBySignal", MGK_MonitorFatalErrorUserRequestedTerminationBySignal },
    { "Default", MGK_MonitorWarningDefault },
    { "BevelWidthIsNegative", MGK_OptionErrorBevelWidthIsNegative },
    { "ColorSeparatedImageRequired", MGK_OptionErrorColorSeparatedImageRequired },
    { "FrameIsLessThanImageSize", MGK_OptionErrorFrameIsLessThanImageSize },
    { "GeometryDimensionsAreZero", MGK_OptionErrorGeometryDimensionsAreZero },
    { "GeometryDoesNotContainImage", MGK_OptionErrorGeometryDoesNotContainImage },
    { "HaldClutImageDimensionsInvalid", MGK_OptionErrorHaldClutImageDimensionsInvalid },
    { "ImagesAreNotTheSameSize", MGK_OptionErrorImagesAreNotTheSameSize },
    { "ImageSizeMustExceedBevelWidth", MGK_OptionErrorImageSizeMustExceedBevelWidth },
    { "ImageSmallerThanKernelWidth", MGK_OptionErrorImageSmallerThanKernelWidth },
    { "ImageSmallerThanRadius", MGK_OptionErrorImageSmallerThanRadius },
    { "ImageWidthsOrHeightsDiffer", MGK_OptionErrorImageWidthsOrHeightsDiffer },
    { "InputImagesAlreadySpecified", MGK_OptionErrorInputImagesAlreadySpecified },
    { "InvalidSubimageSpecification", MGK_OptionErrorInvalidSubimageSpecification },
    { "KernelRadiusIsTooSmall", MGK_OptionErrorKernelRadiusIsTooSmall },
    { "KernelWidthMustBeAnOddNumber", MGK_OptionErrorKernelWidthMustBeAnOddNumber },
    { "MatrixIsNotSquare", MGK_OptionErrorMatrixIsNotSquare },
    { "MatrixOrderOutOfRange", MGK_OptionErrorMatrixOrderOutOfRange },
    { "MissingAnImageFilename", MGK_OptionErrorMissingAnImageFilename },
    { "MissingArgument", MGK_OptionErrorMissingArgument },
    { "MustSpecifyAnImageName", MGK_OptionErrorMustSpecifyAnImageName },
    { "MustSpecifyImageSize", MGK_OptionErrorMustSpecifyImageSize },
    { "NoBlobDefined", MGK_OptionErrorNoBlobDefined },
    { "NoImagesDefined", MGK_OptionErrorNoImagesDefined },
    { "NonzeroWidthAndHeightRequired", MGK_OptionErrorNonzeroWidthAndHeightRequired },
    { "NoProfileNameWasGiven", MGK_OptionErrorNoProfileNameWasGiven },
    { "NullBlobArgument", MGK_OptionErrorNullBlobArgument },
    { "ReferenceImageRequired", MGK_OptionErrorReferenceImageRequired },
    { "ReferenceIsNotMyType", MGK_OptionErrorReferenceIsNotMyType },
    { "RegionAreaExceedsLimit", MGK_OptionErrorRegionAreaExceedsLimit },
    { "RequestDidNotReturnAnImage", MGK_OptionErrorRequestDidNotReturnAnImage },
    { "SteganoImageRequired", MGK_OptionErrorSteganoImageRequired },
    { "StereoImageRequired", MGK_OptionErrorStereoImageRequired },
    { "SubimageSpecificationReturnsNoImages", MGK_OptionErrorSubimageSpecificationReturnsNoImages },
    { "TileNotBoundedByImageDimensions", MGK_OptionErrorTileNotBoundedByImageDimensions },
    { "UnableToAddOrRemoveProfile", MGK_OptionErrorUnableToAddOrRemoveProfile },
    { "UnableToAverageImageSequence", MGK_OptionErrorUnableToAverageImageSequence },
    { "UnableToBlurImage", MGK_OptionErrorUnableToBlurImage },
    { "UnableToChopImage", MGK_OptionErrorUnableToChopImage },
    { "UnableToColorMatrixImage", MGK_OptionErrorUnableToColorMatrixImage },
    { "UnableToConstituteImage", MGK_OptionErrorUnableToConstituteImage },
    { "UnableToConvolveImage", MGK_OptionErrorUnableToConvolveImage },
    { "UnableToEdgeImage", MGK_OptionErrorUnableToEdgeImage },
    { "UnableToEqualizeImage", MGK_OptionErrorUnableToEqualizeImage },
    { "UnableToFilterImage", MGK_OptionErrorUnableToFilterImage },
    { "UnableToFormatImageMetadata", MGK_OptionErrorUnableToFormatImageMetadata },
    { "UnableToFrameImage", MGK_OptionErrorUnableToFrameImage },
    { "UnableToOilPaintImage", MGK_OptionErrorUnableToOilPaintImage },
    { "UnableToPaintImage", MGK_OptionErrorUnableToPaintImage },
    { "UnableToRaiseImage", MGK_OptionErrorUnableToRaiseImage },
    { "UnableToSharpenImage", MGK_OptionErrorUnableToSharpenImage },
    { "UnableToThresholdImage", MGK_OptionErrorUnableToThresholdImage },
    { "UnableToWaveImage", MGK_OptionErrorUnableToWaveImage },
    { "UnrecognizedAttribute", MGK_OptionErrorUnrecognizedAttribute },
    { "UnrecognizedChannelType", MGK_OptionErrorUnrecognizedChannelType },
    { "UnrecognizedColor", MGK_OptionErrorUnrecognizedColor },
    { "UnrecognizedColormapType", MGK_OptionErrorUnrecognizedColormapType },
    { "UnrecognizedColorspace", MGK_OptionErrorUnrecognizedColorspace },
    { "UnrecognizedCommand", MGK_OptionErrorUnrecognizedCommand },
    { "UnrecognizedComposeOperator", MGK_OptionErrorUnrecognizedComposeOperator },
    { "UnrecognizedDisposeMethod", MGK_OptionErrorUnrecognizedDisposeMethod },
    { "UnrecognizedElement", MGK_OptionErrorUnrecognizedElement },
    { "UnrecognizedEndianType", MGK_OptionErrorUnrecognizedEndianType },
    { "UnrecognizedGravityType", MGK_OptionErrorUnrecognizedGravityType },
    { "UnrecognizedHighlightStyle", MGK_OptionErrorUnrecognizedHighlightStyle },
    { "UnrecognizedImageCompression", MGK_OptionErrorUnrecognizedImageCompression },
    { "UnrecognizedImageFilter", MGK_OptionErrorUnrecognizedImageFilter },
    { "UnrecognizedImageFormat", MGK_OptionErrorUnrecognizedImageFormat },
    { "UnrecognizedImageMode", MGK_OptionErrorUnrecognizedImageMode },
    { "UnrecognizedImageType", MGK_OptionErrorUnrecognizedImageType },
    { "UnrecognizedIntentType", MGK_OptionErrorUnrecognizedIntentType },
    { "UnrecognizedInterlaceType", MGK_OptionErrorUnrecognizedInterlaceType },
    { "UnrecognizedListType", MGK_OptionErrorUnrecognizedListType },
    { "UnrecognizedMetric", MGK_OptionErrorUnrecognizedMetric },
    { "UnrecognizedModeType", MGK_OptionErrorUnrecognizedModeType },
    { "UnrecognizedNoiseType", MGK_OptionErrorUnrecognizedNoiseType },
    { "UnrecognizedOperator", MGK_OptionErrorUnrecognizedOperator },
    { "UnrecognizedOption", MGK_OptionErrorUnrecognizedOption },
    { "UnrecognizedPerlMagickMethod", MGK_OptionErrorUnrecognizedPerlMagickMethod },
    { "UnrecognizedPixelMap", MGK_OptionErrorUnrecognizedPixelMap },
    { "UnrecognizedPreviewType", MGK_OptionErrorUnrecognizedPreviewType },
    { "UnrecognizedResourceType", MGK_OptionErrorUnrecognizedResourceType },
    { "UnrecognizedType", MGK_OptionErrorUnrecognizedType },
    { "UnrecognizedUnitsType", MGK_OptionErrorUnrecognizedUnitsType },
    { "UnrecognizedVirtualPixelMethod", MGK_OptionErrorUnrecognizedVirtualPixelMethod },
    { "UnsupportedSamplingFactor", MGK_OptionErrorUnsupportedSamplingFactor },
    { "UsageError", MGK_OptionErrorUsageError },
    { "InvalidColorspaceType", MGK_OptionFatalErrorInvalidColorspaceType },
    { "InvalidEndianType", MGK_OptionFatalErrorInvalidEndianType },
    { "InvalidImageType", MGK_OptionFatalErrorInvalidImageType },
    { "InvalidInterlaceType", MGK_OptionFatalErrorInvalidInterlaceType },
    { "MissingAnImageFilename", MGK_OptionFatalErrorMissingAnImageFilename },
    { "MissingArgument", MGK_OptionFatalErrorMissingArgument },
    { "NoImagesWereLoaded", MGK_OptionFatalErrorNoImagesWereLoaded },
    { "OptionLengthExceedsLimit", MGK_OptionFatalErrorOptionLengthExceedsLimit },
    { "RequestDidNotReturnAnImage", MGK_OptionFatalErrorRequestDidNotReturnAnImage },
    { "UnableToOpenXServer", MGK_OptionFatalErrorUnableToOpenXServer },
    { "UnableToPersistKey", MGK_OptionFatalErrorUnableToPersistKey },
    { "UnrecognizedColormapType", MGK_OptionFatalErrorUnrecognizedColormapType },
    { "UnrecognizedColorspaceType", MGK_OptionFatalErrorUnrecognizedColorspaceType },
    { "UnrecognizedDisposeMethod", MGK_OptionFatalErrorUnrecognizedDisposeMethod },
    { "UnrecognizedEndianType", MGK_OptionFatalErrorUnrecognizedEndianType },
    { "UnrecognizedFilterType", MGK_OptionFatalErrorUnrecognizedFilterType },
    { "UnrecognizedImageCompressionType", MGK_OptionFatalErrorUnrecognizedImageCompressionType },
    { "UnrecognizedImageType", MGK_OptionFatalErrorUnrecognizedImageType },
    { "UnrecognizedInterlaceType", MGK_OptionFatalErrorUnrecognizedInterlaceType },
    { "UnrecognizedOption", MGK_OptionFatalErrorUnrecognizedOption },
    { "UnrecognizedResourceType", MGK_OptionFatalErrorUnrecognizedResourceType },
    { "UnrecognizedVirtualPixelMethod", MGK_OptionFatalErrorUnrecognizedVirtualPixelMethod },
    { "UnrecognizedColor", MGK_OptionWarningUnrecognizedColor },
    { "ImageExpected", MGK_RegistryErrorImageExpected },
    { "ImageInfoExpected", MGK_RegistryErrorImageInfoExpected },
    { "StructureSizeMismatch", MGK_RegistryErrorStructureSizeMismatch },
    { "UnableToGetRegistryID", MGK_RegistryErrorUnableToGetRegistryID },
    { "UnableToLocateImage", MGK_RegistryErrorUnableToLocateImage },
    { "UnableToSetRegistry", MGK_RegistryErrorUnableToSetRegistry },
    { "Default", MGK_RegistryFatalErrorDefault },
    { "Default", MGK_RegistryWarningDefault },
    { "CacheResourcesExhausted", MGK_ResourceLimitErrorCacheResourcesExhausted },
    { "ImagePixelHeightLimitExceeded", MGK_ResourceLimitErrorImagePixelHeightLimitExceeded },
    { "ImagePixelLimitExceeded", MGK_ResourceLimitErrorImagePixelLimitExceeded },
    { "ImagePixelWidthLimitExceeded", MGK_ResourceLimitErrorImagePixelWidthLimitExceeded },
    { "MemoryAllocationFailed", MGK_ResourceLimitErrorMemoryAllocationFailed },
    { "NexusPixelHeightLimitExceeded", MGK_ResourceLimitErrorNexusPixelHeightLimitExceeded },
    { "NexusPixelLimitExceeded", MGK_ResourceLimitErrorNexusPixelLimitExceeded },
    { "NexusPixelWidthLimitExceeded", MGK_ResourceLimitErrorNexusPixelWidthLimitExceeded },
    { "NoPixelsDefinedInCache", MGK_ResourceLimitErrorNoPixelsDefinedInCache },
    { "PixelCacheAllocationFailed", MGK_ResourceLimitErrorPixelCacheAllocationFailed },
    { "UnableToAddColorProfile", MGK_ResourceLimitErrorUnableToAddColorProfile },
    { "UnableToAddGenericProfile", MGK_ResourceLimitErrorUnableToAddGenericProfile },
    { "UnableToAddIPTCProfile", MGK_ResourceLimitErrorUnableToAddIPTCProfile },
    { "UnableToAddOrRemoveProfile", MGK_ResourceLimitErrorUnableToAddOrRemoveProfile },
    { "UnableToAllocateCoefficients", MGK_ResourceLimitErrorUnableToAllocateCoefficients },
    { "UnableToAllocateColormap", MGK_ResourceLimitErrorUnableToAllocateColormap },
    { "UnableToAllocateICCProfile", MGK_ResourceLimitErrorUnableToAllocateICCProfile },
    { "UnableToAllocateImage", MGK_ResourceLimitErrorUnableToAllocateImage },
    { "UnableToAllocateString", MGK_ResourceLimitErrorUnableToAllocateString },
    { "UnableToAnnotateImage", MGK_ResourceLimitErrorUnableToAnnotateImage },
    { "UnableToAverageImageSequence", MGK_ResourceLimitErrorUnableToAverageImageSequence },
    { "UnableToCloneDrawingWand", MGK_ResourceLimitErrorUnableToCloneDrawingWand },
    { "UnableToCloneImage", MGK_ResourceLimitErrorUnableToCloneImage },
    { "UnableToComputeImageSignature", MGK_ResourceLimitErrorUnableToComputeImageSignature },
    { "UnableToConstituteImage", MGK_ResourceLimitErrorUnableToConstituteImage },
    { "UnableToConvertFont", MGK_ResourceLimitErrorUnableToConvertFont },
    { "UnableToConvertStringToTokens", MGK_ResourceLimitErrorUnableToConvertStringToTokens },
    { "UnableToCreateColormap", MGK_ResourceLimitErrorUnableToCreateColormap },
    { "UnableToCreateColorTransform", MGK_ResourceLimitErrorUnableToCreateColorTransform },
    { "UnableToCreateCommandWidget", MGK_ResourceLimitErrorUnableToCreateCommandWidget },
    { "UnableToCreateImageGroup", MGK_ResourceLimitErrorUnableToCreateImageGroup },
    { "UnableToCreateImageMontage", MGK_ResourceLimitErrorUnableToCreateImageMontage },
    { "UnableToCreateXWindow", MGK_ResourceLimitErrorUnableToCreateXWindow },
    { "UnableToCropImage", MGK_ResourceLimitErrorUnableToCropImage },
    { "UnableToDespeckleImage", MGK_ResourceLimitErrorUnableToDespeckleImage },
    { "UnableToDetermineImageClass", MGK_ResourceLimitErrorUnableToDetermineImageClass },
    { "UnableToDetermineTheNumberOfImageColors", MGK_ResourceLimitErrorUnableToDetermineTheNumberOfImageColors },
    { "UnableToDitherImage", MGK_ResourceLimitErrorUnableToDitherImage },
    { "UnableToDrawOnImage", MGK_ResourceLimitErrorUnableToDrawOnImage },
    { "UnableToEdgeImage", MGK_ResourceLimitErrorUnableToEdgeImage },
    { "UnableToEmbossImage", MGK_ResourceLimitErrorUnableToEmbossImage },
    { "UnableToEnhanceImage", MGK_ResourceLimitErrorUnableToEnhanceImage },
    { "UnableToFloodfillImage", MGK_ResourceLimitErrorUnableToFloodfillImage },
    { "UnableToGammaCorrectImage", MGK_ResourceLimitErrorUnableToGammaCorrectImage },
    { "UnableToGetBestIconSize", MGK_ResourceLimitErrorUnableToGetBestIconSize },
    { "UnableToGetFromRegistry", MGK_ResourceLimitErrorUnableToGetFromRegistry },
    { "UnableToGetPackageInfo", MGK_ResourceLimitErrorUnableToGetPackageInfo },
    { "UnableToLevelImage", MGK_ResourceLimitErrorUnableToLevelImage },
    { "UnableToMagnifyImage", MGK_ResourceLimitErrorUnableToMagnifyImage },
    { "UnableToManageColor", MGK_ResourceLimitErrorUnableToManageColor },
    { "UnableToMapImage", MGK_ResourceLimitErrorUnableToMapImage },
    { "UnableToMapImageSequence", MGK_ResourceLimitErrorUnableToMapImageSequence },
    { "UnableToMedianFilterImage", MGK_ResourceLimitErrorUnableToMedianFilterImage },
    { "UnableToMotionBlurImage", MGK_ResourceLimitErrorUnableToMotionBlurImage },
    { "UnableToNoiseFilterImage", MGK_ResourceLimitErrorUnableToNoiseFilterImage },
    { "UnableToNormalizeImage", MGK_ResourceLimitErrorUnableToNormalizeImage },
    { "UnableToOpenColorProfile", MGK_ResourceLimitErrorUnableToOpenColorProfile },
    { "UnableToQuantizeImage", MGK_ResourceLimitErrorUnableToQuantizeImage },
    { "UnableToQuantizeImageSequence", MGK_ResourceLimitErrorUnableToQuantizeImageSequence },
    { "UnableToReadTextChunk", MGK_ResourceLimitErrorUnableToReadTextChunk },
    { "UnableToReadXImage", MGK_ResourceLimitErrorUnableToReadXImage },
    { "UnableToReadXServerColormap", MGK_ResourceLimitErrorUnableToReadXServerColormap },
    { "UnableToResizeImage", MGK_ResourceLimitErrorUnableToResizeImage },
    { "UnableToRotateImage", MGK_ResourceLimitErrorUnableToRotateImage },
    { "UnableToSampleImage", MGK_ResourceLimitErrorUnableToSampleImage },
    { "UnableToScaleImage", MGK_ResourceLimitErrorUnableToScaleImage },
    { "UnableToSelectImage", MGK_ResourceLimitErrorUnableToSelectImage },
    { "UnableToSharpenImage", MGK_ResourceLimitErrorUnableToSharpenImage },
    { "UnableToShaveImage", MGK_ResourceLimitErrorUnableToShaveImage },
    { "UnableToShearImage", MGK_ResourceLimitErrorUnableToShearImage },
    { "UnableToSortImageColormap", MGK_ResourceLimitErrorUnableToSortImageColormap },
    { "UnableToThresholdImage", MGK_ResourceLimitErrorUnableToThresholdImage },
    { "UnableToTransformColorspace", MGK_ResourceLimitErrorUnableToTransformColorspace },
    { "MemoryAllocationFailed", MGK_ResourceLimitFatalErrorMemoryAllocationFailed },
    { "SemaporeOperationFailed", MGK_ResourceLimitFatalErrorSemaporeOperationFailed },
    { "UnableToAllocateAscii85Info", MGK_ResourceLimitFatalErrorUnableToAllocateAscii85Info },
    { "UnableToAllocateCacheInfo", MGK_ResourceLimitFatalErrorUnableToAllocateCacheInfo },
    { "UnableToAllocateCacheView", MGK_ResourceLimitFatalErrorUnableToAllocateCacheView },
    { "UnableToAllocateColorInfo", MGK_ResourceLimitFatalErrorUnableToAllocateColorInfo },
    { "UnableToAllocateDashPattern", MGK_ResourceLimitFatalErrorUnableToAllocateDashPattern },
    { "UnableToAllocateDelegateInfo", MGK_ResourceLimitFatalErrorUnableToAllocateDelegateInfo },
    { "UnableToAllocateDerivatives", MGK_ResourceLimitFatalErrorUnableToAllocateDerivatives },
    { "UnableToAllocateDrawContext", MGK_ResourceLimitFatalErrorUnableToAllocateDrawContext },
    { "UnableToAllocateDrawInfo", MGK_ResourceLimitFatalErrorUnableToAllocateDrawInfo },
    { "UnableToAllocateDrawingWand", MGK_ResourceLimitFatalErrorUnableToAllocateDrawingWand },
    { "UnableToAllocateGammaMap", MGK_ResourceLimitFatalErrorUnableToAllocateGammaMap },
    { "UnableToAllocateImage", MGK_ResourceLimitFatalErrorUnableToAllocateImage },
    { "UnableToAllocateImagePixels", MGK_ResourceLimitFatalErrorUnableToAllocateImagePixels },
    { "UnableToAllocateLogInfo", MGK_ResourceLimitFatalErrorUnableToAllocateLogInfo },
    { "UnableToAllocateMagicInfo", MGK_ResourceLimitFatalErrorUnableToAllocateMagicInfo },
    { "UnableToAllocateMagickInfo", MGK_ResourceLimitFatalErrorUnableToAllocateMagickInfo },
    { "UnableToAllocateMagickMap", MGK_ResourceLimitFatalErrorUnableToAllocateMagickMap },
    { "UnableToAllocateModuleInfo", MGK_ResourceLimitFatalErrorUnableToAllocateModuleInfo },
    { "UnableToAllocateMontageInfo", MGK_ResourceLimitFatalErrorUnableToAllocateMontageInfo },
    { "UnableToAllocateQuantizeInfo", MGK_ResourceLimitFatalErrorUnableToAllocateQuantizeInfo },
    { "UnableToAllocateRandomKernel", MGK_ResourceLimitFatalErrorUnableToAllocateRandomKernel },
    { "UnableToAllocateRegistryInfo", MGK_ResourceLimitFatalErrorUnableToAllocateRegistryInfo },
    { "UnableToAllocateSemaphoreInfo", MGK_ResourceLimitFatalErrorUnableToAllocateSemaphoreInfo },
    { "UnableToAllocateString", MGK_ResourceLimitFatalErrorUnableToAllocateString },
    { "UnableToAllocateTypeInfo", MGK_ResourceLimitFatalErrorUnableToAllocateTypeInfo },
    { "UnableToAllocateWand", MGK_ResourceLimitFatalErrorUnableToAllocateWand },
    { "UnableToAnimateImageSequence", MGK_ResourceLimitFatalErrorUnableToAnimateImageSequence },
    { "UnableToCloneBlobInfo", MGK_ResourceLimitFatalErrorUnableToCloneBlobInfo },
    { "UnableToCloneCacheInfo", MGK_ResourceLimitFatalErrorUnableToCloneCacheInfo },
    { "UnableToCloneImage", MGK_ResourceLimitFatalErrorUnableToCloneImage },
    { "UnableToCloneImageInfo", MGK_ResourceLimitFatalErrorUnableToCloneImageInfo },
    { "UnableToConcatenateString", MGK_ResourceLimitFatalErrorUnableToConcatenateString },
    { "UnableToConvertText", MGK_ResourceLimitFatalErrorUnableToConvertText },
    { "UnableToCreateColormap", MGK_ResourceLimitFatalErrorUnableToCreateColormap },
    { "UnableToDestroySemaphore", MGK_ResourceLimitFatalErrorUnableToDestroySemaphore },
    { "UnableToDisplayImage", MGK_ResourceLimitFatalErrorUnableToDisplayImage },
    { "UnableToEscapeString", MGK_ResourceLimitFatalErrorUnableToEscapeString },
    { "UnableToInitializeSemaphore", MGK_ResourceLimitFatalErrorUnableToInitializeSemaphore },
    { "UnableToInterpretMSLImage", MGK_ResourceLimitFatalErrorUnableToInterpretMSLImage },
    { "UnableToLockSemaphore", MGK_ResourceLimitFatalErrorUnableToLockSemaphore },
    { "UnableToObtainRandomEntropy", MGK_ResourceLimitFatalErrorUnableToObtainRandomEntropy },
    { "UnableToUnlockSemaphore", MGK_ResourceLimitFatalErrorUnableToUnlockSemaphore },
    { "MemoryAllocationFailed", MGK_ResourceLimitWarningMemoryAllocationFailed },
    { "ImageDoesNotContainTheStreamGeometry", MGK_StreamErrorImageDoesNotContainTheStreamGeometry },
    { "NoStreamHandlerIsDefined", MGK_StreamErrorNoStreamHandlerIsDefined },
    { "PixelCacheIsNotOpen", MGK_StreamErrorPixelCacheIsNotOpen },
    { "UnableToAcquirePixelStream", MGK_StreamErrorUnableToAcquirePixelStream },
    { "UnableToSetPixelStream", MGK_StreamErrorUnableToSetPixelStream },
    { "UnableToSyncPixelStream", MGK_StreamErrorUnableToSyncPixelStream },
    { "Default", MGK_StreamFatalErrorDefault },
    { "Default", MGK_StreamWarningDefault },
    { "FontNotSpecified", MGK_TypeErrorFontNotSpecified },
    { "FontSubstitutionRequired", MGK_TypeErrorFontSubstitutionRequired },
    { "UnableToGetTypeMetrics", MGK_TypeErrorUnableToGetTypeMetrics },
    { "UnableToInitializeFreetypeLibrary", MGK_TypeErrorUnableToInitializeFreetypeLibrary },
    { "UnableToReadFont", MGK_TypeErrorUnableToReadFont },
    { "UnrecognizedFontEncoding", MGK_TypeErrorUnrecognizedFontEncoding },
    { "Default", MGK_TypeFatalErrorDefault },
    { "Default", MGK_TypeWarningDefault },
    { "InvalidColormapIndex", MGK_WandErrorInvalidColormapIndex },
    { "WandAPINotImplemented", MGK_WandErrorWandAPINotImplemented },
    { "WandContainsNoImageIndexs", MGK_WandErrorWandContainsNoImageIndexs },
    { "WandContainsNoImages", MGK_WandErrorWandContainsNoImages },
    { "ColorIsNotKnownToServer", MGK_XServerErrorColorIsNotKnownToServer },
    { "NoWindowWithSpecifiedIDExists", MGK_XServerErrorNoWindowWithSpecifiedIDExists },
    { "StandardColormapIsNotInitialized", MGK_XServerErrorStandardColormapIsNotInitialized },
    { "UnableToConnectToRemoteDisplay", MGK_XServerErrorUnableToConnectToRemoteDisplay },
    { "UnableToCreateBitmap", MGK_XServerErrorUnableToCreateBitmap },
    { "UnableToCreateColormap", MGK_XServerErrorUnableToCreateColormap },
    { "UnableToCreatePixmap", MGK_XServerErrorUnableToCreatePixmap },
    { "UnableToCreateProperty", MGK_XServerErrorUnableToCreateProperty },
    { "UnableToCreateStandardColormap", MGK_XServerErrorUnableToCreateStandardColormap },
    { "UnableToDisplayImageInfo", MGK_XServerErrorUnableToDisplayImageInfo },
    { "UnableToGetProperty", MGK_XServerErrorUnableToGetProperty },
    { "UnableToGetStandardColormap", MGK_XServerErrorUnableToGetStandardColormap },
    { "UnableToGetVisual", MGK_XServerErrorUnableToGetVisual },
    { "UnableToGrabMouse", MGK_XServerErrorUnableToGrabMouse },
    { "UnableToLoadFont", MGK_XServerErrorUnableToLoadFont },
    { "UnableToMatchVisualToStandardColormap", MGK_XServerErrorUnableToMatchVisualToStandardColormap },
    { "UnableToOpenXServer", MGK_XServerErrorUnableToOpenXServer },
    { "UnableToReadXAttributes", MGK_XServerErrorUnableToReadXAttributes },
    { "UnableToReadXWindowImage", MGK_XServerErrorUnableToReadXWindowImage },
    { "UnrecognizedColormapType", MGK_XServerErrorUnrecognizedColormapType },
    { "UnrecognizedGravityType", MGK_XServerErrorUnrecognizedGravityType },
    { "UnrecognizedVisualSpecifier", MGK_XServerErrorUnrecognizedVisualSpecifier },
    { "UnableToAllocateXHints", MGK_XServerFatalErrorUnableToAllocateXHints },
    { "UnableToCreateCursor", MGK_XServerFatalErrorUnableToCreateCursor },
    { "UnableToCreateGraphicContext", MGK_XServerFatalErrorUnableToCreateGraphicContext },
    { "UnableToCreateStandardColormap", MGK_XServerFatalErrorUnableToCreateStandardColormap },
    { "UnableToCreateTextProperty", MGK_XServerFatalErrorUnableToCreateTextProperty },
    { "UnableToCreateXImage", MGK_XServerFatalErrorUnableToCreateXImage },
    { "UnableToCreateXPixmap", MGK_XServerFatalErrorUnableToCreateXPixmap },
    { "UnableToCreateXWindow", MGK_XServerFatalErrorUnableToCreateXWindow },
    { "UnableToDisplayImage", MGK_XServerFatalErrorUnableToDisplayImage },
    { "UnableToDitherImage", MGK_XServerFatalErrorUnableToDitherImage },
    { "UnableToGetPixelInfo", MGK_XServerFatalErrorUnableToGetPixelInfo },
    { "UnableToGetVisual", MGK_XServerFatalErrorUnableToGetVisual },
    { "UnableToLoadFont", MGK_XServerFatalErrorUnableToLoadFont },
    { "UnableToMakeXWindow", MGK_XServerFatalErrorUnableToMakeXWindow },
    { "UnableToOpenXServer", MGK_XServerFatalErrorUnableToOpenXServer },
    { "UnableToViewFonts", MGK_XServerFatalErrorUnableToViewFonts },
    { "UnableToGetVisual", MGK_XServerWarningUnableToGetVisual },
    { "UsingDefaultVisual", MGK_XServerWarningUsingDefaultVisual },
    { "", 0 }
  };
#endif /* if defined(_INCLUDE_TAGMAP_TABLE_) */

#if defined(_INCLUDE_MESSAGE_TABLE_)
static const char message_dat[] =
    "%1\0"
    "Unable to create blob\0"
    "Unable to deduce image format\0"
    "Unable to obtain current offset\0"
    "Unable to open file\0"
    "Unable to read file\0"
    "Unable to read to offset\0"
    "Unable to seek to offset\0"
    "Unable to write blob\0"
    "Unrecognized image format\0"
    "default error\0"
    "default warning\0"
    "Cache nexus contains no pixels\0"
    "Inconsistent persistent cache depth\0"
    "Pixel cache dimensions incompatible with image dimensions\0"
    "Pixel cache is not open\0"
    "Unable to allocate cache view\0"
    "Unable to clone cache\0"
    "Unable to extend cache\0"
    "Unable to get cache nexus\0"
    "Unable to get pixels from cache\0"
    "Unable to open cache\0"
    "Unable to persist pixel cache\0"
    "Unable to read pixel cache\0"
    "Unable to sync cache (check temporary file disk space)\0"
    "disk allocation failed\0"
    "Unable to extend pixel cache\0"
    "default warning\0"
    "Arithmetic overflow\0"
    "Colormap size exceeds limit\0"
    "Colormap type not supported\0"
    "Colorspace model is not supported\0"
    "Color type not supported\0"
    "Compression not valid\0"
    "Data encoding scheme is not supported\0"
    "Data storage type is not supported\0"
    "Coder did not return an image (this is a bug, please report it!)\0"
    "Delta-PNG is not supported\0"
    "Division by zero\0"
    "Encrypted WPG image file not supported\0"
    "Fractal compression not supported\0"
    "Image column or row size is not supported\0"
    "Image does not have a matte channel\0"
    "Image is not tiles\0"
    "Image type not supported\0"
    "Incompatible size of double\0"
    "Irregular channel geometry not supported\0"
    "JNG compression is not supported\0"
    "JPEG compression is not supported\0"
    "JPEG embedding failed\0"
    "Location type is not supported\0"
    "Map storage type is not supported\0"
    "MSB order not supported bitmap\0"
    "Multi-dimensional matrices are not supported\0"
    "Multiple record list not supported\0"
    "No 8BIM data is available\0"
    "No APP1 data is available\0"
    "No bitmap on clipboard\0"
    "No color profile available\0"
    "No data returned\0"
    "No image vector graphics\0"
    "No IPTC info was found\0"
    "No IPTC profile available\0"
    "Number of images is not supported\0"
    "Only continuous tone picture supported\0"
    "Only level zero files Supported\0"
    "PNG compression is not supported\0"
    "PNG library is too old\0"
    "RLE compression not supported\0"
    "Subsampling requires that image width be evenly divisible by two\0"
    "Unable to copy profile\0"
    "Unable to create a DC\0"
    "Unable to create bitmap\0"
    "Unable to decompress image\0"
    "Unable to Initialize FPX library\0"
    "Unable to open blob\0"
    "Unable to read aspect ratio\0"
    "Unable to read CIELAB images\0"
    "Unable to read summary info\0"
    "Unable to set affine matrix\0"
    "Unable to set aspect ratio\0"
    "Unable to set color twist\0"
    "Unable to set contrast\0"
    "Unable to set filtering value\0"
    "Unable to set image comment\0"
    "Unable to set image title\0"
    "Unable to set JPEG level\0"
    "Unable to set region of interest\0"
    "Unable to set summary info\0"
    "Unable to translate text\0"
    "Unable to write MPEG parameters\0"
    "Unable to write to temporary file\0"
    "Unable to zip-compress image\0"
    "Unsupported bits per sample\0"
    "Unsupported cell type in the matrix\0"
    "Unsupported samples per pixel\0"
    "WebP decoding failed: user abort\0"
    "WebP encoding failed: unknown reason\0"
    "WebP encoding failed: bad dimension\0"
    "WebP encoding failed: bad write\0"
    "WebP encoding failed: bitstream out of memory\0"
    "WebP encoding failed: File too big (> 4GB)\0"
    "WebP encoding failed: invalid configuration\0"
    "WebP encoding failed: null parameter\0"
    "WebP encoding failed: out of memory\0"
    "WebP encoding failed: partition 0 overflow (> 512K)\0"
    "WebP encoding failed: partition overflow (> 16M)\0"
    "WebP encoding failed: user abort\0"
    "Invalid WebP configuration parameters supplied\0"
    "WebP failed: invalid parameter\0"
    "ZIP compression is not supported\0"
    "default error\0"
    "Lossless to lossy JPEG conversion\0"
    "include element nested too deeply\0"
    "Registry key lookup failed. Package is not properly installed on this machine.\0"
    "String token maximum length exceeded\0"
    "Unable to access configuration file\0"
    "Unable to access font file\0"
    "Unable to access log configuration file\0"
    "Unable to access module file\0"
    "default error\0"
    "Unable to change to working directory\0"
    "Unable to get current working directory\0"
    "Unable to restore current working directory\0"
    "default warning\0"
    "An error has occurred reading from file\0"
    "An error has occurred writing to file\0"
    "Colormap exceeded colors limit\0"
    "Compression not valid\0"
    "Corrupt image\0"
    "Image file or blob does not contain any image data\0"
    "Image file has no scenes\0"
    "Image type not supported\0"
    "Improper image header\0"
    "Insufficient image data in file\0"
    "Invalid colormap index\0"
    "invalid file format version\0"
    "Length and filesize do not match\0"
    "Missing a required image channel\0"
    "Negative or zero image size\0"
    "Non OS2 BMP header size less than 40\0"
    "Not enough tiles found in level\0"
    "Static planes value not equal to 1\0"
    "Subsampling requires that image width be evenly divisible by two\0"
    "Too much image data in file\0"
    "Unable to read colormap from dump file\0"
    "Unable to read color profile\0"
    "Unable to read extension block\0"
    "Unable to read generic profile\0"
    "Unable to read image data\0"
    "Unable to read image header\0"
    "Unable to read IPTC profile\0"
    "Unable to read pixmap from dump file\0"
    "Unable to read sub image data\0"
    "Unable to read VID image\0"
    "Unable to read window name from dump file\0"
    "Unable to runlength decode image\0"
    "Unable to uncompress image\0"
    "Unexpected end-of-file\0"
    "Unexpected sampling factor\0"
    "Unknown pattern type\0"
    "Unrecognized bits per pixel\0"
    "Unrecognized compression\0"
    "Unrecognized number of colors\0"
    "Unrecognized XWD header\0"
    "Unsupported bits per sample\0"
    "Unsupported number of planes\0"
    "Unable to persist key\0"
    "Compression not valid\0"
    "Corrupt image (some data returned)\0"
    "Improper image header\0"
    "Invalid colormap index\0"
    "Length and filesize do not match\0"
    "Negative or zero image size\0"
    "Non OS2 header size error\0"
    "Corrupt PCD image, skipping to sync byte\0"
    "Static planes value not equal to one\0"
    "Unable to parse embedded profile\0"
    "Unrecognized bits per pixel\0"
    "Unrecognized image compression\0"
    "Delegate failed\0"
    "Failed to allocate argument list.\0"
    "Failed to allocate Ghostscript interpreter.\0"
    "Failed to compute output size\0"
    "Failed to find Ghostscript (not installed?).\0"
    "Failed to render file\0"
    "Failed to scan file\0"
    "No tag found\0"
    "Postscript delegate failed\0"
    "Unable to create image\0"
    "Unable to create image component\0"
    "Unable to decode image file\0"
    "Unable to encode image file\0"
    "Unable to initialize FPX library\0"
    "Unable to initialize WMF library\0"
    "Unable to manage JP2 stream\0"
    "Unable to write SVG format\0"
    "WebP library ABI does not match header ABI (build issue!)\0"
    "default error\0"
    "default warning\0"
    "Already pushing pattern definition\0"
    "drawing recursion detected\0"
    "text value does not convert to float\0"
    "text value does not convert to integer\0"
    "invalid primitive argument\0"
    "Non-conforming drawing primitive definition\0"
    "primitive arithmetic overflow\0"
    "too many coordinates\0"
    "Unable to print\0"
    "unbalanced graphic context push-pop\0"
    "unreasonable gradient image size\0"
    "vector path truncated\0"
    "default error\0"
    "Not a relative URL\0"
    "Not currently pushing pattern definition\0"
    "URL not found\0"
    "Unable to create temporary file\0"
    "Unable to open file\0"
    "Unable to write file\0"
    "default error\0"
    "default warning\0"
    "angle is discontinuous\0"
    "CMYKA image lacks an alpha channel (indexes)\0"
    "Colorspace color profile mismatch\0"
    "image colorspace differs\0"
    "image colorspace mismatch\0"
    "image difference exceeds limit (%s)\0"
    "image does not contain resolution\0"
    "image is not colormapped\0"
    "image opacity differs\0"
    "Image sequence is required\0"
    "image size differs\0"
    "Invalid colormap index\0"
    "left and right image sizes differ\0"
    "no images were found\0"
    "no images were loaded\0"
    "no [LOCALE] image attribute\0"
    "too many cluster\0"
    "unable to append image\0"
    "Unable to assign profile\0"
    "unable to average image\0"
    "unable to coalesce image\0"
    "unable to compare images\0"
    "unable to create image mosaic\0"
    "unable to create stereo image\0"
    "unable to deconstruct image sequence\0"
    "unable to export image pixels\0"
    "unable to flatten image\0"
    "Unable to get clip mask\0"
    "Unable to get composite mask\0"
    "unable to handle image channel\0"
    "unable to import image pixels\0"
    "unable to resize image\0"
    "unable to segment image\0"
    "Unable to set clip mask\0"
    "Unable to set composite mask\0"
    "unable to shear image\0"
    "width or height exceeds limit\0"
    "Unable to persist key\0"
    "default warning\0"
    "DPS library is not available\0"
    "FPX library is not available\0"
    "FreeType library is not available\0"
    "JPEG compression library is not available\0"
    "LCMS encoding not enabled\0"
    "LZW encoding not enabled\0"
    "No decode delegate for this image format\0"
    "No encode delegate for this image format\0"
    "TIFF library is not available\0"
    "XML library is not available\0"
    "X Window library is not available\0"
    "ZLIB compression library is not available\0"
    "default error\0"
    "default warning\0"
    "Failed to close module\0"
    "Failed to find symbol\0"
    "Unable to load module\0"
    "Unable to register image format\0"
    "Unrecognized module\0"
    "Unable to initialize module loader\0"
    "default warning\0"
    "default error\0"
    "default error\0"
    "User requested termination (via signal)\0"
    "default warning\0"
    "bevel width is negative\0"
    "color separated image required\0"
    "frame is less than image size\0"
    "geometry dimensions are zero\0"
    "geometry does not contain image\0"
    "hald clut image dimensions are invalid\0"
    "images are not the same size\0"
    "size must exceed bevel width\0"
    "image smaller than kernel width\0"
    "image smaller than radius\0"
    "image widths or heights differ\0"
    "input images already specified\0"
    "Invalid subimage specification\0"
    "kernel radius is too small\0"
    "kernel width must be an odd number\0"
    "Matrix is not square (%s elements)\0"
    "Matrix size is out of range\0"
    "Missing an image filename\0"
    "Option '%s' requires an argument or argument is malformed\0"
    "Must specify a image name\0"
    "Must specify image size\0"
    "No Binary Large OBjects defined\0"
    "No images defined\0"
    "Non-zero width and height required\0"
    "No profile name was given\0"
    "Null blob argument\0"
    "Reference image required\0"
    "Reference is not my type\0"
    "Region area exceeds implementation limit\0"
    "Request did not return an image\0"
    "Stegano image required\0"
    "Stereo image required\0"
    "Subimage specification returns no images\0"
    "Tile is not bounded by image dimensions\0"
    "Unable to add or remove profile\0"
    "unable to average image sequence\0"
    "unable to blur image\0"
    "unable to chop image\0"
    "Unable to color matrix image\0"
    "Unable to constitute image\0"
    "Unable to convolve image\0"
    "Unable to edge image\0"
    "Unable to equalize image\0"
    "Unable to filter image\0"
    "unable to format image meta data\0"
    "Unable to frame image\0"
    "unable to oil paint image\0"
    "Unable to paint image\0"
    "Unable to raise image\0"
    "Unable to sharpen image\0"
    "Unable to threshold image\0"
    "Unable to wave image\0"
    "Unrecognized attribute\0"
    "Unrecognized channel type\0"
    "Unrecognized color\0"
    "Unrecognized colormap type\0"
    "Unrecognized image colorspace\0"
    "Unrecognized command '%s'. Use -help for a usage summary or see manual.\0"
    "Unrecognized compose operator\0"
    "Unrecognized dispose method\0"
    "Unrecognized element\0"
    "Unrecognized endian type\0"
    "Unrecognized gravity type\0"
    "Unrecognized highlight style\0"
    "Unrecognized image compression\0"
    "Unrecognized image filter\0"
    "Unrecognized image format\0"
    "Unrecognized image mode\0"
    "Unrecognized image type\0"
    "Unrecognized intent type\0"
    "Unrecognized interlace type\0"
    "Unrecognized list type\0"
    "Unrecognized error metric\0"
    "Unrecognized mode type\0"
    "Unrecognized noise type\0"
    "Unrecognized operator\0"
    "Unrecognized option\0"
    "Unrecognized PerlMagick method\0"
    "Unrecognized pixel map\0"
    "Unrecognized preview type\0"
    "Unrecognized resource type\0"
    "Unrecognized type\0"
    "Unrecognized units type\0"
    "Unrecognized virtual pixel method\0"
    "Unsupported sampling factor\0"
    "Improper arguments supplied, please see manual\0"
    "Invalid colorspace type\0"
    "Invalid endian type\0"
    "Invalid image type\0"
    "Invalid interlace type\0"
    "Missing an image filename\0"
    "Option '%s' requires an argument or argument is malformed\0"
    "No images were loaded\0"
    "Option length exceeds limit\0"
    "Request did not return an image\0"
    "Unable to open XServer\0"
    "Unable to persist key\0"
    "Unrecognized colormap type\0"
    "Unrecognized colorspace type\0"
    "unrecognized dispose method\0"
    "Unrecognized endian type\0"
    "Unrecognized filter type\0"
    "unrecognized compression type\0"
    "Unrecognized image type\0"
    "Unrecognized interlace type\0"
    "Unrecognized option\0"
    "Unrecognized resource type\0"
    "Unrecognized virtual pixel method\0"
    "Unrecognized color\0"
    "image expected\0"
    "image info expected\0"
    "structure size mismatch\0"
    "Unable to get registry ID\0"
    "Unable to locate image\0"
    "Unable to set registry\0"
    "default error\0"
    "default warning\0"
    "Disk space limit exceeded (see -limit Disk)\0"
    "Image pixel height limit exceeded (see -limit Height)\0"
    "Image pixel limit exceeded (see -limit Pixels)\0"
    "Image pixel width limit exceeded (see -limit Width)\0"
    "Memory allocation failed\0"
    "Pixel nexus height limit exceeded (see -limit Height)\0"
    "Pixel nexus limit exceeded (see -limit Pixels)\0"
    "Pixel nexus width limit exceeded (see -limit Width)\0"
    "No pixels defined in cache\0"
    "Pixel cache allocation failed\0"
    "unable to add ICC Color profile\0"
    "unable to add generic profile\0"
    "unable to add IPTC profile\0"
    "unable to add or remove profile\0"
    "unable to allocate coefficients\0"
    "Unable to allocate colormap\0"
    "unable to allocate ICC profile\0"
    "Unable to allocate image\0"
    "unable to allocate string\0"
    "Unable to annotate image\0"
    "unable to average image sequence\0"
    "unable to clone drawing wand\0"
    "unable to clone image\0"
    "unable to compute image signature\0"
    "unable to constitute image\0"
    "unable to convert font\0"
    "unable to convert strings to tokens\0"
    "Unable to create colormap\0"
    "unable to create color transform\0"
    "unable to create command widget\0"
    "unable to create image group\0"
    "Unable to create image montage\0"
    "unable to create X window\0"
    "unable to crop image\0"
    "unable to despeckle image\0"
    "unable to determine image class\0"
    "unable to determine the number of image colors\0"
    "unable to dither image\0"
    "unable to draw on image\0"
    "unable to edge image\0"
    "unable to emboss image\0"
    "unable to enhance image\0"
    "unable to floodfill image\0"
    "unable to gamma correct image\0"
    "unable to get best icon size\0"
    "unable to get from registry\0"
    "Unable to get package info\0"
    "unable to level image\0"
    "unable to magnify image\0"
    "Unable to manage color\0"
    "Unable to map image\0"
    "Unable to map image sequence\0"
    "unable to median filter image\0"
    "unable to motion blur image\0"
    "unable to noise filter image\0"
    "unable to normalize image\0"
    "unable to open color profile\0"
    "unable to quantize image\0"
    "unable to quantize image sequence\0"
    "unable to read text chunk\0"
    "unable to read X image\0"
    "unable to read X server colormap\0"
    "unable to resize image\0"
    "unable to rotate image\0"
    "unable to sample image\0"
    "unable to scale image\0"
    "unable to select image\0"
    "unable to sharpen image\0"
    "unable to shave image\0"
    "unable to shear image\0"
    "unable to sort image colormap\0"
    "unable to threshold image\0"
    "unable to transform colorspace\0"
    "Memory allocation failed\0"
    "Semaphore operation failed\0"
    "unable to allocate ascii85 info\0"
    "unable to allocate cache info\0"
    "unable to allocate cache view\0"
    "unable to allocate color info\0"
    "unable to allocate dash pattern\0"
    "unable to allocate delegate info\0"
    "unable to allocate derivates\0"
    "unable to allocate draw context\0"
    "unable to allocate draw info\0"
    "unable to allocate drawing wand\0"
    "unable to allocate gamma map\0"
    "unable to allocate image\0"
    "unable to allocate image pixels\0"
    "unable to allocate log info\0"
    "unable to allocate magic info\0"
    "unable to allocate magick info\0"
    "unable to allocate magick map\0"
    "unable to allocate module info\0"
    "unable to allocate montage info\0"
    "unable to allocate quantize info\0"
    "unable to allocate random kernel\0"
    "unable to allocate registry info\0"
    "unable to allocate semaphore info\0"
    "unable to allocate string\0"
    "unable to allocate type info\0"
    "unable to allocate wand\0"
    "unable to animate image sequence\0"
    "unable to clone blob info\0"
    "unable to clone cache info\0"
    "unable to clone image\0"
    "unable to clone image info\0"
    "unable to concatenate string\0"
    "unable to convert text\0"
    "unable to create colormap\0"
    "unable to destroy semaphore\0"
    "unable to display image\0"
    "unable to escape string\0"
    "unable to initialize semaphore\0"
    "unable to interpret MSL image\0"
    "unable to lock semaphore\0"
    "unable to obtain random bytes from operating system\0"
    "unable to unlock semaphore\0"
    "Memory allocation failed\0"
    "image does not contain the stream geometry\0"
    "no stream handler is defined\0"
    "Pixel cache is not open\0"
    "Unable to acquire pixel stream\0"
    "Unable to set pixel stream\0"
    "Unable to sync pixel stream\0"
    "default error\0"
    "default warning\0"
    "Font name not specified\0"
    "Font substitution required\0"
    "Unable to get type metrics\0"
    "Unable to initialize freetype library\0"
    "Unable to read font\0"
    "Unrecognized font encoding\0"
    "default error\0"
    "default warning\0"
    "invalid colormap index `%.1024s\0"
    "Wand API not implemented `%.1024s\0"
    "Wand contains no image indices `%.1024s\0"
    "Wand contains no images `%.1024s\0"
    "Color is not known to server\0"
    "No window with specified ID exists\0"
    "Standard Colormap is not initialized\0"
    "Unable to connect to remote display\0"
    "Unable to create bitmap\0"
    "Unable to create colormap\0"
    "Unable to create pixmap\0"
    "Unable to create property\0"
    "Unable to create standard colormap\0"
    "Unable to display image info\0"
    "Unable to get property\0"
    "Unable to get Standard Colormap\0"
    "Unable to get visual\0"
    "Unable to grab mouse\0"
    "Unable to load font\0"
    "Unable to match visual to Standard Colormap\0"
    "Unable to open X server\0"
    "Unable to read X attributes\0"
    "Unable to read X window image\0"
    "Unrecognized colormap type\0"
    "Unrecognized gravity type\0"
    "Unrecognized visual specifier\0"
    "Unable to allocate X hints\0"
    "Unable to create X cursor\0"
    "Unable to create graphic context\0"
    "unable to create standard colormap\0"
    "Unable to create text property\0"
    "Unable to create X image\0"
    "Unable to create X pixmap\0"
    "Unable to create X window\0"
    "unable to display image\0"
    "unable to dither image\0"
    "Unable to get pixel info\0"
    "Unable to get visual\0"
    "Unable to load font\0"
    "Unable to make X window\0"
    "Unable to open X server\0"
    "Unable to view fonts\0"
    "Unable to get visual\0"
    "UsingDefaultVisual\0"
  ;

static const unsigned short message_dat_offsets[] =
  {
    0,
    3,
    25,
    55,
    87,
    107,
    127,
    152,
    177,
    198,
    224,
    238,
    254,
    285,
    321,
    379,
    403,
    433,
    455,
    478,
    504,
    536,
    557,
    587,
    614,
    669,
    692,
    721,
    737,
    757,
    785,
    813,
    847,
    872,
    894,
    932,
    967,
    1032,
    1059,
    1076,
    1115,
    1149,
    1191,
    1227,
    1246,
    1271,
    1299,
    1340,
    1373,
    1407,
    1429,
    1460,
    1494,
    1525,
    1570,
    1605,
    1631,
    1657,
    1680,
    1707,
    1724,
    1749,
    1772,
    1798,
    1832,
    1871,
    1903,
    1936,
    1959,
    1989,
    2054,
    2077,
    2099,
    2123,
    2150,
    2183,
    2203,
    2231,
    2260,
    2288,
    2316,
    2343,
    2369,
    2392,
    2422,
    2450,
    2476,
    2501,
    2534,
    2561,
    2586,
    2618,
    2652,
    2681,
    2709,
    2745,
    2775,
    2808,
    2845,
    2881,
    2913,
    2959,
    3002,
    3046,
    3083,
    3119,
    3171,
    3220,
    3253,
    3300,
    3331,
    3364,
    3378,
    3412,
    3446,
    3525,
    3562,
    3598,
    3625,
    3665,
    3694,
    3708,
    3746,
    3786,
    3830,
    3846,
    3886,
    3924,
    3955,
    3977,
    3991,
    4042,
    4067,
    4092,
    4114,
    4146,
    4169,
    4197,
    4230,
    4263,
    4291,
    4328,
    4360,
    4395,
    4460,
    4488,
    4527,
    4556,
    4587,
    4618,
    4644,
    4672,
    4700,
    4737,
    4767,
    4792,
    4834,
    4867,
    4894,
    4917,
    4944,
    4965,
    4993,
    5018,
    5048,
    5072,
    5100,
    5129,
    5151,
    5173,
    5208,
    5230,
    5253,
    5286,
    5314,
    5340,
    5381,
    5418,
    5451,
    5479,
    5510,
    5526,
    5560,
    5604,
    5634,
    5679,
    5701,
    5721,
    5734,
    5761,
    5784,
    5817,
    5845,
    5873,
    5906,
    5939,
    5967,
    5994,
    6052,
    6066,
    6082,
    6117,
    6144,
    6181,
    6220,
    6247,
    6291,
    6321,
    6342,
    6358,
    6394,
    6427,
    6449,
    6463,
    6482,
    6523,
    6537,
    6569,
    6589,
    6610,
    6624,
    6640,
    6663,
    6708,
    6742,
    6767,
    6793,
    6829,
    6863,
    6888,
    6910,
    6937,
    6956,
    6979,
    7013,
    7034,
    7056,
    7084,
    7101,
    7124,
    7149,
    7173,
    7198,
    7223,
    7253,
    7283,
    7320,
    7350,
    7374,
    7398,
    7427,
    7458,
    7488,
    7511,
    7535,
    7559,
    7588,
    7610,
    7640,
    7662,
    7678,
    7707,
    7736,
    7770,
    7812,
    7838,
    7863,
    7904,
    7945,
    7975,
    8004,
    8038,
    8080,
    8094,
    8110,
    8133,
    8155,
    8177,
    8209,
    8229,
    8264,
    8280,
    8294,
    8308,
    8348,
    8364,
    8388,
    8419,
    8449,
    8478,
    8510,
    8549,
    8578,
    8607,
    8639,
    8665,
    8696,
    8727,
    8758,
    8785,
    8820,
    8855,
    8883,
    8909,
    8967,
    8993,
    9017,
    9049,
    9067,
    9102,
    9128,
    9147,
    9172,
    9197,
    9238,
    9270,
    9293,
    9315,
    9356,
    9396,
    9428,
    9461,
    9482,
    9503,
    9532,
    9559,
    9584,
    9605,
    9630,
    9653,
    9686,
    9708,
    9734,
    9756,
    9778,
    9802,
    9828,
    9849,
    9872,
    9898,
    9917,
    9944,
    9974,
    10046,
    10076,
    10104,
    10125,
    10150,
    10176,
    10205,
    10236,
    10262,
    10288,
    10312,
    10336,
    10361,
    10389,
    10412,
    10438,
    10461,
    10485,
    10507,
    10527,
    10558,
    10581,
    10607,
    10634,
    10652,
    10676,
    10710,
    10738,
    10785,
    10809,
    10829,
    10848,
    10871,
    10897,
    10955,
    10977,
    11005,
    11037,
    11060,
    11082,
    11109,
    11138,
    11166,
    11191,
    11216,
    11246,
    11270,
    11298,
    11318,
    11345,
    11379,
    11398,
    11413,
    11433,
    11457,
    11483,
    11506,
    11529,
    11543,
    11559,
    11603,
    11657,
    11704,
    11756,
    11781,
    11835,
    11882,
    11934,
    11961,
    11991,
    12023,
    12053,
    12080,
    12112,
    12144,
    12172,
    12203,
    12228,
    12254,
    12279,
    12312,
    12341,
    12363,
    12397,
    12424,
    12447,
    12483,
    12509,
    12542,
    12574,
    12603,
    12634,
    12660,
    12681,
    12707,
    12739,
    12786,
    12809,
    12833,
    12854,
    12877,
    12901,
    12927,
    12957,
    12986,
    13014,
    13041,
    13063,
    13087,
    13110,
    13130,
    13159,
    13189,
    13217,
    13246,
    13272,
    13301,
    13326,
    13360,
    13386,
    13409,
    13442,
    13465,
    13488,
    13511,
    13533,
    13556,
    13580,
    13602,
    13624,
    13654,
    13680,
    13711,
    13736,
    13763,
    13795,
    13825,
    13855,
    13885,
    13917,
    13950,
    13979,
    14011,
    14040,
    14072,
    14101,
    14126,
    14158,
    14186,
    14216,
    14247,
    14277,
    14308,
    14340,
    14373,
    14406,
    14439,
    14473,
    14499,
    14528,
    14552,
    14585,
    14611,
    14638,
    14660,
    14687,
    14716,
    14739,
    14765,
    14793,
    14817,
    14841,
    14872,
    14902,
    14927,
    14979,
    15006,
    15031,
    15074,
    15103,
    15127,
    15158,
    15185,
    15213,
    15227,
    15243,
    15267,
    15294,
    15321,
    15359,
    15379,
    15406,
    15420,
    15436,
    15468,
    15502,
    15542,
    15575,
    15604,
    15639,
    15676,
    15712,
    15736,
    15762,
    15786,
    15812,
    15847,
    15876,
    15899,
    15931,
    15952,
    15973,
    15993,
    16037,
    16061,
    16089,
    16119,
    16146,
    16172,
    16202,
    16229,
    16255,
    16288,
    16323,
    16354,
    16379,
    16405,
    16431,
    16455,
    16478,
    16503,
    16524,
    16544,
    16568,
    16592,
    16613,
    16634,
    16653,
    0
  };
#endif /* if defined(_INCLUDE_MESSAGE_TABLE_) */
