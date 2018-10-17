/*
 * GStreamer
 * Copyright (C) 2015 Matthew Waters <matthew@centricular.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef _GST_GL_ENUMS_H_
#define _GST_GL_ENUMS_H_

/**
 * GstGLTextureTarget:
 * @GST_GL_TEXTURE_TARGET_NONE: no texture target
 * @GST_GL_TEXTURE_TARGET_2D: 2D texture target
 * @GST_GL_TEXTURE_TARGET_RECTANGLE: rectangle texture target
 * @GST_GL_TEXTURE_TARGET_EXTERNAL_OES: external oes texture target
 *
 * Since: 1.8
 */
typedef enum
{
  GST_GL_TEXTURE_TARGET_NONE,
  GST_GL_TEXTURE_TARGET_2D,
  GST_GL_TEXTURE_TARGET_RECTANGLE,
  GST_GL_TEXTURE_TARGET_EXTERNAL_OES,
} GstGLTextureTarget;

#endif /* _GST_GL_ENUMS_H_ */
