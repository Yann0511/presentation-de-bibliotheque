NAME 	=	groupe5 

CFLAGS	=	-g2

HEADERS_DIR 	=	 $(shell find . -name "*.h")

SRC 	=	 $(shell find  -name "*.c")

OBJ  	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(HEADERS_DIRS) -g3 -gdwarf-4

temp:
	find . -name "*[#,~,.o]" -type f -delete

clean:   temp
	rm -f $(NAME)
	rm -f $(OBJ)

fclean:  clean
	rm -f $(NAME)

re: 	 fclean  all

auteur:  Groupe 5

