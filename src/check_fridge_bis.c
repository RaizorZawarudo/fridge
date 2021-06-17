/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** check_fridge_bis
*/

#include "../include/helper.h"
#include "../include/my.h"

int pepper_check(int amount, int *ingredients_amount, int goodstock)
{
    if (ingredients_amount[5] - amount < 0) {
        printf("'make pizza': not enough pepper\n");
        return 0;
    }
    return goodstock;
}

int ham_check(int amount, int *ingredients_amount, int goodstock)
{
    if (ingredients_amount[6] - amount < 0) {
        printf("'make pizza': not enough ham\n");
        return 0;
    }
    return goodstock;
}

int cheese_check(int amount, int *ingredients_amount, int goodstock)
{
    if (ingredients_amount[7] - amount < 0) {
        printf("'make pizza': not enough cheese\n");
        return 0;
    }
    return goodstock;
}