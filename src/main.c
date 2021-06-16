/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../include/helper.h"
#include "../include/my.h"

int error_management(int ac)
{
    if (ac != 1)
        return 0;
    return 1;
}

char **create_ingredient_list(void)
{
    char **ingredient_list = malloc(sizeof(char *) * 9);
    
    if (ingredient_list == NULL)
        exit(84);
    ingredient_list[0] = strdup("tomato");
    ingredient_list[1] = strdup("dough");
    ingredient_list[2] = strdup("onion");
    ingredient_list[3] = strdup("pasta");
    ingredient_list[4] = strdup("olive");
    ingredient_list[5] = strdup("pepper");
    ingredient_list[6] = strdup("ham");
    ingredient_list[7] = strdup("cheese");
    ingredient_list[8] = NULL;
    return ingredient_list;
}

int main(int ac, char **av)
{
    char **ingredients = NULL;
    int *ingredients_amount = NULL;

    if (!error_management(ac))
        return 84;
    ingredients = create_ingredient_list();
    ingredients_amount = malloc(sizeof(int) * 8);
    if (ingredients_amount == NULL)
        return 84;
    set_ingredients_amount(ingredients_amount);
    gameloop(ingredients, ingredients_amount);

    /* for (int i = 0; i < 8; i++)
        printf("%s has %d\n", ingredients[i], ingredients_amount[i]);
 */
    return 0;
}