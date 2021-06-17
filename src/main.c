/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../include/helper.h"
#include "../include/my.h"

void save_fridge_data(int *ingredients_amount)
{
    FILE *f = fopen(".save", "w");

    if (f == NULL)
        exit(84);
    fprintf(f, "tomato = %d\n", ingredients_amount[0]);
    fprintf(f, "dough = %d\n", ingredients_amount[1]);
    fprintf(f, "onion = %d\n", ingredients_amount[2]);
    fprintf(f, "pasta = %d\n", ingredients_amount[3]);
    fprintf(f, "olive = %d\n", ingredients_amount[4]);
    fprintf(f, "pepper = %d\n", ingredients_amount[5]);
    fprintf(f, "ham = %d\n", ingredients_amount[6]);
    fprintf(f, "cheese = %d\n", ingredients_amount[7]);
    fclose(f);
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

int main(void)
{
    char **ingredients = NULL;
    int *ingredients_amount = NULL;

    ingredients = create_ingredient_list();
    ingredients_amount = malloc(sizeof(int) * 8);
    if (ingredients_amount == NULL)
        return 84;
    set_ingredients_amount(ingredients_amount);
    gameloop(ingredients, ingredients_amount);
    save_fridge_data(ingredients_amount);
    free(ingredients_amount);
    free_char_table(ingredients);
    return 0;
}