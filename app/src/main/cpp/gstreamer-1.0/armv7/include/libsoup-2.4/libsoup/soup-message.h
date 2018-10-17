/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2000-2003, Ximian, Inc.
 */

#ifndef SOUP_MESSAGE_H
#define SOUP_MESSAGE_H 1

#include <libsoup/soup-types.h>
#include <libsoup/soup-message-body.h>
#include <libsoup/soup-message-headers.h>
#include <libsoup/soup-method.h>

G_BEGIN_DECLS

#define SOUP_TYPE_MESSAGE            (soup_message_get_type ())
#define SOUP_MESSAGE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOUP_TYPE_MESSAGE, SoupMessage))
#define SOUP_MESSAGE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), SOUP_TYPE_MESSAGE, SoupMessageClass))
#define SOUP_IS_MESSAGE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOUP_TYPE_MESSAGE))
#define SOUP_IS_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((obj), SOUP_TYPE_MESSAGE))
#define SOUP_MESSAGE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), SOUP_TYPE_MESSAGE, SoupMessageClass))

struct _SoupMessage {
	GObject parent;

	/*< public >*/
	const char         *method;

	guint               status_code;
	char               *reason_phrase;

	SoupMessageBody    *request_body;
	SoupMessageHeaders *request_headers;

	SoupMessageBody    *response_body;
	SoupMessageHeaders *response_headers;
};

typedef struct {
	GObjectClass parent_class;

	/* signals */
	void     (*wrote_informational) (SoupMessage *msg);
	void     (*wrote_headers)       (SoupMessage *msg);
	void     (*wrote_chunk)         (SoupMessage *msg);
	void     (*wrote_body)          (SoupMessage *msg);
	void     (*got_informational)   (SoupMessage *msg);
	void     (*got_headers)         (SoupMessage *msg);
	void     (*got_chunk)           (SoupMessage *msg, SoupBuffer *chunk);
	void     (*got_body)            (SoupMessage *msg);
	void     (*restarted)           (SoupMessage *msg);
	void     (*finished)            (SoupMessage *msg);
	void     (*starting)            (SoupMessage *msg);

	/* Padding for future expansion */
	void (*_libsoup_reserved1) (void);
	void (*_libsoup_reserved2) (void);
	void (*_libsoup_reserved3) (void);
} SoupMessageClass;

SOUP_AVAILABLE_IN_2_4
GType soup_message_get_type (void);

#define SOUP_MESSAGE_METHOD             "method"
#define SOUP_MESSAGE_URI                "uri"
#define SOUP_MESSAGE_HTTP_VERSION       "http-version"
#define SOUP_MESSAGE_FLAGS              "flags"
#define SOUP_MESSAGE_SERVER_SIDE        "server-side"
#define SOUP_MESSAGE_STATUS_CODE        "status-code"
#define SOUP_MESSAGE_REASON_PHRASE      "reason-phrase"
#define SOUP_MESSAGE_FIRST_PARTY        "first-party"
#define SOUP_MESSAGE_REQUEST_BODY       "request-body"
#define SOUP_MESSAGE_REQUEST_BODY_DATA  "request-body-data"
#define SOUP_MESSAGE_REQUEST_HEADERS    "request-headers"
#define SOUP_MESSAGE_RESPONSE_BODY      "response-body"
#define SOUP_MESSAGE_RESPONSE_BODY_DATA "response-body-data"
#define SOUP_MESSAGE_RESPONSE_HEADERS   "response-headers"
#define SOUP_MESSAGE_TLS_CERTIFICATE    "tls-certificate"
#define SOUP_MESSAGE_TLS_ERRORS         "tls-errors"
#define SOUP_MESSAGE_PRIORITY           "priority"

SOUP_AVAILABLE_IN_2_4
SoupMessage   *soup_message_new                 (const char        *method,
						 const char        *uri_string);
SOUP_AVAILABLE_IN_2_4
SoupMessage   *soup_message_new_from_uri        (const char        *method,
						 SoupURI           *uri);

SOUP_AVAILABLE_IN_2_4
void           soup_message_set_request         (SoupMessage       *msg,
						 const char        *content_type,
						 SoupMemoryUse      req_use,
						 const char        *req_body,
						 gsize              req_length);
SOUP_AVAILABLE_IN_2_4
void           soup_message_set_response        (SoupMessage       *msg,
						 const char        *content_type,
						 SoupMemoryUse      resp_use,
						 const char        *resp_body,
						 gsize              resp_length);

typedef enum {
	SOUP_HTTP_1_0 = 0, /*< nick=http-1-0 >*/
	SOUP_HTTP_1_1 = 1  /*< nick=http-1-1 >*/
} SoupHTTPVersion;

SOUP_AVAILABLE_IN_2_4
void             soup_message_set_http_version    (SoupMessage       *msg,
						   SoupHTTPVersion    version);
SOUP_AVAILABLE_IN_2_4
SoupHTTPVersion  soup_message_get_http_version    (SoupMessage       *msg);

SOUP_AVAILABLE_IN_2_4
gboolean         soup_message_is_keepalive        (SoupMessage       *msg);

SOUP_AVAILABLE_IN_2_4
SoupURI         *soup_message_get_uri             (SoupMessage       *msg);
SOUP_AVAILABLE_IN_2_4
void             soup_message_set_uri             (SoupMessage       *msg,
						   SoupURI           *uri);
SOUP_AVAILABLE_IN_2_26
SoupAddress     *soup_message_get_address         (SoupMessage       *msg);

SOUP_AVAILABLE_IN_2_30
SoupURI         *soup_message_get_first_party     (SoupMessage       *msg);
SOUP_AVAILABLE_IN_2_30
void             soup_message_set_first_party     (SoupMessage       *msg,
						   SoupURI           *first_party);

typedef enum {
	SOUP_MESSAGE_NO_REDIRECT              = (1 << 1),
	SOUP_MESSAGE_CAN_REBUILD              = (1 << 2),
#ifndef SOUP_DISABLE_DEPRECATED
	SOUP_MESSAGE_OVERWRITE_CHUNKS         = (1 << 3),
#endif
	SOUP_MESSAGE_CONTENT_DECODED          = (1 << 4),
	SOUP_MESSAGE_CERTIFICATE_TRUSTED      = (1 << 5),
	SOUP_MESSAGE_NEW_CONNECTION           = (1 << 6),
	SOUP_MESSAGE_IDEMPOTENT               = (1 << 7),
	SOUP_MESSAGE_IGNORE_CONNECTION_LIMITS = (1 << 8),
	SOUP_MESSAGE_DO_NOT_USE_AUTH_CACHE    = (1 << 9)
} SoupMessageFlags;

SOUP_AVAILABLE_IN_2_4
void             soup_message_set_flags           (SoupMessage           *msg,
						   SoupMessageFlags       flags);

SOUP_AVAILABLE_IN_2_4
SoupMessageFlags soup_message_get_flags           (SoupMessage           *msg);

SOUP_AVAILABLE_IN_2_34
gboolean         soup_message_get_https_status    (SoupMessage           *msg,
						   GTlsCertificate      **certificate,
						   GTlsCertificateFlags  *errors);


/* Specialized signal handlers */
SOUP_AVAILABLE_IN_2_4
guint          soup_message_add_header_handler  (SoupMessage       *msg,
						 const char        *signal,
						 const char        *header,
						 GCallback          callback,
						 gpointer           user_data);

SOUP_AVAILABLE_IN_2_4
guint          soup_message_add_status_code_handler (
						 SoupMessage       *msg,
						 const char        *signal,
						 guint              status_code,
						 GCallback          callback,
						 gpointer           user_data);

/*
 * Status Setting
 */
SOUP_AVAILABLE_IN_2_4
void           soup_message_set_status          (SoupMessage       *msg, 
						 guint              status_code);

SOUP_AVAILABLE_IN_2_4
void           soup_message_set_status_full     (SoupMessage       *msg, 
						 guint              status_code, 
						 const char        *reason_phrase);

SOUP_AVAILABLE_IN_2_38
void           soup_message_set_redirect        (SoupMessage       *msg,
						 guint              status_code,
						 const char        *redirect_uri);

/* I/O */
#ifndef SOUP_DISABLE_DEPRECATED
typedef SoupBuffer * (*SoupChunkAllocator)      (SoupMessage       *msg,
						 gsize              max_len,
						 gpointer           user_data);

SOUP_AVAILABLE_IN_2_4
SOUP_DEPRECATED_IN_2_42_FOR(SoupRequest)
void           soup_message_set_chunk_allocator (SoupMessage       *msg,
						 SoupChunkAllocator allocator,
						 gpointer           user_data,
						 GDestroyNotify     destroy_notify);
#endif

SOUP_AVAILABLE_IN_2_28
void           soup_message_disable_feature     (SoupMessage       *msg,
						 GType              feature_type);

SOUP_AVAILABLE_IN_2_42
SoupRequest   *soup_message_get_soup_request    (SoupMessage       *msg);


typedef enum {
	SOUP_MESSAGE_PRIORITY_VERY_LOW = 0,
	SOUP_MESSAGE_PRIORITY_LOW,
	SOUP_MESSAGE_PRIORITY_NORMAL,
	SOUP_MESSAGE_PRIORITY_HIGH,
	SOUP_MESSAGE_PRIORITY_VERY_HIGH
} SoupMessagePriority;

SOUP_AVAILABLE_IN_2_44
void                soup_message_set_priority   (SoupMessage        *msg,
						 SoupMessagePriority priority);


SOUP_AVAILABLE_IN_2_44
SoupMessagePriority soup_message_get_priority   (SoupMessage        *msg);

SOUP_AVAILABLE_IN_2_4
void soup_message_wrote_informational (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_wrote_headers       (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_wrote_chunk         (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_wrote_body_data     (SoupMessage *msg, SoupBuffer *chunk);
SOUP_AVAILABLE_IN_2_4
void soup_message_wrote_body          (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_got_informational   (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_got_headers         (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_got_chunk           (SoupMessage *msg, SoupBuffer *chunk);
SOUP_AVAILABLE_IN_2_4
void soup_message_got_body            (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_content_sniffed     (SoupMessage *msg, const char *content_type, GHashTable *params);

SOUP_AVAILABLE_IN_2_50
void soup_message_starting            (SoupMessage *msg);

SOUP_AVAILABLE_IN_2_4
void soup_message_restarted           (SoupMessage *msg);
SOUP_AVAILABLE_IN_2_4
void soup_message_finished            (SoupMessage *msg);

G_END_DECLS

#endif /*SOUP_MESSAGE_H*/
