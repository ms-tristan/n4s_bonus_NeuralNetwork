/*
** EPITECH PROJECT, 2024
** bonus_n4s
** File description:
** lidar
*/

#include "../includes/coppelia.h"


void print_lidar_data(float *lidar_data)
{
    printf("Lidar data:");
    for (int i = 0; i < 9; i++) {
        printf(" %f", lidar_data[i]);
    }
    printf("\n");
}

float *get_lidar(global_t *global)
{
    if (!global)
        return NULL;
    return NULL;
}
