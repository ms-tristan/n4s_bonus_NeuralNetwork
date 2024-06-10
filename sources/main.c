/*
** EPITECH PROJECT, 2023
** Need4Stek
** File description:
** This is the best simulation ever made.
*/

#include "../includes/n4s.h"
#include "../NN/nn_framework.h"

static int print_help_message(void)
{
    my_putstr("Better than CoppeliaSim\n");
    my_putstr("(ez)\n");
    return 0;
}

// manage_keys(races[i]);
//? Add this to the game loop to control the car with the keys
//! This will affect the car's fitness
// so make sure to disable the nn_save_best_fit function
static void game_loop(global_t *global, race_t **races, int nb_of_races)
{
    for (int i = 0; i < nb_of_races; i++) {
        manage_events(global);
        races[i]->lidar_data = get_lidar(races[i]);
        nn_control_car(races[i]);
        move_car(races[i]);
        if (i == 0)
            render_race(global, races[i]);
        FREE(races[i]->lidar_data);
    }
}

static void launch_game(int nb_of_trainings, int nb_of_races, int races_len)
{
    global_t *global = init_csfml();

    if (!global || !global->window)
        return;
    while (sfRenderWindow_isOpen(global->window) && nb_of_trainings >= 0) {
        printf("\t--%d ITERATIONS LEFT--\n", nb_of_trainings);
        global->races = init_races(nb_of_races,
        MUTATION_RATE, MUTATION_STRENGTH);
        for (int i = 0; i < races_len; i++) {
            game_loop(global, global->races, nb_of_races);
            printf("%d\n", i);
        }
        nn_save_best_fits(global, nb_of_races, NB_OF_SAVES);
        free_races(global, nb_of_races);
        nb_of_trainings--;
    }
    free_global(global);
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h"))
        return print_help_message();
    launch_game(TRAINING_ITERATIONS, NB_OF_RACES, 800);
    return 0;
}
