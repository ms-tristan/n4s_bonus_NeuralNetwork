/*
** EPITECH PROJECT, 2024
** n4s_my_cop
** File description:
** save_races
*/

#include "../includes/coppelia.h"

static int find_min_index_in_array(race_t **array, int array_size)
{
    int min_index = 0;

    for (int i = 0; i < array_size; i++) {
        if (array[i]->nn_fitness < array[min_index]->nn_fitness)
            min_index = i;
    }
    return min_index;
}

race_t **find_top_n_agents(race_t **races, int nb_of_races, int n)
{
    race_t **bests = ALLOC(sizeof(race_t *) * n);
    int min_index = 0;

    for (int i = 0; i < n; i++)
        bests[i] = races[i];
    for (int i = n; i < nb_of_races; i++) {
        min_index = find_min_index_in_array(bests, n);
        if (races[i]->nn_fitness > bests[min_index]->nn_fitness) {
            bests[min_index] = races[i];
        }
    }
    return bests;
}

void nn_save_best_fits(global_t *global, int nb_of_races, int nb_of_saves)
{
    race_t **bests = NULL;
    char file_name[50];

    if (nb_of_saves > nb_of_races)
        return;
    bests = find_top_n_agents(global->races, nb_of_races, nb_of_saves);
    for (int i = 0; i < nb_of_saves; i++) {
        sprintf(file_name, "nn_saves/autopilot_save_%d.nn", i);
        nn_save(&bests[i]->nn, file_name);
        printf("SAVED FITNESS : %f\n", bests[i]->nn_fitness);
    }
    FREE(bests);
}
