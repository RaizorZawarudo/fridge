/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** loop
*/

#include "../include/helper.h"
#include "../include/my.h"

int do_disp(char *userline, char **ingredients, int *ingredients_amount,\
int valid)
{
    if (strcmp(userline, "disp fridge") != 0)
        return valid;

    for (int i = 0; i < 8; i++)
        printf("%s = %d\n", ingredients[i], ingredients_amount[i]);
    return 1;
}

int do_add(char *userline, char **ingredients, int *ingredients_amount,\
int valid)
{
    int match = 0;
    if (strncmp(userline, "addToFridge", 11) != 0)
        return valid;
    for (int i = 0; i < 8; i++) {
        if (strstr(userline, ingredients[i]) != NULL) {
            match = 1;
            add_amounts(userline, ingredients_amount, i);
        }
    }
    if (match == 0)
        return 0;
    return 1;
}

void do_invalid_cmd(int valid, char *userline)
{
    if (valid)
        return;
    printf("'%s': Invalid operation\n", userline);
}

void correct_input(char *userline)
{
    int size = strlen(userline);
    userline[size - 1] = '\0';
}

void gameloop(char **ingredients, int *ingredients_amount)
{
    int keep_going = 1;
    int valid = 0;
    char *userline = NULL;
    size_t len = 0;

    while (keep_going == 1) {
        if (getline(&userline, &len, stdin) == -1)
            exit(84);
        correct_input(userline);
        valid = do_disp(userline, ingredients, ingredients_amount, valid);
        valid = do_make(userline, ingredients_amount, valid);
        valid = do_add(userline, ingredients, ingredients_amount, valid);
        if ((keep_going = do_exit(userline)) == 0)
            valid = 1;
        do_invalid_cmd(valid, userline);
        valid = 0;
    }
    free(userline);
}