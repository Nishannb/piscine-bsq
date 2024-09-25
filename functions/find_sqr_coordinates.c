#include "headers/headers.h"
#include "headers/structures.h"
#include "headers/functions.h"

static	void	update_panel_data(
	t_panel_data *panel_data,
	int sqr_size,
	int row,
	int col)
{
	panel_data->coordinates_row = row;
	panel_data->coordinates_col = col;
	panel_data->sqr_size = sqr_size;
}

int				find_sqr_coordinates(
	char **panel,
	t_panel_data *panel_data)
{
	int		row;
	int		col;
	int		sqr_size;
	int		is_there_a_valid_sqr;

	is_there_a_valid_sqr = 0;
	row = panel_data->coordinates_row;
	sqr_size = panel_data->sqr_size;
	while (row < panel_data->panel_size_rows)
	{
		col = panel_data->coordinates_col;
		while (col < panel_data->panel_size_cols)
		{
			while (is_sqr_valid(panel, panel_data, sqr_size))
			{
				is_there_a_valid_sqr = 1;
				sqr_size++;
			}
			if (sqr_size > panel_data->sqr_size)
				update_panel_data(panel_data, sqr_size, row, col);
			col++;
		}
		row++;
	}
	return (is_there_a_valid_sqr);
}