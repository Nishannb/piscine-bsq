#include "headers/headers.h"
#include "headers/functions.h"
#include "headers/structures.h"
#include "headers/variables.h"

static	void	initialize_panel_data(
	t_panel_data *panel_data,
	char *file_name)
{
	panel_data->coordinates_row = 0;
	panel_data->coordinates_col = 1;
	panel_data->sqr_size = 2;
	panel_data->file_name = file_name;
}

static	void	free_panel(char **panel, int rows)
{
	int row;

	row = 0;
	while (row < rows)
	{
		free(panel[row]);
		row++;
	}
	free(panel);
}

int				draw_panel(char *panel_file_name)
{
	char			**panel;
	char			*arr;
	t_panel_data	panel_data;

	initialize_panel_data(&panel_data, panel_file_name);
	arr = create_array(panel_data.file_name);
	panel = create_panel(arr, &panel_data);
	free(arr);
	if (find_sqr_coordinates(panel, &panel_data))
	{
		add_sqr_to_panel(panel, &panel_data);
		print_panel(panel, &panel_data);
		free_panel(panel, panel_data.panel_size_rows);
		return (1);
	}
	free_panel(panel, panel_data.panel_size_rows);
	return (0);
}

static	int		ft_file_size(char *file_name, int buff_cnt)
{
	int		fd;
	int		nchr;
	int		file_size;
	char	**buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		fd = 0;
	buffer = (char **)malloc(sizeof(char *) * buff_cnt);
	nchr = read(fd, buffer, buff_cnt);
	file_size = 0;
	if (nchr == buff_cnt)
	{
		close(fd);
		return (ft_file_size(file_name, buff_cnt * 2));
	}
	else if (nchr != buff_cnt)
	{
		close(fd);
		file_size = nchr;
	}
	free(buffer);
	return (file_size);
}

char			*create_array(char *file_name)
{
	int		fd;
	int		file_size;
	char	*panel_array;

	file_size = ft_file_size(file_name, INIT_BUFFER);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		fd = 0;
	panel_array = (char *)malloc(sizeof(char) * file_size);
	read(fd, panel_array, file_size);
	return (panel_array);
}