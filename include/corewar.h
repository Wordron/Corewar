/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/
#include <stdio.h>
#include <stdbool.h>
#include "op.h"

#ifndef COREWAR_H_
    #define COREWAR_H_

    typedef struct champ_s {
        bool alive;
        char name_champ[PROG_NAME_LENGTH + 1];
        int registers;
        int pc;
        int carry;
        int id;
    } champ_t;

    typedef struct vm_s {
        char **av;
        int ac;
        int cycle_die;
        int nb_champions_alive;
        int nb_tot_champ;
        int nb_cycle_dump;
        int nb_live;
        champ_t **champs;
        char memory[MEM_SIZE];
    } vm_t;

    typedef struct s_labels {
        char *label_name;
        int position;
    } label_t;

    typedef struct s_asm {
        FILE *fd;
        FILE *output;
        label_t **labels;
        header_t *header;
        char *file_path_input;
        int line;
        int where_bytes;
        int temp_where_bytes;
        char *output_name;
    } asm_t;

    enum e_where_index {
        NONE = 0,
        FIRST_ONE,
        FIRST_TWO,
        LAST_TWO
    };

    #define CONVERT_ENDIAN(a) ((0x000000ff & a) << 24) | /*See 1*/\
((0x0000ff00 & a) << 8) | /*See 2*/ \
((0x00ff0000 & a) >> 8) | /*See 3*/ \
((0xff000000 & a) >> 24) /*See 4*/

/*1 - Moves the least significant byte to the most*/
/*2 - Moves the second least significant byte to the second most*/
/*3 - Moves the second most significant byte to the second least*/
/*4 - Moves the most significant byte to the least*/

    void free_double_array(char **arr);
    void check_for_commentaries(char *str, asm_t *asm_s);
    void separate_line_header(char *line, asm_t *asm_s);
    void process_word_header(char *word, asm_t *asm_s, int check);
    void process_command(char **arr, asm_t *asm_s);
    int check_label_chars(char *label, int start);
    char *process_args(char *arg, char *parameters);
    char *get_bin_from_hexa(char *hexa);
    void get_long_from_string(char *string, FILE *output);
    int conv_to_base(unsigned long nb, int base, FILE *output);
    int arr_len(char **arr);
    int conv_bin_to_hexa(long int binary);
    void check_which_type(char *arg, args_type_t args_type);
    int my_is_num(char *str, int start);
    int my_is_num_2(char *str, int start);
    void get_file(asm_t *asm_s);
    void print_args(char *arg, asm_t *asm_s, unsigned int i,
        enum e_where_index where);
    void get_args(vm_t *vm);
    void process_command_labels(char **arr, asm_t *asm_s);
    void check_for_commentaries_labels(char *str, asm_t *asm_s);
    char *get_label_without_two_points(char *str);
    int strlen_before_two(char *str);
    void parameters_cat(char *parameters, char *src);
    char *get_bin_from_hexa(char *hexa);
    int main_loop(vm_t *vm);
    char *int_copy_in_char(char *nb, int new_size);
    void do_if_command(char **arr, asm_t *asm_s, int start);
    enum e_where_index where_is_index(int which_command);
    void process_args_labels(char *arg, asm_t *asm_s, int which_command,
        int i);
    void do_if_command_labels(char **arr, asm_t *asm_s, int start,
        int arr_size);
    int get_param_size(enum e_where_index where, int i);
    void print_labels(asm_t *asm_s, char *label);
    void do_if_indirect_label(char *arg, asm_t *asm_s);
    char *create_delim_direct_label(void);
    void display_alive(champ_t *champion);
    void display_winner(champ_t *champion);
    int check_command(char *command);
    int update_if_comment(int comment);
    int update_if_name(int name);
    void check_name_length(char *word);
    void check_comment_length(char *word);
    int check_line_emptyness(char *line);
    char *my_strstr(char *str, char const *to_find);
    int find_which_label(label_t **labels, char *label);

#endif /* !COREWAR_H_ */
