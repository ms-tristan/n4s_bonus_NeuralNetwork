/*
** EPITECH PROJECT, 2024
** bonus_n4s
** File description:
** car render
*/

#include "../includes/coppelia.h"

void render_car_hitbox(global_t *global)
{
    sfRectangleShape_setSize(global->hitbox, global->car->size);
    sfRectangleShape_setRotation(global->hitbox, global->car->direction);
    sfRectangleShape_setPosition(global->hitbox, global->car->pos);
    sfRectangleShape_setFillColor(global->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(global->hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(global->hitbox, 1);
    sfRenderWindow_drawRectangleShape(global->window, global->hitbox, NULL);
}

void render_car(global_t *global)
{
    sfSprite_setPosition(global->sprite, global->car->pos);
    sfSprite_setScale(global->sprite, (sfVector2f){CAR_SCALE, CAR_SCALE});
    sfSprite_setRotation(global->sprite, global->car->direction);
    sfSprite_setTexture(global->sprite, global->car->texture, sfTrue);
    sfRenderWindow_drawSprite(global->window, global->sprite, NULL);
    render_car_hitbox(global);
}

void render_map(global_t *global)
{
    sfSprite_setPosition(global->sprite, (sfVector2f){0, 0});
    sfSprite_setRotation(global->sprite, 0);
    sfSprite_setScale(global->sprite, (sfVector2f){1, 1});
    sfSprite_setTexture(global->sprite, global->map_texture, sfTrue);
    sfRenderWindow_drawSprite(global->window, global->sprite, NULL);
}

static void disp_lidar_line(global_t *global, sfVector2f source, float angle)
{
    float line_x = source.x + cos(angle * M_PI / 180) * 1500;
    float line_y = source.y + sin(angle * M_PI / 180) * 1500;
    sfVector2f line_end = {line_x, line_y};
    sfVertexArray *line = sfVertexArray_create();
    sfVertex vertex1 = {.position = source, .color = sfRed};
    sfVertex vertex2 = {.position = line_end, .color = sfRed};

    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);
    sfVertexArray_setPrimitiveType(line, sfLines);
    sfRenderWindow_drawVertexArray(global->window, line, NULL);
    sfVertexArray_destroy(line);
}

void render_lidar(global_t *global)
{
    sfVector2f car_pov = global->car->driver_sit;
    float car_orientation = global->car->direction;

    for (int i = 0; i < 9; i++) {
        disp_lidar_line(global, car_pov, car_orientation -
        40 + (20 * i) + 45);
    }
}

void render_all(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    render_map(global);
    render_car(global);
    render_lidar(global);
    sfRenderWindow_display(global->window);
}
