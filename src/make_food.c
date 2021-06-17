/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** make_food
*/

#include "../include/helper.h"
#include "../include/my.h"

void remove_ingredients(char *meal, int *ingredients_amount)
{
    if (!strcmp("pizza", meal)) {
        ingredients_amount[0] -= 5;
        ingredients_amount[1] -= 1;
        ingredients_amount[2] -= 3;
        ingredients_amount[4] -= 8;
        ingredients_amount[5] -= 8;
        ingredients_amount[6] -= 4;
        ingredients_amount[7] -= 3;
    }
    if (!strcmp("pasta", meal)) {
        ingredients_amount[0] -= 5;
        ingredients_amount[3] -= 2;
        ingredients_amount[4] -= 6;
        ingredients_amount[6] -= 4;
        ingredients_amount[7] -= 3;
    }
}

void make_pasta(int *ingredients_amount)
{
    int good_stock = 0;

    good_stock = tomato_check(5, ingredients_amount);
    good_stock = pasta_check(2, ingredients_amount, good_stock);
    good_stock = olive_check(6, ingredients_amount, good_stock);
    good_stock = ham_check(4, ingredients_amount, good_stock);
    good_stock = cheese_check(3, ingredients_amount, good_stock);

    if (good_stock != 0)
        remove_ingredients("pasta", ingredients_amount);
}

void make_pizza(int *ingredients_amount)
{
    int good_stock = 0;

    good_stock = tomato_check(5, ingredients_amount);
    good_stock = dough_check(1, ingredients_amount, good_stock);
    good_stock = onion_check(3, ingredients_amount, good_stock);
    good_stock = olive_check(8, ingredients_amount, good_stock);
    good_stock = pepper_check(8, ingredients_amount, good_stock);
    good_stock = ham_check(4, ingredients_amount, good_stock);
    good_stock = cheese_check(3, ingredients_amount, good_stock);

    if (good_stock != 0)
        remove_ingredients("pizza", ingredients_amount);
}