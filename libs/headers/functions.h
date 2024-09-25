#include "structures.h"

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int		ft_atoi(char *str);
void	print_char(char c);
void	print_str(char *str);
int		draw_panel(char *panel_file_name);
char	**create_panel(char *array, t_panel_data *panel_data);
int		find_sqr_coordinates(char **panel, t_panel_data *panel_data);
int		is_sqr_valid(char **panel, t_panel_data *panel_data, int sqr_size);
void	add_sqr_to_panel(char **panel, t_panel_data *panel_data);
void	print_panel(char **panel, t_panel_data *panel_data);
int		get_row_num(char *map_array);
int		get_col_num(char *map_array);
char	get_empty_char(char *map_array);
char	get_obst_char(char *map_array);
char	get_sqr_char(char *map_array);
char	*create_array(char *file_name);
int		check_first_line(char *array);
int		are_chars_printable(char *array);
int		row_length(char *array);
int		are_chars_valid(char *array, t_panel_characters *panel_chars);
#endif