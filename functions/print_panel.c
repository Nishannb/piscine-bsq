#include "headers/structures.h"
#include "headers/functions.h"

void	print_panel(char **panel, t_panel_data *panel_data)
{
	int row;

	row = 0;
	while (row < panel_data->panel_size_rows)
	{
		print_str(panel[row]);
		row++;
	}
}