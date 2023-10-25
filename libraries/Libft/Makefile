NAME	=	libft.a

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f

SRC	=	ft_strlen.c ft_strdup.c ft_split.c ft_strjoin.c ft_strrchr.c ft_strcmp.c ft_itoa.c\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)


$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
