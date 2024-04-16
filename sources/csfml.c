/*
** EPITECH PROJECT, 2024
** csfml.c
** File description:
** Theses functions manage basic csfml features
** (such as creating a new window).
*/

#include "../includes/coppelia.h"

void manage_events(global_t *global)
{
    if (!global || !global->window)
        return;
    while (sfRenderWindow_pollEvent(global->window, &global->events)) {
        if (global->events.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
    }
}

sfRenderWindow *init_window(char const *window_name)
{
    sfVideoMode mode = {X_SIZE, Y_SIZE, 4};
    sfRenderWindow *window = sfRenderWindow_create(mode, window_name,
    sfClose | sfResize, NULL);

    sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
    if (!window)
        return NULL;
    return window;
}
