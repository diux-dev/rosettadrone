/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2005 Novell, Inc.
 * Copyright (C) 2007 Red Hat, Inc.
 */

#ifndef SOUP_DATE_H
#define SOUP_DATE_H 1

#include <time.h>
#include <libsoup/soup-types.h>

G_BEGIN_DECLS

struct _SoupDate {
	int      year;
	int      month;
	int      day;

	int      hour;
	int      minute;
	int      second;

	gboolean utc;
	int      offset;
};

typedef enum {
	SOUP_DATE_HTTP = 1,
	SOUP_DATE_COOKIE,
	SOUP_DATE_RFC2822,
	SOUP_DATE_ISO8601_COMPACT,
	SOUP_DATE_ISO8601_FULL,
	SOUP_DATE_ISO8601 = SOUP_DATE_ISO8601_FULL,
	SOUP_DATE_ISO8601_XMLRPC
} SoupDateFormat;

SOUP_AVAILABLE_IN_2_24
GType soup_date_get_type (void);
#define SOUP_TYPE_DATE (soup_date_get_type ())

SOUP_AVAILABLE_IN_2_24
SoupDate *soup_date_new             (int             year,
				     int             month,
				     int             day, 
				     int             hour,
				     int             minute,
				     int             second);
SOUP_AVAILABLE_IN_2_24
SoupDate *soup_date_new_from_string (const char     *date_string);
SOUP_AVAILABLE_IN_2_24
SoupDate *soup_date_new_from_time_t (time_t          when);
SOUP_AVAILABLE_IN_2_24
SoupDate *soup_date_new_from_now    (int             offset_seconds);

SOUP_AVAILABLE_IN_2_24
char     *soup_date_to_string       (SoupDate       *date,
				     SoupDateFormat  format);
SOUP_AVAILABLE_IN_2_24
time_t    soup_date_to_time_t       (SoupDate       *date);
SOUP_AVAILABLE_IN_2_24
void      soup_date_to_timeval      (SoupDate       *date,
				     GTimeVal       *time);

SOUP_AVAILABLE_IN_2_24
gboolean  soup_date_is_past         (SoupDate       *date);

SOUP_AVAILABLE_IN_2_32
int       soup_date_get_year        (SoupDate       *date);
SOUP_AVAILABLE_IN_2_32
int       soup_date_get_month       (SoupDate       *date);
SOUP_AVAILABLE_IN_2_32
int       soup_date_get_day         (SoupDate       *date);
SOUP_AVAILABLE_IN_2_32
int       soup_date_get_hour        (SoupDate       *date);
SOUP_AVAILABLE_IN_2_32
int       soup_date_get_minute      (SoupDate       *date);
SOUP_AVAILABLE_IN_2_32
int       soup_date_get_second      (SoupDate       *date);
SOUP_AVAILABLE_IN_2_32
int       soup_date_get_utc         (SoupDate       *date);
SOUP_AVAILABLE_IN_2_32
int       soup_date_get_offset      (SoupDate       *date);

SOUP_AVAILABLE_IN_2_24
SoupDate *soup_date_copy            (SoupDate       *date);
SOUP_AVAILABLE_IN_2_24
void      soup_date_free            (SoupDate       *date);

G_END_DECLS

#endif /* SOUP_DATE_H */
