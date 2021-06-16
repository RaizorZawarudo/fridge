/*
** EPITECH PROJECT, 2021
** fridge
** File description:
** set_ingredients
*/

#include "../include/helper.h"
#include "../include/my.h"

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    struct stat sb;

    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (buffer == NULL)
        exit(84);
    memset(buffer, 0, sizeof(char) * (sb.st_size + 1));
    if (fd < 0) {
        return NULL;
    }
    read(fd, buffer, sb.st_size);
    close(fd);
    return buffer;
}

void create_ingredient_file(void)
{
    FILE *f = fopen(".save", "w");

    if (f == NULL)
        exit(84);
    fprintf(f, "tomato = 50\n");
    fprintf(f, "dough = 50\n");
    fprintf(f, "onion = 50\n");
    fprintf(f, "pasta = 50\n");
    fprintf(f, "olive = 50\n");
    fprintf(f, "pepper = 50\n");
    fprintf(f, "ham = 50\n");
    fprintf(f, "cheese = 50\n");
    fclose(f);
}

void check_valid_file(char **parsed_file)
{
    int size = 0;
    
    for (int i = 0; parsed_file[i] != NULL; i++)
        size++;
    if (size != 8)
        exit(84);
    if (strncmp("tomato = ", parsed_file[0], 9) != 0 || \
    strncmp("dough = ", parsed_file[1], 8) != 0 || \
    strncmp("onion = ", parsed_file[2], 8) != 0 || \
    strncmp("pasta = ", parsed_file[3], 8) != 0 || \
    strncmp("olive = ", parsed_file[4], 8) != 0 || \
    strncmp("pepper = ", parsed_file[5], 9) != 0 || \
    strncmp("ham = ", parsed_file[6], 6) != 0 || \
    strncmp("cheese = ", parsed_file[7], 9) != 0)
        exit(84);    
}

void retrieve_amounts(char *content, int *ingredients_amount, int i)
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
    ingredients_amount[i] = atoi(cur_line);
    free(cur_line);
}

void set_ingredients_amount(int *ingredients_amount)
{
    char *content = read_file(".save");
    char **content_array = NULL;

    if (content == NULL) {
        create_ingredient_file();
        for (int i = 0; i < 8; i++)
            ingredients_amount[i] = 50;
        return;
    }
    content_array = my_str_to_word_array(content, '\n');
    check_valid_file(content_array);
    for (int i = 0; i < 8; i++)
        retrieve_amounts(content_array[i], ingredients_amount, i);
}