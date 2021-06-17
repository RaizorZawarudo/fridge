/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** loop_utils
*/

#include "../include/helper.h"
#include "../include/my.h"

void meal_doesnt_exist(char *userline)
{
    int j = 0;
    char *meal = malloc(sizeof(char) * strlen(userline));

    if (meal == NULL)
        exit(84);
    for (int a = 5; userline[a] != '\0'; a++) {
        meal[j] = userline[a];
        j++;
    }
    meal[j] = '\0';
    printf("'%s': meal unknown\n", meal);
    free(meal);
}

int do_make(char *userline, int *ingredients_amount, int valid)
{
    if (strncmp(userline, "make ", 5) != 0)
        return valid;
    if (!strcmp(userline, "make pizza")) {
        make_pizza(ingredients_amount);
        return 1;
    }
    if (!strcmp(userline, "make pasta")) {
        make_pasta(ingredients_amount);
        return 1;
    }
    meal_doesnt_exist(userline);
    return 1;
}

int do_exit(char *userline)
{
    if (!strcmp(userline, "exit"))
        return 0;
    return 1;
}

int count_spaces(char a)
{
    if (a == ' ')
        return 1;
    return 0;
}

void add_amounts(char *content, int *ingredients_amount, int i)
{
    int j = 0;
    int inv = 0;
    int spaces = 0;
    char *cur_line = malloc(sizeof(char) * strlen(content));

    if (cur_line == NULL)
        exit(84);
    for (int a = 0; content[a] != '\0'; a++) {
        if (content[a] >= '0' && content[a] <= '9') {
            cur_line[j] = content[a];
            j++;
        }
        inv = invalid_amount_check(a, spaces, content, inv);
        spaces += count_spaces(content[a]);
    }
    cur_line[j] = '\0';
    if (inv != 0)
        printf("'%s': Invalid operation\n", content);
    else
        ingredients_amount[i] += atoi(cur_line);
    free(cur_line);
}