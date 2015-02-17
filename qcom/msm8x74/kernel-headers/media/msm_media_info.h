/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __MEDIA_INFO_H__
#define __MEDIA_INFO_H__
#ifndef MSM_MEDIA_ALIGN
#define MSM_MEDIA_ALIGN(__sz, __align) (((__sz) + (__align-1)) & (~(__align-1)))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
enum color_fmts {
 COLOR_FMT_NV12,
 COLOR_FMT_NV21,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define VENUS_Y_STRIDE(__color_fmt, __width) ({  unsigned int __alignment, __stride = 0;   if (__width) {   switch (__color_fmt) {   case COLOR_FMT_NV12:   __alignment = 128;   __stride = MSM_MEDIA_ALIGN(__width, __alignment);  break;  default:  break;  }  }   __stride; })
#define VENUS_UV_STRIDE(__color_fmt, __width) ({  unsigned int __alignment, __stride = 0;   if (__width) {  switch (__color_fmt) {   case COLOR_FMT_NV12:   __alignment = 128;   __stride = MSM_MEDIA_ALIGN(__width, __alignment);   break;   default:   break;   }   }   __stride;  })
#define VENUS_Y_SCANLINES(__color_fmt, __height) ({   unsigned int __alignment, __sclines = 0;   if (__height) {  switch (__color_fmt) {   case COLOR_FMT_NV12:   __alignment = 32;   __sclines = MSM_MEDIA_ALIGN(__height, __alignment);   break;   default:   break;   }   }   __sclines;  })
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENUS_UV_SCANLINES(__color_fmt, __height) ({  unsigned int __alignment, __sclines = 0;   if (__height) {  switch (__color_fmt) {   case COLOR_FMT_NV12:   __alignment = 16;   __sclines = MSM_MEDIA_ALIGN(((__height + 1) >> 1), __alignment);   break;   default:   break;   }   }   __sclines;  })
#define VENUS_BUFFER_SIZE(   __color_fmt, __width, __height) ({   unsigned int __uv_alignment;   unsigned int __size = 0;   unsigned int __y_plane, __uv_plane, __y_stride,   __uv_stride, __y_sclines, __uv_sclines;   if (__width && __height) {  __y_stride = VENUS_Y_STRIDE(__color_fmt, __width);   __uv_stride = VENUS_UV_STRIDE(__color_fmt, __width);   __y_sclines = VENUS_Y_SCANLINES(__color_fmt, __height);   __uv_sclines = VENUS_UV_SCANLINES(__color_fmt, __height);   switch (__color_fmt) {   case COLOR_FMT_NV12:   __uv_alignment = 4096;   __y_plane = __y_stride * __y_sclines;   __uv_plane = __uv_stride * __uv_sclines + __uv_alignment;   __size = __y_plane + __uv_plane;   __size = MSM_MEDIA_ALIGN(__size, 4096);   break;   default:   break;   }   }   __size;  })
#endif

