# Define the name of the output program
NAME = bsq

# Define the list of source files (.c files)
SRC = main.c file_reading.c map_parsing.c square_finding.c validation.c # Replace with your actual .c files

# Define the list of object files (.o files) generated from the source files
OBJ = $(SRC:.c=.o)

# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Default rule to compile the program
all: $(NAME)

# Rule to create the executable by compiling the object files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Rule to remove object files
clean:
	rm -f $(OBJ)

# Rule to remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to rebuild everything from scratch
re: fclean all
