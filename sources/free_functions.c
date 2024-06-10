/*
** EPITECH PROJECT, 2024
** n4s_my_cop
** File description:
** free_functions
*/

#include "../includes/n4s.h"

void free_races(global_t *global, int nb_of_races)
{
    for (int i = 0; i < nb_of_races; i++) {
        manage_events(global);
        sfTexture_destroy(global->races[i]->car->texture);
        nn_free(&global->races[i]->nn);
        FREE(global->races[i]->car);
        sfImage_destroy(global->races[i]->map);
        FREE(global->races[i]);
    }
    FREE(global->races);
}

void free_global(global_t *global)
{
    sfRectangleShape_destroy(global->hitbox);
    sfSprite_destroy(global->sprite);
    sfTexture_destroy(global->map_texture);
    sfRenderWindow_destroy(global->window);
    sfView_destroy(global->view);
    FREE(global);
}
