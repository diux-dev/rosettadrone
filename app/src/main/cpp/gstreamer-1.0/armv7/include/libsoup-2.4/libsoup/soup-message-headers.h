/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2005 Novell, Inc.
 */

#ifndef SOUP_MESSAGE_HEADERS_H
#define SOUP_MESSAGE_HEADERS_H 1

#include <libsoup/soup-types.h>

G_BEGIN_DECLS

typedef struct SoupMessageHeaders SoupMessageHeaders;
SOUP_AVAILABLE_IN_2_4
GType soup_message_headers_get_type (void);
#define SOUP_TYPE_MESSAGE_HEADERS (soup_message_headers_get_type ())

typedef enum {
	SOUP_MESSAGE_HEADERS_REQUEST,
	SOUP_MESSAGE_HEADERS_RESPONSE,
	SOUP_MESSAGE_HEADERS_MULTIPART
} SoupMessageHeadersType;

SOUP_AVAILABLE_IN_2_4
SoupMessageHeaders *soup_message_headers_new      (SoupMessageHeadersType type);

SOUP_AVAILABLE_IN_2_4
void                soup_message_headers_free     (SoupMessageHeaders *hdrs);

SOUP_AVAILABLE_IN_2_4
void                soup_message_headers_append   (SoupMessageHeaders *hdrs,
						   const char         *name,
						   const char         *value);
SOUP_AVAILABLE_IN_2_4
void                soup_message_headers_replace  (SoupMessageHeaders *hdrs,
						   const char         *name,
						   const char         *value);

SOUP_AVAILABLE_IN_2_4
void                soup_message_headers_remove   (SoupMessageHeaders *hdrs,
						   const char         *name);
SOUP_AVAILABLE_IN_2_4
void                soup_message_headers_clear    (SoupMessageHeaders *hdrs);

SOUP_AVAILABLE_IN_2_36
void                soup_message_headers_clean_connection_headers (SoupMessageHeaders *hdrs);

#ifndef SOUP_DISABLE_DEPRECATED
SOUP_AVAILABLE_IN_2_4
SOUP_DEPRECATED_IN_2_28_FOR ("soup_message_headers_get_one or soup_message_headers_get_list")
const char         *soup_message_headers_get      (SoupMessageHeaders *hdrs,
						   const char         *name);
#endif
SOUP_AVAILABLE_IN_2_28
const char         *soup_message_headers_get_one  (SoupMessageHeaders *hdrs,
						   const char         *name);
SOUP_AVAILABLE_IN_2_28
const char         *soup_message_headers_get_list (SoupMessageHeaders *hdrs,
						   const char         *name);
SOUP_AVAILABLE_IN_2_50
gboolean            soup_message_headers_header_contains (SoupMessageHeaders *hdrs,
							  const char         *name,
							  const char         *token);
SOUP_AVAILABLE_IN_2_50
gboolean            soup_message_headers_header_equals   (SoupMessageHeaders *hdrs,
							  const char         *name,
							  const char         *value);

typedef void      (*SoupMessageHeadersForeachFunc)(const char         *name,
						   const char         *value,
						   gpointer            user_data);

SOUP_AVAILABLE_IN_2_4
void                soup_message_headers_foreach  (SoupMessageHeaders *hdrs,
						   SoupMessageHeadersForeachFunc func,
						   gpointer            user_data);

SOUP_AVAILABLE_IN_2_50
SoupMessageHeadersType soup_message_headers_get_headers_type (SoupMessageHeaders *hdrs);

typedef struct {
	/*< private >*/
	gpointer dummy[3];
} SoupMessageHeadersIter;

SOUP_AVAILABLE_IN_2_4
void                soup_message_headers_iter_init (SoupMessageHeadersIter  *iter,
						    SoupMessageHeaders      *hdrs);
SOUP_AVAILABLE_IN_2_4
gboolean            soup_message_headers_iter_next (SoupMessageHeadersIter  *iter,
						    const char             **name,
						    const char             **value);

/* Specific headers */

typedef enum {
	SOUP_ENCODING_UNRECOGNIZED,
	SOUP_ENCODING_NONE,
	SOUP_ENCODING_CONTENT_LENGTH,
	SOUP_ENCODING_EOF,
	SOUP_ENCODING_CHUNKED,
	SOUP_ENCODING_BYTERANGES
} SoupEncoding;

SOUP_AVAILABLE_IN_2_4
SoupEncoding    soup_message_headers_get_encoding        (SoupMessageHeaders *hdrs);
SOUP_AVAILABLE_IN_2_4
void            soup_message_headers_set_encoding        (SoupMessageHeaders *hdrs,
							  SoupEncoding        encoding);

SOUP_AVAILABLE_IN_2_4
goffset         soup_message_headers_get_content_length  (SoupMessageHeaders *hdrs);
SOUP_AVAILABLE_IN_2_4
void            soup_message_headers_set_content_length  (SoupMessageHeaders *hdrs,
							  goffset             content_length);

typedef enum {
	SOUP_EXPECTATION_UNRECOGNIZED = (1 << 0),
	SOUP_EXPECTATION_CONTINUE     = (1 << 1)
} SoupExpectation;

SOUP_AVAILABLE_IN_2_4
SoupExpectation soup_message_headers_get_expectations    (SoupMessageHeaders *hdrs);
SOUP_AVAILABLE_IN_2_4
void            soup_message_headers_set_expectations    (SoupMessageHeaders *hdrs,
							  SoupExpectation     expectations);

typedef struct {
	goffset start;
	goffset end;
} SoupRange;

SOUP_AVAILABLE_IN_2_26
gboolean        soup_message_headers_get_ranges          (SoupMessageHeaders  *hdrs,
							  goffset              total_length,
							  SoupRange          **ranges,
							  int                 *length);
SOUP_AVAILABLE_IN_2_26
void            soup_message_headers_free_ranges         (SoupMessageHeaders  *hdrs,
							  SoupRange           *ranges);
SOUP_AVAILABLE_IN_2_26
void            soup_message_headers_set_ranges          (SoupMessageHeaders  *hdrs,
							  SoupRange           *ranges,
							  int                  length);
SOUP_AVAILABLE_IN_2_26
void            soup_message_headers_set_range           (SoupMessageHeaders  *hdrs,
							  goffset              start,
							  goffset              end);

SOUP_AVAILABLE_IN_2_26
gboolean        soup_message_headers_get_content_range   (SoupMessageHeaders  *hdrs,
							  goffset             *start,
							  goffset             *end,
							  goffset             *total_length);
SOUP_AVAILABLE_IN_2_26
void            soup_message_headers_set_content_range   (SoupMessageHeaders  *hdrs,
							  goffset              start,
							  goffset              end,
							  goffset              total_length);


SOUP_AVAILABLE_IN_2_26
const char *soup_message_headers_get_content_type     (SoupMessageHeaders  *hdrs,
						       GHashTable         **params);
SOUP_AVAILABLE_IN_2_26
void        soup_message_headers_set_content_type     (SoupMessageHeaders  *hdrs,
						       const char          *content_type,
						       GHashTable          *params);

SOUP_AVAILABLE_IN_2_26
gboolean soup_message_headers_get_content_disposition (SoupMessageHeaders  *hdrs,
						       char               **disposition,
						       GHashTable         **params);
SOUP_AVAILABLE_IN_2_26
void     soup_message_headers_set_content_disposition (SoupMessageHeaders  *hdrs,
						       const char          *disposition,
						       GHashTable          *params);

G_END_DECLS

#endif /* SOUP_MESSAGE_HEADERS_H */
