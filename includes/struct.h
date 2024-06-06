/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** This header file contains all the structure definitions of the project.
*/

#pragma once

#include "n4s.h"
#include "../NN/nn_framework.h"

// CAR :
typedef struct car_s {
    sfTexture *texture;
    float wheels;
    float speed;
    float direction;
    sfVector2f size;
    sfVector2f pos;
    sfVector2f top_left;
    sfVector2f top_right;
    sfVector2f bottom_left;
    sfVector2f bottom_right;
    sfVector2f driver_sit;
} car_t;

// RACE :
typedef struct race_s {
    sfVector2f origin;
    nn_t nn;
    car_t *car;
    sfImage *map;
    float nn_fitness;
    float *lidar_data;
} race_t;

// GLOBAL :
typedef struct global_s {
    sfRectangleShape *hitbox;
    sfEvent events;
    race_t **races;
    sfSprite *sprite;
    sfRenderWindow *window;
    sfTexture *map_texture;
    sfView *view;
} global_t;
