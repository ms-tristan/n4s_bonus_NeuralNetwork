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
void manage_keys(global_t *global);

// car functions :
void accelerate_car(global_t *global, float speed);
void move_car(global_t *global);
void turn_wheels(global_t *global, float angle);

// rendering functions :
void render_all(global_t *global);

// lidar functions :
void print_lidar_data(float *lidar_data);
float *get_lidar(global_t *global);
