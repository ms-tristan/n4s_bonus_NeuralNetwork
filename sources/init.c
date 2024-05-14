/*
** EPITECH PROJECT, 2024
** n4s_my_cop
** File description:
** init
*/

#include "../includes/coppelia.h"

car_t *init_car(sfVector2f race_origin)
{
    car_t *car = ALLOC(sizeof(car_t));

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

race_t *init_race(float mutation_rate, float mutation_strength)
{
    race_t *new_race = ALLOC(sizeof(race_t));

    new_race->nn_fitness = 0;
    new_race->nn = nn_open("nn_saves/autopilot_save.nn");
    nn_mutate(&new_race->nn, mutation_rate, mutation_strength);
    new_race->origin = (sfVector2f){0, 0};
    new_race->car = init_car(new_race->origin);
    new_race->map = sfImage_createFromFile(MAP_FILEPATH);
    return new_race;
}

race_t **init_races(global_t *global, int nb_of_races, float mutation_rate,
    float mutation_strength)
{
    race_t **races = ALLOC(sizeof(global_t *) * nb_of_races);

    races[0] = init_race(0, 0);
    for (int i = 1; i < nb_of_races / 4; i++) {
        manage_events(global);
        races[i] = init_race(mutation_rate, mutation_strength);
    }
    for (int i = nb_of_races / 4; i < nb_of_races / 2; i++) {
        manage_events(global);
        races[i] = init_race(1, 0.5);
    }
    for (int i = nb_of_races / 2; i < nb_of_races / 1.5; i++) {
        manage_events(global);
        races[i] = init_race(i / nb_of_races, 1 / i);
    }
    for (int i = nb_of_races / 1.5; i < nb_of_races; i++) {
        manage_events(global);
        races[i] = init_race(i / nb_of_races, 1 / i);
    }
    return races;
}

global_t *init_csfml(void)
{
    global_t *global = ALLOC(sizeof(global_t));

    global->view = sfView_createFromRect((sfFloatRect){0, 0,
    X_SIZE, Y_SIZE});
    global->window = init_window("n4s");
    global->sprite = sfSprite_create();
    global->hitbox = sfRectangleShape_create();
    global->map_texture = sfTexture_createFromFile
    (MAP_FILEPATH, NULL);
    if (!global->map_texture)
        global->map_texture = sfTexture_create(100, 100);
    sfRenderWindow_setView(global->window, global->view);
    return global;
}
