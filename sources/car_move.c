/*
** EPITECH PROJECT, 2024
** bonus_n4s
** File description:
** car_move
*/

#include "../includes/coppelia.h"

bool is_pixel_grass(race_t *race, sfVector2f pos)
{
    if (pos.x <= race->origin.x + 5 || pos.y <= race->origin.y + 5 || pos.x
    >= race->origin.x + X_SIZE - 5 || pos.y >= race->origin.y + Y_SIZE - 5) {
        return (true);
    }
    if (sfImage_getPixel(race->map, pos.x, pos.y).g > 150) {
        return (true);
    }
    return (false);
}

static bool is_car_on_grass(race_t *race)
{
    if (is_pixel_grass(race, race->car->top_left))
        return (true);
    if (is_pixel_grass(race, race->car->top_right))
        return (true);
    if (is_pixel_grass(race, race->car->bottom_left))
        return (true);
    if (is_pixel_grass(race, race->car->bottom_right))
        return (true);
    return (false);
}

void update_hitbox(race_t *race)
{
    sfVector2f pos = race->car->pos;
    sfVector2f size = race->car->size;
    float left_angle = race->car->direction;
    float front_angle = (left_angle + 90 >= 360) ? left_angle + 90 - 360 :
    left_angle + 90;

    race->car->top_left = pos;
    race->car->top_right = (sfVector2f){pos.x + cos(left_angle * M_PI / 180)
    * size.x, pos.y + sin(left_angle * M_PI / 180) * size.x};
    race->car->bottom_left = (sfVector2f){pos.x + cos(front_angle * M_PI /
    180) * size.y, pos.y + sin(front_angle * M_PI / 180) * size.y};
    race->car->bottom_right = (sfVector2f){race->car->top_right.x +
    cos(front_angle * M_PI / 180) * size.y, race->car->top_right.y +
    sin(front_angle * M_PI / 180) * size.y};
    race->car->driver_sit = (sfVector2f){(race->car->top_left.x +
    race->car->top_right.x + race->car->bottom_left.x +
    race->car->bottom_right.x) / 4, (race->car->top_left.y +
    race->car->top_right.y + race->car->bottom_left.y +
    race->car->bottom_right.y) / 4};
}

car_t copy_car(race_t *race)
{
    car_t car;

    car.pos = race->car->pos;
    car.speed = 0;
    car.direction = race->car->direction;
    car.wheels = race->car->wheels;
    car.size = race->car->size;
    car.top_left = race->car->top_left;
    car.top_right = race->car->top_right;
    car.bottom_left = race->car->bottom_left;
    car.bottom_right = race->car->bottom_right;
    car.driver_sit = race->car->driver_sit;
    car.texture = race->car->texture;
    return car;
}

void move_car(race_t *race)
{
    car_t rollback = copy_car(race);

    race->car->pos.y += 10 * race->car->speed *
    cos(race->car->direction * M_PI / 180);
    race->car->pos.x -= 10 * race->car->speed *
    sin(race->car->direction * M_PI / 180);
    update_hitbox(race);
    if (is_car_on_grass(race)) {
        *race->car = rollback;
        race->nn_fitness -= 0.5;
        return;
    } else
        race->car->speed *= 0.95;
    race->nn_fitness += 3 * race->car->speed;
    if (race->car->direction + race->car->wheels >= 360)
        race->car->direction -= 360;
    else if (race->car->direction + race->car->wheels < 0)
        race->car->direction += 360;
    race->car->direction += (4 * race->car->wheels) * race->car->speed;
    race->car->wheels *= 0.95;
}

void accelerate_car(race_t *race, float speed)
{
    if (race->car->speed + speed > MAX_SPEED) {
        race->car->speed = MAX_SPEED;
        return;
    } else if (race->car->speed + speed < -MAX_SPEED) {
        race->car->speed = -MAX_SPEED;
        return;
    }
    race->car->speed += speed;
}

void turn_wheels(race_t *race, float angle)
{
    if (race->car->wheels + angle > MAX_WHEELS) {
        race->car->wheels = MAX_WHEELS;
        return;
    } else if (race->car->wheels + angle < -MAX_WHEELS) {
        race->car->wheels = -MAX_WHEELS;
        return;
    }
    race->car->wheels += angle;
}
