/*
** EPITECH PROJECT, 2024
** n4s_bonus_NeuralNetwork
** File description:
** nn_display
*/

//! make sure to add the CSFML library to the compilation

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include "nn_framework.h"

//? remap values between 0 and 255
int remap(float value)
{
    float squashed_value = tanh(value);
    int remapped_value = (int)((squashed_value + 1) / 2 * 255);

    return remapped_value;
}

// (sfColor){0, 100, remap(nn->weights[i - 1].matrix[k][j]), 255}
void draw_weights(sfRenderWindow *window, nn_t *nn)
{
    sfVertexArray *line = sfVertexArray_create();
    sfVertex vertex1;
    sfVertex vertex2;
    sfVector2f pos = {50, 50};

    for (int i = 1; i < nn->arch_size; i++) {
        for (int j = 0; j < nn->nodes[i].cols; j++) {
            pos.x = 75 + (i * 100);
            pos.y = 75 + (j * 50);
            for (int k = 0; k < nn->nodes[i - 1].cols; k++) {
                sfVertexArray_setPrimitiveType(line, sfLines);
                vertex1 = (sfVertex){{75 + ((i - 1) * 100), 75 + (k * 50)},
                (sfColor){remap(nn->nodes[i - 1].matrix[0][k]), 0, remap(nn->weights[i - 1].matrix[k][j]), 255}, {0, 0}};
                vertex2 = (sfVertex){pos,
                (sfColor){remap(nn->nodes[i - 1].matrix[0][j]), 0, remap(nn->weights[i - 1].matrix[k][j]), 255}, {0, 0}};
                sfVertexArray_append(line, vertex1);
                sfVertexArray_append(line, vertex2);
                sfRenderWindow_drawVertexArray(window, line, NULL);
            }
        }
    }
    sfVertexArray_destroy(line);
}

void draw_nn_on_window(sfRenderWindow *window, nn_t *nn)
{
    sfVector2f pos = {50, 50};
    sfCircleShape *circle = sfCircleShape_create();

    draw_weights(window, nn);
    for (int i = 0; i < nn->arch_size; i++) {
        for (int j = 0; j < nn->nodes[i].cols; j++) {
            pos.x = 50 + (i * 100);
            pos.y = 50 + (j * 50);
            sfCircleShape_setRadius(circle, 20);
            sfCircleShape_setPosition(circle, pos);
            sfCircleShape_setFillColor(circle, (sfColor){(int)nn->nodes[i].matrix[0][j] * 10, 0, 0, 255});
            if (i > 0)
                sfCircleShape_setFillColor(circle, (sfColor){(int)nn->nodes[i].matrix[0][j] * 180, 0, 0, 255});
            sfRenderWindow_drawCircleShape(window, circle, NULL);
            if (i > 0) {
                sfCircleShape_setFillColor(circle,
                (sfColor){0, 0, remap(nn->bias[i - 1].matrix[0][j]), 255});
                sfCircleShape_setRadius(circle, 10);
                sfCircleShape_setPosition(circle, pos);
                sfRenderWindow_drawCircleShape(window, circle, NULL);
            }
        }
    }
    sfCircleShape_destroy(circle);
}