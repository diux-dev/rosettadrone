/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2000-2003, Ximian, Inc.
 */

#ifndef SOUP_MISC_H
#define SOUP_MISC_H 1

#include <libsoup/soup-types.h>

G_BEGIN_DECLS

/* Non-default-GMainContext operations */
SOUP_AVAILABLE_IN_2_4
GSource           *soup_add_io_watch         (GMainContext *async_context,
					      GIOChannel   *chan,
					      GIOCondition  condition,
					      GIOFunc       function,
					      gpointer      data);
SOUP_AVAILABLE_IN_2_4
GSource           *soup_add_idle             (GMainContext *async_context,
					      GSourceFunc   function,
					      gpointer      data);
SOUP_AVAILABLE_IN_2_24
GSource           *soup_add_completion	     (GMainContext *async_context,
					      GSourceFunc   function,
					      gpointer      data);
SOUP_AVAILABLE_IN_2_4
GSource           *soup_add_timeout          (GMainContext *async_context,
					      guint         interval,
					      GSourceFunc   function,
					      gpointer      data);

/* Misc utils */

SOUP_AVAILABLE_IN_2_4
guint              soup_str_case_hash        (gconstpointer key);
SOUP_AVAILABLE_IN_2_4
gboolean           soup_str_case_equal       (gconstpointer v1,
					      gconstpointer v2);

#define _SOUP_ATOMIC_INTERN_STRING(variable, value) ((const char *)(g_atomic_pointer_get (&(variable)) ? (variable) : (g_atomic_pointer_set (&(variable), (gpointer)g_intern_static_string (value)), (variable))))

/* character classes */

SOUP_AVAILABLE_IN_2_4
const char soup_char_attributes[];
#define SOUP_CHAR_URI_PERCENT_ENCODED 0x01
#define SOUP_CHAR_URI_GEN_DELIMS      0x02
#define SOUP_CHAR_URI_SUB_DELIMS      0x04
#define SOUP_CHAR_HTTP_SEPARATOR      0x08
#define SOUP_CHAR_HTTP_CTL            0x10

#define soup_char_is_uri_percent_encoded(ch) (soup_char_attributes[(guchar)ch] & SOUP_CHAR_URI_PERCENT_ENCODED)
#define soup_char_is_uri_gen_delims(ch)      (soup_char_attributes[(guchar)ch] & SOUP_CHAR_URI_GEN_DELIMS)
#define soup_char_is_uri_sub_delims(ch)      (soup_char_attributes[(guchar)ch] & SOUP_CHAR_URI_SUB_DELIMS)
#define soup_char_is_uri_unreserved(ch)      (!(soup_char_attributes[(guchar)ch] & (SOUP_CHAR_URI_PERCENT_ENCODED | SOUP_CHAR_URI_GEN_DELIMS | SOUP_CHAR_URI_SUB_DELIMS)))
#define soup_char_is_token(ch)               (!(soup_char_attributes[(guchar)ch] & (SOUP_CHAR_HTTP_SEPARATOR | SOUP_CHAR_HTTP_CTL)))

/* SSL stuff */
SOUP_AVAILABLE_IN_2_4
const gboolean soup_ssl_supported;

/* Part of a debugging API */

typedef enum {
	SOUP_CONNECTION_NEW,
	SOUP_CONNECTION_CONNECTING,
	SOUP_CONNECTION_IDLE,
	SOUP_CONNECTION_IN_USE,
	SOUP_CONNECTION_REMOTE_DISCONNECTED,
	SOUP_CONNECTION_DISCONNECTED
} SoupConnectionState;

G_END_DECLS

#endif /* SOUP_MISC_H */
