/* mongo-client.c
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

#include <glib/gi18n.h>

#include "mongo-client.h"

struct _MongoClientPrivate
{
   mongoc_client_t *client;
};

enum
{
   PROP_0,
   LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

G_DEFINE_TYPE_WITH_CODE (MongoClient,
                         mongo_client,
                         G_TYPE_OBJECT,
                         G_ADD_PRIVATE (MongoClient))

static void
mongo_client_finalize (GObject *object)
{
   MongoClientPrivate *priv;

   priv = MONGO_CLIENT (object)->priv;

   mongoc_client_destroy (priv->client);
   priv->client = NULL;

   G_OBJECT_CLASS (mongo_client_parent_class)->finalize (object);
}

static void
mongo_client_get_property (GObject    *object,
                           guint       prop_id,
                           GValue     *value,
                           GParamSpec *pspec)
{
#if 0
   MongoClient *client = MONGO_CLIENT (object);
#endif

   switch (prop_id) {
   default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
   }
}

static void
mongo_client_set_property (GObject      *object,
                           guint         prop_id,
                           const GValue *value,
                           GParamSpec   *pspec)
{
#if 0
   MongoClient *client = MONGO_CLIENT (object);
#endif

   switch (prop_id) {
   default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
   }
}

static void
mongo_client_class_init (MongoClientClass *klass)
{
   GObjectClass *object_class;

   object_class = G_OBJECT_CLASS(klass);
   object_class->finalize = mongo_client_finalize;
   object_class->get_property = mongo_client_get_property;
   object_class->set_property = mongo_client_set_property;
}

static void
mongo_client_init (MongoClient *client)
{
   client->priv = mongo_client_get_instance_private (client);
}
