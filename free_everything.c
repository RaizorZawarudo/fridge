/*
** EPITECH PROJECT, 2021
** B-CPE-210-BER-2-1-stumper4-eduard.popp
** File description:
** free_everything
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/helper.h"
#include "../include/my.h"

void free_char_table(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}