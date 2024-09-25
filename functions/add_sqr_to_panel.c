#include "headers/functions.h"

void	add_sqr_to_panel(char **panel, t_panel_data *panel_data)
{
	int		row;
	int		col;
	int		this_row;
	int		this_col;

	row = 0;
	col = 0;
	while (row < panel_data->sqr_size)
	{
		col = 0;
		while (col < panel_data->sqr_size)
		{
			this_row = panel_data->coordinates_row + row;
			this_col = panel_data->coordinates_col + col;
			panel[this_row][this_col] = panel_data->panel_chars_sqr;
			col++;
		}
		row++;
	}
}