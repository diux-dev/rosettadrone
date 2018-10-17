/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2007 Red Hat, Inc.
 */

#ifndef SOUP_AUTH_MANAGER_H
#define SOUP_AUTH_MANAGER_H 1

#include "soup-types.h"
#include "soup-auth.h"

G_BEGIN_DECLS

#define SOUP_TYPE_AUTH_MANAGER            (soup_auth_manager_get_type ())
#define SOUP_AUTH_MANAGER(object)         (G_TYPE_CHECK_INSTANCE_CAST ((object), SOUP_TYPE_AUTH_MANAGER, SoupAuthManager))
#define SOUP_AUTH_MANAGER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), SOUP_TYPE_AUTH_MANAGER, SoupAuthManagerClass))
#define SOUP_IS_AUTH_MANAGER(object)      (G_TYPE_CHECK_INSTANCE_TYPE ((object), SOUP_TYPE_AUTH_MANAGER))
#define SOUP_IS_AUTH_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOUP_TYPE_AUTH_MANAGER))
#define SOUP_AUTH_MANAGER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), SOUP_TYPE_AUTH_MANAGER, SoupAuthManagerClass))

typedef struct SoupAuthManagerPrivate SoupAuthManagerPrivate;

typedef struct {
	GObject parent;

	SoupAuthManagerPrivate *priv;
} SoupAuthManager;

typedef struct {
	GObjectClass parent_class;

	void (*authenticate) (SoupAuthManager *manager, SoupMessage *msg,
			      SoupAuth *auth, gboolean retrying);
} SoupAuthManagerClass;

SOUP_AVAILABLE_IN_2_4
GType soup_auth_manager_get_type (void);

SOUP_AVAILABLE_IN_2_4
void  soup_auth_manager_use_auth (SoupAuthManager *manager,
				  SoupURI         *uri,
				  SoupAuth        *auth);

SOUP_AVAILABLE_IN_2_58
void soup_auth_manager_clear_cached_credentials (SoupAuthManager *manager);

G_END_DECLS

#endif /* SOUP_AUTH_MANAGER_H */
