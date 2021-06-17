/*
** EPITECH PROJECT, 2020
** helper.h
** File description:
** header file containing prototypes and definitions from all project files
*/

#ifndef HELPER_H_
#define HELPER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <math.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

void set_ingredients_amount(int *ingredients_amount);
char **my_str_to_word_array(char *str, char sep);
void gameloop(char **ingredients, int *ingredients_amount);
void add_amounts(char *content, int *ingredients_amount, int i);
int do_exit(char *userline);
int do_make(char *userline, int *ingredients_amount, int valid);
int tomato_check(int amount, int *ingredients_amount);
int dough_check(int amount, int *ingredients_amount, int goodstock);
int onion_check(int amount, int *ingredients_amount, int goodstock);
int pasta_check(int amount, int *ingredients_amount, int goodstock);
int olive_check(int amount, int *ingredients_amount, int goodstock);
int pepper_check(int amount, int *ingredients_amount, int goodstock);
int ham_check(int amount, int *ingredients_amount, int goodstock);
int cheese_check(int amount, int *ingredients_amount, int goodstock);
void make_pasta(int *ingredients_amount);
void make_pizza(int *ingredients_amount);
int invalid_amount_check(int a, int spaces, char *content, int invalid_amount);
void free_char_table(char **table);

#endif /* !HELPER_H_ */