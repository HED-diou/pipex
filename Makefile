CC =  cc -c

CFLAGS = -Wall -Werror -Wextra 

SRCS = 	ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strtrim.c \
		get_path.c \
		pipex.c \
		par.c

OBJS = ${SRCS:.c=.o}

ARV = ar -rcs

NAME = pipex.a

REM = rm -rf

.c.o :
	$(CC) ${CFLAGS} $< -o $@
	$(ARV) $(NAME) $@

all : $(NAME)
$(NAME) : $(OBJS)
	cc ${CFLAGS} ${NAME} pipex.c -o pipex

clean :
	${REM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${REM} ${NAME}
	${REM} pipex

re : fclean all

.PHONY : all clean fclean re