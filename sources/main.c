/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** This is the best game ever made.
*/

#include "../includes/coppelia.h"

static int print_help_message(void)
{
    my_putstr("Better than CoppeliaSim\n");
    my_putstr("ez\n");
    return 0;
}

static void game_loop(global_t *global)
{
    manage_events(global);
    manage_keys(global);
    move_car(global);
    get_lidar(global);
    render_all(global);
    get_lidar(global);
}

static global_t *init_game(void)
{
    global_t *global = malloc(sizeof(global_t));

    global->window = init_window("CoppeliaMieux");
    global->sprite = sfSprite_create();
    global->hitbox = sfRectangleShape_create();
    global->car = malloc(sizeof(car_t));
    global->car->texture = sfTexture_createFromFile
    ("./assets/textures/car.png", NULL);
    global->map = sfImage_createFromFile("./assets/textures/scenes/1.png");
    global->map_texture = sfTexture_createFromImage(global->map, NULL);
    global->car->size.x =
    (float)sfTexture_getSize(global->car->texture).x * CAR_SCALE;
    global->car->size.y =
    (float)sfTexture_getSize(global->car->texture).y * CAR_SCALE;
    global->car->pos.x = 200;
    global->car->pos.y = 300;
    global->car->speed = 0;
    global->car->direction = 0;
    global->car->wheels = 0;
    return global;
}

static int launch_game(void)
{
    global_t *global = init_game();

    if (!global->window)
        return 84;
    while (sfRenderWindow_isOpen(global->window)) {
        game_loop(global);
    }
    sfRenderWindow_close(global->window);
    sfRenderWindow_destroy(global->window);
    sfSprite_destroy(global->sprite);
    free(global);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h"))
        return print_help_message();
    if (argc != 1)
        return 84;
    return launch_game();
}
