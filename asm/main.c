/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

static char *get_output_name(char *input_file_name)
{
    char **arr = my_str_to_word_arr(input_file_name, "./");
    int arr_size = arr_len(arr);
    char *new_name = NULL;

    if (my_strstr(input_file_name, ".s") == 0) {
        new_name = malloc(sizeof(char) * (my_strlen(arr[arr_size - 1]) + 5));
        my_strcpy(new_name, arr[arr_size - 1]);
    } else {
        new_name = malloc(sizeof(char) * (my_strlen(arr[arr_size - 2]) + 5));
        my_strcpy(new_name, arr[arr_size - 2]);
    }
    my_strcat(new_name, ".cor");
    free_double_array(arr);
    return (new_name);
}

static header_t *init_header(void)
{
    header_t *header = malloc(sizeof(header_t));

    header->magic = CONVERT_ENDIAN(COREWAR_EXEC_MAGIC);
    for (int i = 0; i < PROG_NAME_LENGTH + 1; i++)
        header->prog_name[i] = '\0';
    for (int i = 0; i < COMMENT_LENGTH + 1; i++)
        header->comment[i] = '\0';
    header->prog_size = 0;
    return (header);
}

static asm_t *create_struct(void)
{
    asm_t *asm_s = malloc(sizeof(asm_t));

    asm_s->fd = NULL;
    asm_s->output = NULL;
    asm_s->header = init_header();
    asm_s->where_bytes = 0;
    asm_s->temp_where_bytes = 0;
    asm_s->output_name = NULL;
    return (asm_s);
}

static void free_struct(asm_t *asm_s)
{
    fclose(asm_s->fd);
    fclose(asm_s->output);
    free(asm_s->file_path_input);
    free(asm_s->header);
    free(asm_s->output_name);
    free(asm_s);
}

int main(int ac, char **av)
{
    asm_t *asm_s = create_struct();

    if (ac != 2)
        return (84);
    asm_s->output_name = get_output_name(av[1]);
    asm_s->fd = fopen(av[1], "r");
    if (asm_s->fd == NULL)
        exit(84);
    asm_s->file_path_input = malloc(sizeof(char) * (my_strlen(av[1]) + 1));
    my_strcpy(asm_s->file_path_input, av[1]);
    get_file(asm_s);
    process_word_header(NULL, asm_s, 1);
    free_struct(asm_s);
    exit(0);
}
