// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file Shape.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _Shape_H_
#define _Shape_H_

#include <string.h>
#include <stdlib.h>
#include <micrortps/client/client.h>
#include <microcdr/microcdr.h>

/*!
 * @brief This class represents the structure ShapeType defined by the user in the IDL file.
 * @ingroup SHAPE
 */
typedef struct ShapeType
{
    char* color;
    int32_t x;
    int32_t y;
    int32_t shapesize;
} ShapeType;

bool serialize_ShapeType_topic(MicroBuffer* writer, const AbstractTopic* topic_structure)
{
    ShapeType* topic = (ShapeType*) topic_structure->topic;
    serialize_uint32_t(writer, strlen(topic->color) + 1);
    serialize_array_char(writer, topic->color, strlen(topic->color) + 1);
    serialize_int32_t(writer, topic->x);
    serialize_int32_t(writer, topic->y);
    serialize_int32_t(writer, topic->shapesize);

    return true;
}

ShapeType *deserialize_ShapeType_message(MicroBuffer *message)
{
    ShapeType* topic = malloc(sizeof(ShapeType));
    uint32_t size_color = 0;
    deserialize_uint32_t(message, &size_color);
    topic->color = malloc(size_color);
    deserialize_array_char(message, topic->color, size_color);
    deserialize_int32_t(message, &topic->x);
    deserialize_int32_t(message, &topic->y);
    deserialize_int32_t(message, &topic->shapesize);

    return topic;
}

void deallocate_ShapeType_topic(ShapeType *topic)
{
    free(topic->color);
    free(topic);
}

#endif // _Shape_H_