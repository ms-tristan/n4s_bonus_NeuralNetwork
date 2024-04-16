/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** This header file contains all the structure definitions of the project.
*/

#pragma once

#include "coppelia.h"

// CAR :
typedef struct car_s {
    sfTexture *texture;
    float wheels; // from -1 to 1
    float speed; // from -1 to 1
    float direction; // in degrees
    sfVector2f size;
    sfVector2f pos;
    sfVector2f top_left;
    sfVector2f top_right;
    sfVector2f bottom_left;
    sfVector2f bottom_right;
    sfVector2f driver_sit;
} car_t;

// GLOBAL :
typedef struct global_s {
    sfRenderWindow *window;
    sfEvent events;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    car_t *car;
    float *lidar_data;
    sfImage *map;
    sfTexture *map_texture;
} global_t;
