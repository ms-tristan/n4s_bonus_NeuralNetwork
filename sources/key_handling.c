/*
** EPITECH PROJECT, 2024
** bonus_n4s
** File description:
** key_management
*/

#include "../includes/n4s.h"

void manage_keys(race_t *race)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        turn_wheels(race, -TURN_SPEED);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        turn_wheels(race, TURN_SPEED);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        accelerate_car(race, ACCELERATION);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        accelerate_car(race, -ACCELERATION);
}
