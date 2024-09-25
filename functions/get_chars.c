#include "headers/functions.h"

char	get_empty_char(char *map_array)
{
	int		i;
	char	empty;

	i = 0;
	while (map_array[i] != '\n')
		i++;
	empty = map_array[i - 3];
	return (empty);
}

char	get_obst_char(char *map_array)
{
	int		i;
	char	obstacle;

	i = 0;
	while (map_array[i] != '\n')
		i++;
	obstacle = map_array[i - 2];
	return (obstacle);
}

char	get_sqr_char(char *map_array)
{
	int		i;
	char	square;

	i = 0;
	while (map_array[i] != '\n')
		i++;
	square = map_array[i - 1];
	return (square);
}
