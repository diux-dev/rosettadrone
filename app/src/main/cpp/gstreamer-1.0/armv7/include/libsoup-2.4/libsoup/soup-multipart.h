/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2008 Red Hat, Inc.
 */

#ifndef SOUP_MULTIPART_H
#define SOUP_MULTIPART_H 1

#include <libsoup/soup-types.h>
#include <libsoup/soup-message-body.h>
#include <libsoup/soup-message-headers.h>

G_BEGIN_DECLS

typedef struct SoupMultipart SoupMultipart;

SOUP_AVAILABLE_IN_2_26
GType soup_multipart_get_type (void);
#define SOUP_TYPE_MULTIPART (soup_multipart_get_type ())

SOUP_AVAILABLE_IN_2_26
SoupMultipart *soup_multipart_new              (const char          *mime_type);
SOUP_AVAILABLE_IN_2_26
SoupMultipart *soup_multipart_new_from_message (SoupMessageHeaders  *headers,
						SoupMessageBody     *body);

SOUP_AVAILABLE_IN_2_26
int      soup_multipart_get_length         (SoupMultipart       *multipart);
SOUP_AVAILABLE_IN_2_26
gboolean soup_multipart_get_part           (SoupMultipart       *multipart,
					    int                  part,
					    SoupMessageHeaders **headers,
					    SoupBuffer         **body);

SOUP_AVAILABLE_IN_2_26
void     soup_multipart_append_part        (SoupMultipart       *multipart,
					    SoupMessageHeaders  *headers,
					    SoupBuffer          *body);

SOUP_AVAILABLE_IN_2_26
void     soup_multipart_append_form_string (SoupMultipart       *multipart,
					    const char          *control_name,
					    const char          *data);
SOUP_AVAILABLE_IN_2_26
void     soup_multipart_append_form_file   (SoupMultipart       *multipart,
					    const char          *control_name,
					    const char          *filename,
					    const char          *content_type,
					    SoupBuffer          *body);

SOUP_AVAILABLE_IN_2_26
void     soup_multipart_to_message         (SoupMultipart       *multipart,
					    SoupMessageHeaders  *dest_headers,
					    SoupMessageBody     *dest_body);

SOUP_AVAILABLE_IN_2_26
void     soup_multipart_free               (SoupMultipart       *multipart);

G_END_DECLS

#endif /* SOUP_MULTIPART_H */
