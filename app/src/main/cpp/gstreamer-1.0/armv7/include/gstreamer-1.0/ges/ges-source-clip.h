/* GStreamer Editing Services
 * Copyright (C) 2009 Edward Hervey <edward.hervey@collabora.co.uk>
 *               2009 Nokia Corporation
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

#ifndef _GES_SOURCE_CLIP
#define _GES_SOURCE_CLIP

#include <glib-object.h>
#include <ges/ges-types.h>
#include <ges/ges-clip.h>
#include <ges/ges-enums.h>

G_BEGIN_DECLS

#define GES_TYPE_SOURCE_CLIP ges_source_clip_get_type()

#define GES_SOURCE_CLIP(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GES_TYPE_SOURCE_CLIP, GESSourceClip))

#define GES_SOURCE_CLIP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), GES_TYPE_SOURCE_CLIP, GESSourceClipClass))

#define GES_IS_SOURCE_CLIP(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GES_TYPE_SOURCE_CLIP))

#define GES_IS_SOURCE_CLIP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), GES_TYPE_SOURCE_CLIP))

#define GES_SOURCE_CLIP_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), GES_TYPE_SOURCE_CLIP, GESSourceClipClass))

typedef struct _GESSourceClipPrivate GESSourceClipPrivate;

/**
 * GESSourceClip:
 *
 * Base class for sources of a #GESLayer
 */

struct _GESSourceClip {
  GESClip parent;

  /*< private >*/
  GESSourceClipPrivate *priv;

  /* Padding for API extension */
  gpointer _ges_reserved[GES_PADDING];
};

/**
 * GESSourceClipClass:
 */

struct _GESSourceClipClass {
  /*< private >*/
  GESClipClass parent_class;

  /* Padding for API extension */
  gpointer _ges_reserved[GES_PADDING];
};

GES_API
GType ges_source_clip_get_type (void);

G_END_DECLS

#endif /* _GES_SOURCE_CLIP */

