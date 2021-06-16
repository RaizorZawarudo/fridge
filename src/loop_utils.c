/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** loop_utils
*/

#include "../include/helper.h"
#include "../include/my.h"

void add_amounts(char *content, int *ingredients_amount, int i)
{
    int j = 0;
    char *cur_line = malloc(sizeof(char) * strlen(content));
    
    if (cur_line == NULL)
        exit(84);
    for (int a = 0; content[a] != '\0'; a++) {
        if (content[a] >= '0' && content[a] <= '9') {
            cur_line[j] = content[a];
            j++;
        }
    }
    cur_line[j] = '\0';
    ingredients_amount[i] += atoi(cur_line);
    free(cur_line);
}