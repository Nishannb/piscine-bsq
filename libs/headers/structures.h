#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef	struct	s_panel_data
{
	int		coordinates_col;
	int		coordinates_row;
	int		panel_size_cols;
	int		panel_size_rows;
	char	*file_name;
	int		sqr_size;
	char	panel_chars_obstacle;
	char 	panel_chars_empty;
	char 	panel_chars_sqr;
}				t_panel_data;

typedef struct s_panel_size {
    int rows;    
    int cols;   
}         t_panel_size;

typedef struct s_panel_characters {
    char empty;     
    char obstacle;  
    char sqr;      
}         t_panel_characters;

#endif