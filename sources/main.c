/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** This is the best game ever made.
*/

#include "../includes/coppelia.h"
#include "../NN/nn_framework.h"

static int print_help_message(void)
{
    my_putstr("Better than CoppeliaSim\n");
    my_putstr("(ez)\n");
    return 0;
}

static void game_loop(global_t *global, race_t *race, int pos)
{
    manage_events(global);
    race->lidar_data = get_lidar(race);
    // manage_keys(race);
    nn_control_car(race);
    move_car(race);
    if (pos == 0)
        render_all(global, race);
    free(race->lidar_data);
}

void save_best_nn_fit(global_t *global, int nb_of_races)
{
    race_t *best_fit = global->races[0];

    for (int i = 0; i < nb_of_races; i++) {
        if (global->races[i]->nn_fitness > best_fit->nn_fitness)
            best_fit = global->races[i];
        printf("-- NN fit : %f\n", global->races[i]->nn_fitness);
    }
    printf("SAVED FITNESS : %f\n", best_fit->nn_fitness);
    nn_save(&best_fit->nn, "autopilot_save.nn");
}

void free_all(global_t *global, int nb_of_races)
{
    for (int i = 0; i < nb_of_races; i++) {
        sfTexture_destroy(global->races[i]->car->texture);
        nn_free(&global->races[i]->nn);
        free(global->races[i]->car);
        sfImage_destroy(global->races[i]->map);
        free(global->races[i]);
    }
    free(global->races);
    sfRectangleShape_destroy(global->hitbox);
    sfSprite_destroy(global->sprite);
    sfTexture_destroy(global->map_texture);
    sfRenderWindow_destroy(global->window);
    sfView_destroy(global->view);
}

static void launch_game(int iteration)
{
    int game_iterations = 0;
    global_t *global = init_game(NB_OF_RACES);

    printf("\t--%d ITERATIONS LEFT--\n", iteration);
    if (!global || !global->window)
        return;
    while (game_iterations < TRAINING_ITERATIONS &&
    sfRenderWindow_isOpen(global->window)) {
        for (int i = 0; i < NB_OF_RACES; i++)
            game_loop(global, global->races[i], i);
        game_iterations++;
        printf("%d\n", game_iterations);
    }
    save_best_nn_fit(global, NB_OF_RACES);
    free_all(global, NB_OF_RACES);
    if (iteration > 1)
        launch_game(iteration - 1);
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h"))
        return print_help_message();
    if (argc != 1)
        return 84;
    launch_game(NB_OF_TRAINING_ROUNDS);
    return 0;
}
