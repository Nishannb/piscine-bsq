#include <stdlib.h>
#include "headers/functions.h"

int		ft_atoi(char *str)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int		get_row_num(char *map_array)
{
	int		i;
	int		j;
	int		row_num;
	char	*row_num_array;

	i = 0;
	while (map_array[i] != '\n')
		i++;
	row_num_array = (char *)malloc(sizeof(char) * (i - 2));
	j = 0;
	while (j < (i - 3))
	{
		row_num_array[j] = map_array[j];
		j++;
	}
	row_num_array[j] = '\0';
	row_num = ft_atoi(row_num_array);
	free(row_num_array);
	return (row_num);
}

int		get_col_num(char *map_array)
{
	int col_num;
	int first_row_chars;
	int i;

	i = 0;
	while (map_array[i] != '\n')
		i++;
	col_num = 0;
	first_row_chars = i + 1;
	while (map_array[first_row_chars + col_num] != '\n')
		col_num++;
	return (col_num + 1);
}
