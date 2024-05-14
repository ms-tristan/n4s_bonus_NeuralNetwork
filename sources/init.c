/*
** EPITECH PROJECT, 2024
** n4s_my_cop
** File description:
** init
*/

#include "../includes/coppelia.h"

car_t *init_car(sfVector2f race_origin)
{
    car_t *car = malloc(sizeof(car_t));

    car->texture = sfTexture_createFromFile
    ("./assets/textures/car.png", NULL);
    if (!car->texture)
        car->texture = sfTexture_create(100, 100);
    car->size.x =
    (float)sfTexture_getSize(car->texture).x * CAR_SCALE;
    car->size.y =
    (float)sfTexture_getSize(car->texture).y * CAR_SCALE;
    car->pos.x = X_CAR_ORIGIN + race_origin.x;
    car->pos.y = Y_CAR_ORIGIN + race_origin.y;
    car->speed = 0;
    car->direction = CAR_ROTATION;
    car->wheels = 0;
    return car;
}

race_t *init_race(sfVector2f race_origin, bool mutate)
{
    race_t *new_race = malloc(sizeof(race_t));

    new_race->nn_fitness = 0;
    new_race->nn = nn_open("autopilot_save.nn");
    if (mutate)
        nn_mutate(&new_race->nn, MUTATION_RATE);
    new_race->car = init_car(race_origin);
    new_race->origin = race_origin;
    new_race->map = sfImage_createFromFile(MAP_FILEPATH);
    return new_race;
}

global_t *init_game(int nb_of_races)
{
    global_t *global = malloc(sizeof(global_t));
    sfVector2f origin = {0, 0};

    global->races = malloc(sizeof(global_t *) * nb_of_races);
    global->races[0] = init_race(origin, false);
    for (int i = 1; i < nb_of_races; i++) {
        origin.x = X_SIZE * i;
        global->races[i] = init_race(origin, true);
    }
    global->view = sfView_createFromRect((sfFloatRect){0, 0,
    X_SIZE, Y_SIZE});
    global->window = init_window("CoppeliaMieux");
    global->sprite = sfSprite_create();
    global->hitbox = sfRectangleShape_create();
    global->map_texture = sfTexture_createFromFile
    (MAP_FILEPATH, NULL);
    if (!global->map_texture)
        global->map_texture = sfTexture_create(100, 100);
    sfRenderWindow_setView(global->window, global->view);
    return global;
}
