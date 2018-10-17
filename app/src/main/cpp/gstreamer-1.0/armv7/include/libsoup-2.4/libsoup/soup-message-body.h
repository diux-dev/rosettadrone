/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2000-2003, Ximian, Inc.
 */

#ifndef SOUP_MESSAGE_BODY_H
#define SOUP_MESSAGE_BODY_H 1

#include <libsoup/soup-types.h>

G_BEGIN_DECLS

typedef enum {
	SOUP_MEMORY_STATIC,
	SOUP_MEMORY_TAKE,
	SOUP_MEMORY_COPY,
	SOUP_MEMORY_TEMPORARY
} SoupMemoryUse;

typedef struct {
	const char *data;
	gsize       length;
} SoupBuffer;

SOUP_AVAILABLE_IN_2_4
GType soup_buffer_get_type (void);
#define SOUP_TYPE_BUFFER (soup_buffer_get_type ())

SOUP_AVAILABLE_IN_2_4
SoupBuffer *soup_buffer_new            (SoupMemoryUse   use,
					gconstpointer   data,
					gsize           length);
SOUP_AVAILABLE_IN_2_32
SoupBuffer *soup_buffer_new_take       (guchar         *data,
					gsize           length);
SOUP_AVAILABLE_IN_2_4
SoupBuffer *soup_buffer_new_subbuffer  (SoupBuffer     *parent,
					gsize           offset,
					gsize           length);

SOUP_AVAILABLE_IN_2_4
SoupBuffer *soup_buffer_new_with_owner (gconstpointer   data,
					gsize           length,
					gpointer        owner,
					GDestroyNotify  owner_dnotify);
SOUP_AVAILABLE_IN_2_4
gpointer    soup_buffer_get_owner      (SoupBuffer     *buffer);
SOUP_AVAILABLE_IN_2_32
void        soup_buffer_get_data       (SoupBuffer     *buffer,
					const guint8  **data,
					gsize          *length);
SOUP_AVAILABLE_IN_2_40
GBytes     *soup_buffer_get_as_bytes   (SoupBuffer *buffer);

SOUP_AVAILABLE_IN_2_4
SoupBuffer *soup_buffer_copy           (SoupBuffer     *buffer);
SOUP_AVAILABLE_IN_2_4
void        soup_buffer_free           (SoupBuffer     *buffer);

typedef struct {
	const char *data;
	goffset     length;
} SoupMessageBody;

SOUP_AVAILABLE_IN_2_4
GType soup_message_body_get_type (void);
#define SOUP_TYPE_MESSAGE_BODY (soup_message_body_get_type ())

SOUP_AVAILABLE_IN_2_4
SoupMessageBody *soup_message_body_new           (void);

SOUP_AVAILABLE_IN_2_24
void             soup_message_body_set_accumulate(SoupMessageBody *body,
						  gboolean         accumulate);
SOUP_AVAILABLE_IN_2_24
gboolean         soup_message_body_get_accumulate(SoupMessageBody *body);

SOUP_AVAILABLE_IN_2_4
void             soup_message_body_append        (SoupMessageBody *body,
						  SoupMemoryUse    use,
						  gconstpointer    data,
						  gsize            length);
SOUP_AVAILABLE_IN_2_32
void             soup_message_body_append_take   (SoupMessageBody *body,
						  guchar          *data,
						  gsize            length);
SOUP_AVAILABLE_IN_2_4
void             soup_message_body_append_buffer (SoupMessageBody *body,
						  SoupBuffer      *buffer);
SOUP_AVAILABLE_IN_2_4
void             soup_message_body_truncate      (SoupMessageBody *body);
SOUP_AVAILABLE_IN_2_4
void             soup_message_body_complete      (SoupMessageBody *body);

SOUP_AVAILABLE_IN_2_4
SoupBuffer      *soup_message_body_flatten       (SoupMessageBody *body);

SOUP_AVAILABLE_IN_2_4
SoupBuffer      *soup_message_body_get_chunk     (SoupMessageBody *body,
						  goffset          offset);

SOUP_AVAILABLE_IN_2_24
void             soup_message_body_got_chunk     (SoupMessageBody *body,
						  SoupBuffer      *chunk);
SOUP_AVAILABLE_IN_2_24
void             soup_message_body_wrote_chunk   (SoupMessageBody *body,
						  SoupBuffer      *chunk);

SOUP_AVAILABLE_IN_2_4
void             soup_message_body_free          (SoupMessageBody *body);

G_END_DECLS

#endif /* SOUP_MESSAGE_BODY_H */
