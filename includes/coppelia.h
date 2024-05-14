/*
** EPITECH PROJECT, 2023
** my_rpg.h
** File description:
** This is the main header file for the my_rpg project.
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "lib.h"
#include "params.h"
#include "struct.h"

// csfml functions :
sfRenderWindow *init_window(char const *window_name);
void manage_events(global_t *global);
void manage_keys(race_t *race);

// car functions :
void accelerate_car(race_t *race, float speed);
void move_car(race_t *race);
void turn_wheels(race_t *race, float angle);
void update_hitbox(race_t *race);

// rendering functions :
void render_all(global_t *global, race_t *race);

// lidar functions :
void print_lidar_data(float *lidar_data);
float *get_lidar(race_t *race);

// nn / sim functions :
void nn_control_car(race_t *race);

// informations functions :
bool is_pixel_grass(race_t *race, sfVector2f pos);

// init functions :
global_t *init_game(int nb_of_races);
race_t *init_race(sfVector2f race_origin, bool mutate);
car_t *init_car(sfVector2f race_origin);
