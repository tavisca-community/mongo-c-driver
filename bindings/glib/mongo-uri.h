/* mongo-uri.h
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

#ifndef MONGO_URI_H
#define MONGO_URI_H

#include <glib-object.h>

G_BEGIN_DECLS

#define MONGO_TYPE_URI (mongo_uri_get_type ())

typedef struct _MongoUri MongoUri;

GType     mongo_uri_get_type (void) G_GNUC_CONST;
MongoUri *mongo_uri_new      (void);
MongoUri *mongo_uri_ref      (MongoUri *uri);
void      mongo_uri_unref    (MongoUri *uri);

G_END_DECLS

#endif /* MONGO_URI_H */

