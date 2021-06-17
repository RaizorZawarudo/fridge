/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** check_valid_file
*/

#include "../include/helper.h"
#include "../include/my.h"

int tomato_check(int amount, int *ingredients_amount)
{
    if (ingredients_amount[0] - amount < 0) {
        printf("'make pizza': not enough tomato\n");
        return 0;
    }
    return 1;
}

int dough_check(int amount, int *ingredients_amount, int goodstock)
{
    if (ingredients_amount[1] - amount < 0) {
        printf("'make pizza': not enough dough\n");
        return 0;
    }
    return goodstock;
}

int onion_check(int amount, int *ingredients_amount, int goodstock)
{
    if (ingredients_amount[2] - amount < 0) {
        printf("'make pizza': not enough onion\n");
        return 0;
    }
    return goodstock;
}

int pasta_check(int amount, int *ingredients_amount, int goodstock)
{
    if (ingredients_amount[3] - amount < 0) {
        printf("'make pizza': not enough pasta\n");
        return 0;
    }
    return goodstock;
}

int olive_check(int amount, int *ingredients_amount, int goodstock)
{
    if (ingredients_amount[4] - amount < 0) {
        printf("'make pizza': not enough olive\n");
        return 0;
    }
    return goodstock;
}