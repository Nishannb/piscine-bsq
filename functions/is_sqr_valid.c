#include "headers/headers.h"
#include "headers/structures.h"
#include "headers/functions.h"

static	int		fits_panel_row(int rows,
	int row,
	int sqr_size)
{
	if (row + sqr_size <= rows)
	{
		return (1);
	}
	return (0);
}

static	int		fits_panel_col(int cols,
	int col,
	int sqr_size)
{
	if (col + sqr_size <= cols)
	{
		return (1);
	}
	return (0);
}

int				is_sqr_valid(
	char **panel,
	t_panel_data *panel_data,
	int sqr_size)
{
	int		row;
	int		col;
	int		this_row;
	int		this_col;

	row = 0;
	while (row < sqr_size &&
		fits_panel_row(panel_data->panel_size_rows, row, sqr_size))
	{
		col = 0;
		while (col < sqr_size &&
			fits_panel_col(panel_data->panel_size_cols, col, sqr_size))
		{
			this_row = panel_data->coordinates_row + row;
			this_col = panel_data->coordinates_col + col;
			if (panel[this_row][this_col] == panel_data->panel_chars_obstacle)
			{
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}