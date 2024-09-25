#include "headers/functions.h"
#include "headers/structures.h"
#include <unistd.h>

int		valid_size(char *array)
{
	int i;

	i = 0;
	while (array[i] != '\n')
		i++;
	i++;
	if (array[i] == '\0')
		return (0);
	return (1);
}

int		line_breaks(char *array, t_panel_size panel_size)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (array[i] != '\0')
	{
		if (array[i] == '\n')
			counter++;
		i++;
	}
	if ((counter - 1) != panel_size.rows)
		return (0);
}

int		is_map_valid(char *array, t_panel_characters *panel_chars, t_panel_size panel_size)
{
	int i;

	i = 1;
	i = check_first_line(array);
	if (i == 0)
		return (0);
	i = are_chars_printable(array);
	if (i == 0)
		return (0);
	i = row_length(array);
	if (i == 0)
		return (0);
	i = are_chars_valid(array, panel_chars);
	if (i == 0)
		return (0);
	i = valid_size(array);
	if (i == 0)
		return (0);
	i = line_breaks(array, panel_size);
	if (i == 0)
		return (0);
	else
		return (1);
}

void	print_map_error(void)
{
	write(1, "Map error.\n", 11);
}