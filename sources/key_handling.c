/*
** EPITECH PROJECT, 2024
** bonus_n4s
** File description:
** key_management
*/

#include "../includes/coppelia.h"

void manage_keys(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        turn_wheels(global, -TURN_SPEED);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        turn_wheels(global, TURN_SPEED);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        accelerate_car(global, ACCELERATION);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        accelerate_car(global, -ACCELERATION);
}
