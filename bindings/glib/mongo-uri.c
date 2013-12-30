/* mongo-uri.c
 *
 * Copyright (C) 2013 MongoDB, Inc.
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mongoc.h>

#include "mongo-uri.h"

struct _MongoUri
{
   volatile gint  ref_count;
   mongoc_uri_t  *uri;
};

static void
mongo_uri_dispose (MongoUri *uri)
{
   mongoc_uri_destroy (uri->uri);
}

MongoUri *
mongo_uri_new (const char *uri_string);
{
   MongoUri *uri;

   uri = g_slice_new0 (MongoUri);
   uri->ref_count = 1;
   uri->uri = mongoc_uri_new (uri_string);

   return uri;
}

MongoUri *
mongo_uri_ref (MongoUri *uri)
{
   g_return_val_if_fail (uri != NULL, NULL);
   g_return_val_if_fail (uri->ref_count > 0, NULL);

   g_atomic_int_inc (&uri->ref_count);

   return uri;
}

void
mongo_uri_unref (MongoUri *uri)
{
   g_return_if_fail (uri != NULL);
   g_return_if_fail (uri->ref_count > 0);

   if (g_atomic_int_dec_and_test (&uri->ref_count)) {
      mongo_uri_dispose (uri);
      g_slice_free (MongoUri, uri);
   }
}
