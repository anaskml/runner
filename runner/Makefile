CC = clang

NAME=RUNNER

SRC=    source/main.c\
            source/draw.c\
            source/init.c\
            source/input.c\

OBJ=$(SRC:%.c=%.o)

RM = rm -f

CFLAGS += -I /opt/homebrew/include -I include
CFLAGS += -W -Werror -Wall -Wextra

LIBS += -l SDL2 -l SDL2_image -L/opt/homebrew/lib

$(NAME):    $(OBJ)
			$(CC) $(OBJ) $(LIBS) -o $(NAME)
all:        $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:    fclean all

.PHONY: all clean