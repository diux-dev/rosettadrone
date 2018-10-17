/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/* 
 * Copyright 1999-2002 Ximian, Inc.
 */


#ifndef  SOUP_URI_H
#define  SOUP_URI_H 1

#include <libsoup/soup-types.h>
#include <libsoup/soup-misc.h>

G_BEGIN_DECLS

struct _SoupURI {
	const char *scheme;

	char       *user;
	char       *password;

	char       *host;
	guint       port;

	char       *path;
	char       *query;

	char       *fragment;
};

SOUP_AVAILABLE_IN_2_4
GType       soup_uri_get_type              (void);
#define SOUP_TYPE_URI (soup_uri_get_type ())

#define SOUP_URI_SCHEME_HTTP     _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_HTTP, "http")
#define SOUP_URI_SCHEME_HTTPS    _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_HTTPS, "https")
#define SOUP_URI_SCHEME_FTP      _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_FTP, "ftp")
#define SOUP_URI_SCHEME_FILE     _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_FILE, "file")
#define SOUP_URI_SCHEME_DATA     _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_DATA, "data")
#define SOUP_URI_SCHEME_RESOURCE _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_RESOURCE, "resource")
#define SOUP_URI_SCHEME_WS       _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_WS, "ws")
#define SOUP_URI_SCHEME_WSS      _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_WSS, "wss")

SOUP_VAR gpointer _SOUP_URI_SCHEME_HTTP, _SOUP_URI_SCHEME_HTTPS;
SOUP_VAR gpointer _SOUP_URI_SCHEME_FTP;
SOUP_VAR gpointer _SOUP_URI_SCHEME_FILE, _SOUP_URI_SCHEME_DATA, _SOUP_URI_SCHEME_RESOURCE;
SOUP_VAR gpointer _SOUP_URI_SCHEME_WS, _SOUP_URI_SCHEME_WSS;

SOUP_AVAILABLE_IN_2_4
SoupURI	   *soup_uri_new_with_base         (SoupURI    *base,
					    const char *uri_string);
SOUP_AVAILABLE_IN_2_4
SoupURI	   *soup_uri_new                   (const char *uri_string);

SOUP_AVAILABLE_IN_2_4
char   	   *soup_uri_to_string             (SoupURI    *uri,
					    gboolean    just_path_and_query);

SOUP_AVAILABLE_IN_2_4
SoupURI	   *soup_uri_copy                  (SoupURI    *uri);

SOUP_AVAILABLE_IN_2_4
gboolean    soup_uri_equal                 (SoupURI    *uri1,
					    SoupURI    *uri2);

SOUP_AVAILABLE_IN_2_4
void  	    soup_uri_free                  (SoupURI    *uri);

SOUP_AVAILABLE_IN_2_4
char  	   *soup_uri_encode                (const char *part,
					    const char *escape_extra);
SOUP_AVAILABLE_IN_2_4
char  	   *soup_uri_decode                (const char *part);
SOUP_AVAILABLE_IN_2_4
char  	   *soup_uri_normalize             (const char *part,
					    const char *unescape_extra);

SOUP_AVAILABLE_IN_2_4
gboolean    soup_uri_uses_default_port     (SoupURI    *uri);

SOUP_AVAILABLE_IN_2_32
const char *soup_uri_get_scheme            (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_scheme            (SoupURI    *uri,
					    const char *scheme);
SOUP_AVAILABLE_IN_2_32
const char *soup_uri_get_user              (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_user              (SoupURI    *uri,
					    const char *user);
SOUP_AVAILABLE_IN_2_32
const char *soup_uri_get_password          (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_password          (SoupURI    *uri,
					    const char *password);
SOUP_AVAILABLE_IN_2_32
const char *soup_uri_get_host              (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_host              (SoupURI    *uri,
					    const char *host);
SOUP_AVAILABLE_IN_2_32
guint       soup_uri_get_port              (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_port              (SoupURI    *uri,
					    guint       port);
SOUP_AVAILABLE_IN_2_32
const char *soup_uri_get_path              (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_path              (SoupURI    *uri,
					    const char *path);
SOUP_AVAILABLE_IN_2_32
const char *soup_uri_get_query             (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_query             (SoupURI    *uri,
					    const char *query);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_query_from_form   (SoupURI    *uri,
					    GHashTable *form);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_query_from_fields (SoupURI    *uri,
					    const char *first_field,
					    ...) G_GNUC_NULL_TERMINATED;
SOUP_AVAILABLE_IN_2_32
const char *soup_uri_get_fragment          (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_4
void        soup_uri_set_fragment          (SoupURI    *uri,
					    const char *fragment);

SOUP_AVAILABLE_IN_2_28
SoupURI    *soup_uri_copy_host             (SoupURI    *uri);
SOUP_AVAILABLE_IN_2_28
guint       soup_uri_host_hash             (gconstpointer key);
SOUP_AVAILABLE_IN_2_28
gboolean    soup_uri_host_equal            (gconstpointer v1,
					    gconstpointer v2);

#define   SOUP_URI_IS_VALID(uri)       ((uri) && (uri)->scheme && (uri)->path)
#define   SOUP_URI_VALID_FOR_HTTP(uri) ((uri) && ((uri)->scheme == SOUP_URI_SCHEME_HTTP || (uri)->scheme == SOUP_URI_SCHEME_HTTPS) && (uri)->host && (uri)->path)

G_END_DECLS

#endif /*SOUP_URI_H*/
