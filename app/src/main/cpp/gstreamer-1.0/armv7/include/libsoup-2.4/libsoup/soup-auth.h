/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2001-2003, Ximian, Inc.
 */

#ifndef SOUP_AUTH_H
#define SOUP_AUTH_H 1

#include <libsoup/soup-types.h>
#include <libsoup/soup-headers.h>

G_BEGIN_DECLS

#define SOUP_TYPE_AUTH            (soup_auth_get_type ())
#define SOUP_AUTH(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOUP_TYPE_AUTH, SoupAuth))
#define SOUP_AUTH_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), SOUP_TYPE_AUTH, SoupAuthClass))
#define SOUP_IS_AUTH(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOUP_TYPE_AUTH))
#define SOUP_IS_AUTH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((obj), SOUP_TYPE_AUTH))
#define SOUP_AUTH_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), SOUP_TYPE_AUTH, SoupAuthClass))

struct _SoupAuth {
	GObject parent;

	char *realm;
};

typedef struct {
	GObjectClass parent_class;

	const char  *scheme_name;
	guint        strength;

	gboolean     (*update)               (SoupAuth      *auth,
					      SoupMessage   *msg,
					      GHashTable    *auth_header);

	GSList *     (*get_protection_space) (SoupAuth      *auth,
					      SoupURI       *source_uri);

	void         (*authenticate)         (SoupAuth      *auth,
					      const char    *username,
					      const char    *password);
	gboolean     (*is_authenticated)     (SoupAuth      *auth);

	char *       (*get_authorization)    (SoupAuth      *auth,
					      SoupMessage   *msg);

	gboolean     (*is_ready)             (SoupAuth      *auth,
					      SoupMessage   *msg);

	gboolean     (*can_authenticate)     (SoupAuth      *auth);

	/* Padding for future expansion */
	void (*_libsoup_reserved3) (void);
	void (*_libsoup_reserved4) (void);
} SoupAuthClass;

#define SOUP_AUTH_SCHEME_NAME      "scheme-name"
#define SOUP_AUTH_REALM            "realm"
#define SOUP_AUTH_HOST             "host"
#define SOUP_AUTH_IS_FOR_PROXY     "is-for-proxy"
#define SOUP_AUTH_IS_AUTHENTICATED "is-authenticated"

SOUP_AVAILABLE_IN_2_4
GType       soup_auth_get_type              (void);

SOUP_AVAILABLE_IN_2_4
SoupAuth   *soup_auth_new                   (GType          type,
					     SoupMessage   *msg,
					     const char    *auth_header);
SOUP_AVAILABLE_IN_2_4
gboolean    soup_auth_update                (SoupAuth      *auth,
					     SoupMessage   *msg,
					     const char    *auth_header);

SOUP_AVAILABLE_IN_2_4
gboolean    soup_auth_is_for_proxy          (SoupAuth      *auth);
SOUP_AVAILABLE_IN_2_4
const char *soup_auth_get_scheme_name       (SoupAuth      *auth);
SOUP_AVAILABLE_IN_2_4
const char *soup_auth_get_host              (SoupAuth      *auth);
SOUP_AVAILABLE_IN_2_4
const char *soup_auth_get_realm             (SoupAuth      *auth);
SOUP_AVAILABLE_IN_2_4
char       *soup_auth_get_info              (SoupAuth      *auth);

SOUP_AVAILABLE_IN_2_4
void        soup_auth_authenticate          (SoupAuth      *auth,
					     const char    *username,
					     const char    *password);
SOUP_AVAILABLE_IN_2_4
gboolean    soup_auth_is_authenticated      (SoupAuth      *auth);
SOUP_AVAILABLE_IN_2_42
gboolean    soup_auth_is_ready              (SoupAuth      *auth,
					     SoupMessage   *msg);
SOUP_AVAILABLE_IN_2_54
gboolean    soup_auth_can_authenticate      (SoupAuth      *auth);

SOUP_AVAILABLE_IN_2_4
char       *soup_auth_get_authorization     (SoupAuth      *auth, 
					     SoupMessage   *msg);

SOUP_AVAILABLE_IN_2_4
GSList     *soup_auth_get_protection_space  (SoupAuth      *auth,
					     SoupURI       *source_uri);
SOUP_AVAILABLE_IN_2_4
void        soup_auth_free_protection_space (SoupAuth      *auth,
					     GSList        *space);

/* The actual auth types, which can be added/removed as features */

#define SOUP_TYPE_AUTH_BASIC  (soup_auth_basic_get_type ())
SOUP_AVAILABLE_IN_2_4
GType soup_auth_basic_get_type  (void);
#define SOUP_TYPE_AUTH_DIGEST (soup_auth_digest_get_type ())
SOUP_AVAILABLE_IN_2_4
GType soup_auth_digest_get_type (void);
#define SOUP_TYPE_AUTH_NTLM   (soup_auth_ntlm_get_type ())
SOUP_AVAILABLE_IN_2_4
GType soup_auth_ntlm_get_type   (void);
#define SOUP_TYPE_AUTH_NEGOTIATE  (soup_auth_negotiate_get_type ())
SOUP_AVAILABLE_IN_2_54
GType soup_auth_negotiate_get_type   (void);

/* Deprecated SoupPasswordManager-related APIs: all are now no-ops */
SOUP_AVAILABLE_IN_2_28
SOUP_DEPRECATED_IN_2_28
GSList     *soup_auth_get_saved_users    (SoupAuth   *auth);
SOUP_AVAILABLE_IN_2_28
SOUP_DEPRECATED_IN_2_28
const char *soup_auth_get_saved_password (SoupAuth   *auth,
					  const char *user);
SOUP_AVAILABLE_IN_2_28
SOUP_DEPRECATED_IN_2_28
void        soup_auth_save_password      (SoupAuth   *auth,
					  const char *username,
					  const char *password);
SOUP_AVAILABLE_IN_2_28
SOUP_DEPRECATED_IN_2_28
void        soup_auth_has_saved_password (SoupAuth   *auth,
					  const char *username,
					  const char *password);

SOUP_AVAILABLE_IN_2_54
gboolean    soup_auth_negotiate_supported   (void);

G_END_DECLS

#endif /* SOUP_AUTH_H */
