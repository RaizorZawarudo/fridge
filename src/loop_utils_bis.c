/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** loop_utils_bis
*/

#include "../include/helper.h"
#include "../include/my.h"

int invalid_amount_check(int a, int spaces, char *content, int invalid_amount)
{
    if (spaces >= 2 && (content[a] < '0' || content[a] > '9'))
        invalid_amount += 1;
    return invalid_amount;
}