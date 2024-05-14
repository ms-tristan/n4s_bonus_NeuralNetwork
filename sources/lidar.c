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
    for (int i = 0; i < LIDAR_SIZE; i++) {
        printf(" %.2f", lidar_data[i]);
    }
    printf("\n");
}

static float get_lidar_line(race_t *race, sfVector2f source, float angle)
{
    float distance = 0;

    for (float i = 0; i < LIDAR_DISTANCE; i += LIDAR_IMPRECISION) {
        float x = source.x + cos(angle * M_PI / 180) * i;
        float y = source.y + sin(angle * M_PI / 180) * i;
        if (sfImage_getPixel(race->map, x, y).g > 150) {
            distance = i;
            break;
        }
    }
    return distance / 10;
}

float *get_lidar(race_t *race)
{
    float *lidar_data = malloc(sizeof(float) * LIDAR_SIZE);
    float car_orientation = race->car->direction + LIDAR_OFFSET;
    sfVector2f car_pov = race->car->driver_sit;

    if (is_pixel_grass(race, car_pov)) {
        for (int i = 0; i < LIDAR_SIZE; i++) {
            lidar_data[i] = 0;
        }
        return lidar_data;
    }
    for (int i = 0; i < LIDAR_SIZE; i++) {
        lidar_data[i] =
        get_lidar_line(race, car_pov, car_orientation + (LIDAR_GAP * i));
    }
    return lidar_data;
}
