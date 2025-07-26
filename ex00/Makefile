# Nom du programme
NAME = rush-02

# Répertoires
SRCDIR = srcs
INCDIR = headers

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

# Fichiers sources
SRC = $(wildcard $(SRCDIR)/*.c)

# Objets
OBJ = $(SRC:.c=.o)

# Règles

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re