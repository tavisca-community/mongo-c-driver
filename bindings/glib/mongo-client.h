/* mongo-client.h
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

#ifndef MONGO_CLIENT_H
#define MONGO_CLIENT_H

#include <glib-object.h>

#include "mongo-uri.h"

G_BEGIN_DECLS

#define MONGO_TYPE_CLIENT            (mongo_client_get_type())
#define MONGO_CLIENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MONGO_TYPE_CLIENT, MongoClient))
#define MONGO_CLIENT_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), MONGO_TYPE_CLIENT, MongoClient const))
#define MONGO_CLIENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  MONGO_TYPE_CLIENT, MongoClientClass))
#define MONGO_IS_CLIENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MONGO_TYPE_CLIENT))
#define MONGO_IS_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  MONGO_TYPE_CLIENT))
#define MONGO_CLIENT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  MONGO_TYPE_CLIENT, MongoClientClass))

typedef struct _MongoClient        MongoClient;
typedef struct _MongoClientClass   MongoClientClass;
typedef struct _MongoClientPrivate MongoClientPrivate;

struct _MongoClient
{
   GObject parent;

   /*< private >*/
   MongoClientPrivate *priv;
};

struct _MongoClientClass
{
   GObjectClass parent_class;
};

GType        mongo_client_get_type     (void) G_GNUC_CONST;
MongoClient *mongo_client_new          (const gchar *uri_string);
MongoClient *mongo_client_new_from_uri (MongoUri    *uri);

G_END_DECLS

#endif /* MONGO_CLIENT_H */
