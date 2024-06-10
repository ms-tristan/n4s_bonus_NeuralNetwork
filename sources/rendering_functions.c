/*
** EPITECH PROJECT, 2024
** bonus_n4s
** File description:
** car render
*/

#include "../includes/n4s.h"

void render_car_hitbox(global_t *global, race_t *race)
{
    sfRectangleShape_setSize(global->hitbox, race->car->size);
    sfRectangleShape_setRotation(global->hitbox, race->car->direction);
    sfRectangleShape_setPosition(global->hitbox, race->car->pos);
    sfRectangleShape_setFillColor(global->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(global->hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(global->hitbox, 1);
    sfRenderWindow_drawRectangleShape(global->window, global->hitbox, NULL);
}

void render_car(global_t *global, race_t *race)
{
    sfSprite_setPosition(global->sprite, race->car->pos);
    sfSprite_setScale(global->sprite, (sfVector2f){CAR_SCALE, CAR_SCALE});
    sfSprite_setRotation(global->sprite, race->car->direction);
    sfSprite_setTexture(global->sprite, race->car->texture, sfTrue);
    sfRenderWindow_drawSprite(global->window, global->sprite, NULL);
    render_car_hitbox(global, race);
}

void render_map(global_t *global, race_t *race)
{
    sfSprite_setPosition(global->sprite, race->origin);
    sfSprite_setRotation(global->sprite, 0);
    sfSprite_setScale(global->sprite, (sfVector2f){1, 1});
    sfSprite_setTexture(global->sprite, global->map_texture, sfTrue);
    sfRenderWindow_drawSprite(global->window, global->sprite, NULL);
}

static void disp_lidar_line(global_t *global, sfVector2f source, float angle)
{
    float line_x = source.x + cos(angle * M_PI / 180) * LIDAR_DISTANCE;
    float line_y = source.y + sin(angle * M_PI / 180) * LIDAR_DISTANCE;
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

void render_lidar(global_t *global, race_t *race)
{
    float car_orientation = race->car->direction + LIDAR_OFFSET;
    sfVector2f car_pov = race->car->driver_sit;

    for (int i = 0; i < 11; i++) {
        disp_lidar_line(global, car_pov, car_orientation + (LIDAR_GAP * i));
    }
}

void render_race(global_t *global, race_t *race)
{
    render_map(global, race);
    render_car(global, race);
    render_lidar(global, race);
    if (sfKeyboard_isKeyPressed(sfKeyN))
        draw_nn_on_window(global->window, &race->nn);
    sfRenderWindow_display(global->window);
}
