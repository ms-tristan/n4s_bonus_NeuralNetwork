/*
** EPITECH PROJECT, 2024
** params.h
** File description:
** This header file contains parameters for the game.
*/

#pragma once

#include "coppelia.h"

//! macros:

// return ERROR_CODE when error met
#define ERROR_CODE 84

//! parameters:

// window parameters
#define X_SIZE 1920
#define Y_SIZE 1080
#define FRAMERATE_LIMIT 120

//! maths:

// pi
#define M_PI 3.14159265358979323846

//! car params:
// car scale
#define CAR_SCALE 0.2
// max wheels offset
#define MAX_WHEELS 2
// max speed
#define MAX_SPEED 0.6
// acceleration
#define ACCELERATION 0.04
// turn speed
#define TURN_SPEED 0.1
// origin
#define X_CAR_ORIGIN 200
#define Y_CAR_ORIGIN 300
#define CAR_ROTATION 0
#define MAP_FILEPATH "./assets/textures/scenes/1.png"

//! lidar params:
#define LIDAR_SIZE 11
#define LIDAR_OFFSET 15
#define LIDAR_GAP 15
#define LIDAR_IMPRECISION 10
#define LIDAR_DISTANCE 1000

//! simulation and nn params:
#define RACES_DURATION 600
#define MUTATION_RATE 0.05
#define MUTATION_STRENGTH 0.1
#define NB_OF_RACES 300
#define TRAINING_ITERATIONS 500
