/*
** EPITECH PROJECT, 2024
** n4s_my_cop
** File description:
** nn_move_car
*/

#include "../includes/n4S.h"
#include "../NN/nn_framework.h"

void lidar_to_nn(race_t *race)
{
    mat_t total_info = mat_init(1, race->nn.nodes[0].cols);
    int i = 0;

    for (; i < LIDAR_SIZE; i++)
        total_info.matrix[0][i] = race->lidar_data[i];
    total_info.matrix[0][i] = race->car->speed;
    total_info.matrix[0][i + 1] = race->car->wheels;
    nn_forward(&race->nn, &total_info);
    mat_free(&total_info);
}

void fix_max(car_t *car)
{
    if (car->speed > MAX_SPEED)
        car->speed = MAX_SPEED;
    else if (car->speed < -MAX_SPEED)
        car->speed = -MAX_SPEED;
    if (car->wheels > MAX_WHEELS)
        car->wheels = MAX_WHEELS;
    else if (car->wheels < -MAX_WHEELS)
        car->wheels = -MAX_WHEELS;
}

void nn_control_car(race_t *race)
{
    lidar_to_nn(race);
    race->car->wheels +=
    ((2 * race->nn.nodes[race->nn.arch_size - 1].matrix[0][0]) -
    (2 * race->nn.nodes[race->nn.arch_size - 1].matrix[0][1]));
    race->car->speed +=
    (2 * race->nn.nodes[race->nn.arch_size - 1].matrix[0][2]) -
    (2 * race->nn.nodes[race->nn.arch_size - 1].matrix[0][3]);
    fix_max(race->car);
}
