#include "headers/headers.h"
#include "headers/structures.h"
#include "headers/functions.h"

static	void	update_panel_data(char *array, t_panel_data *panel_data)
{
	panel_data->panel_chars_obstacle = get_obst_char(array);
	panel_data->panel_chars_empty = get_empty_char(array);
	panel_data->panel_chars_sqr = get_sqr_char(array);
	panel_data->panel_size_rows = get_row_num(array);
	panel_data->panel_size_cols = get_col_num(array);
}

static	char	**create_panel_from_array(char *array, int rows, int cols)
{
	int		i;
	int		j;
	int		y;
	char	**panel;

	y = 0;
	while (array[y] != '\n')
		y++;
	y++;
	panel = (char **)malloc(sizeof(char *) * rows);
	i = 0;
	while (i < rows)
	{
		panel[i] = (char *)malloc(sizeof(char) * cols);
		j = 0;
		while (j < cols)
		{
			panel[i][j] = array[y];
			j++;
			y++;
		}
		i++;
	}
	return (panel);
}

char			**create_panel(char *array, t_panel_data *panel_data)
{
	char	**panel;

	update_panel_data(array, panel_data);
	panel = create_panel_from_array(
		array,
		panel_data->panel_size_rows,
		panel_data->panel_size_cols);
	return (panel);
}