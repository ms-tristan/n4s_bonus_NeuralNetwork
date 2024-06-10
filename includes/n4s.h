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

// rendering functions :
void render_race(global_t *global, race_t *race);

// lidar functions :
void print_lidar_data(float *lidar_data);
float *get_lidar(race_t *race);

// nn / sim functions :
void nn_control_car(race_t *race);
void nn_save_best_fits(global_t *global, int nb_of_races, int nb_of_saves);

// informations functions :
bool is_pixel_grass(race_t *race, sfVector2f pos);

// init functions :
global_t *init_csfml(void);
race_t *init_race(float mutation_rate, float mutation_strength, char *model);
race_t **init_races(int nb_of_races, float mutation_rate,
    float mutation_strength);
car_t *init_car(sfVector2f race_origin);
void randomize_nns(bool randomize, int i, race_t **races, int nb_of_races);

// free functions :
void free_races(global_t *global, int nb_of_races);
void free_global(global_t *global);
