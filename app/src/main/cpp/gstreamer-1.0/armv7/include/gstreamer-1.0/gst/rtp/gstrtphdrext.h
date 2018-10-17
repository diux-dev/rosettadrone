/* GStreamer
 * Copyright (C) <2012> Wim Taymans <wim.taymans@gmail.com>
 *
 * gstrtphdrext.h: RTP header extensions
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
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_RTPHDREXT_H__
#define __GST_RTPHDREXT_H__

#include <gst/gst.h>
#include <gst/rtp/gstrtpbuffer.h>

G_BEGIN_DECLS

#define GST_RTP_HDREXT_BASE "urn:ietf:params:rtp-hdrext:"

/* RFC 6051 */
#define GST_RTP_HDREXT_NTP_64 "ntp-64"

#define GST_RTP_HDREXT_NTP_64_SIZE 8

GST_RTP_API
gboolean       gst_rtp_hdrext_set_ntp_64  (gpointer data, guint size, guint64 ntptime);

GST_RTP_API
gboolean       gst_rtp_hdrext_get_ntp_64  (gpointer data, guint size, guint64 *ntptime);

#define GST_RTP_HDREXT_NTP_56 "ntp-56"

#define GST_RTP_HDREXT_NTP_56_SIZE 7

GST_RTP_API
gboolean       gst_rtp_hdrext_set_ntp_56  (gpointer data, guint size, guint64 ntptime);

GST_RTP_API
gboolean       gst_rtp_hdrext_get_ntp_56  (gpointer data, guint size, guint64 *ntptime);

G_END_DECLS

#endif /* __GST_RTPHDREXT_H__ */

