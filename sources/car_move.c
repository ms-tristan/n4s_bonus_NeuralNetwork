/*
** EPITECH PROJECT, 2024
** bonus_n4s
** File description:
** car_move
*/

#include "../includes/coppelia.h"

bool is_pixel_grass(global_t *global, sfVector2f pos)
{
    if (sfImage_getPixel(global->map, pos.x,
    pos.y).g > 150)
        return (true);
    return (false);
}

static bool is_car_on_grass(global_t *global)
{
    if (is_pixel_grass(global, global->car->top_left))
        return (true);
    if (is_pixel_grass(global, global->car->top_right))
        return (true);
    if (is_pixel_grass(global, global->car->bottom_left))
        return (true);
    if (is_pixel_grass(global, global->car->bottom_right))
        return (true);
    return (false);
}

void update_hitbox(global_t *global)
{
    sfVector2f pos = global->car->pos;
    sfVector2f size = global->car->size;
    float left_angle = global->car->direction;
    float front_angle = (left_angle + 90 >= 360) ? left_angle + 90 - 360 :
    left_angle + 90;

    global->car->top_left = pos;
    global->car->top_right = (sfVector2f){pos.x + cos(left_angle * M_PI / 180)
    * size.x, pos.y + sin(left_angle * M_PI / 180) * size.x};
    global->car->bottom_left = (sfVector2f){pos.x + cos(front_angle * M_PI /
    180) * size.y, pos.y + sin(front_angle * M_PI / 180) * size.y};
    global->car->bottom_right = (sfVector2f){global->car->top_right.x +
    cos(front_angle * M_PI / 180) * size.y, global->car->top_right.y +
    sin(front_angle * M_PI / 180) * size.y};
    global->car->driver_sit = (sfVector2f){(global->car->top_left.x +
    global->car->top_right.x + global->car->bottom_left.x +
    global->car->bottom_right.x) / 4, (global->car->top_left.y +
    global->car->top_right.y + global->car->bottom_left.y +
    global->car->bottom_right.y) / 4};
}

void move_car(global_t *global)
{
    global->car->pos.y += 10 * global->car->speed *
    cos(global->car->direction * M_PI / 180);
    global->car->pos.x -= 10 * global->car->speed *
    sin(global->car->direction * M_PI / 180);
    update_hitbox(global);
    if (is_car_on_grass(global)) {
        global->car->speed *= 0.5;
    } else
        global->car->speed *= 0.95;
    if (global->car->direction + global->car->wheels >= 360)
        global->car->direction -= 360;
    else if (global->car->direction + global->car->wheels < 0)
        global->car->direction += 360;
    global->car->direction += (4 * global->car->wheels) * global->car->speed;
    global->car->wheels *= 0.95;
}

void accelerate_car(global_t *global, float speed)
{
    if (global->car->speed + speed > MAX_SPEED) {
        global->car->speed = MAX_SPEED;
        return;
    } else if (global->car->speed + speed < -MAX_SPEED) {
        global->car->speed = -MAX_SPEED;
        return;
    }
    global->car->speed += speed;
}

void turn_wheels(global_t *global, float angle)
{
    if (global->car->wheels + angle > MAX_WHEELS) {
        global->car->wheels = MAX_WHEELS;
        return;
    } else if (global->car->wheels + angle < -MAX_WHEELS) {
        global->car->wheels = -MAX_WHEELS;
        return;
    }
    global->car->wheels += angle;
}
