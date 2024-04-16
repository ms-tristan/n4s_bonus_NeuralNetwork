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
#define FRAMERATE_LIMIT 60


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
#define ACCELERATION 0.1
// turn speed
#define TURN_SPEED 0.1
