#include "headers/structures.h"
#include "headers/functions.h"

int		check_first_line(char *array)
{
	int i;
	int j;

	i = 0;
	while (array[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	if (array[i - 1] == array[i - 2] || array[i - 2] == array[i - 3] || array[i
			- 3] == array[i - 1])
		return (0);
	j = 0;
	while (j < (i - 3))
	{
		if (array[j] < '0' || array[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

int		are_chars_printable(char *array)
{
	int i;

	i = 0;
	while (array[i] != '\0')
	{
		if ((array[i] <= 31 || array[i] >= 126) && (array[i] != '\n'))
			return (0);
		i++;
	}
	return (1);
}

int		row_length(char *array)
{
	int i;
	int j;
	int counter;

	i = 0;
	counter = 0;
	while (array[i++] != '\n')
		counter++;
	i++;
	j = 0;
	while (array[i++] != '\0')
	{
		j = 0;
		while (array[i++] != '\n')
			j++;
		if (j != counter)
			return (0);
	}
	return (1);
}

int		are_chars_valid(char *array, t_panel_characters *panel_chars)
{
	int i;

	i = 0;
	while (array[i] != '\0')
	{
		if ((array[i] != panel_chars->obstacle || array[i] !=
					panel_chars->empty || array[i] != panel_chars->sqr) &&
				array[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}