NAME	=	minishell

READLINE =	-I/Users/$(USER)/.brew/opt/readline/include -lreadline -L /Users/$(USER)/.brew/opt/readline/lib

SRCS =		rmicheli/dou_right_red.c rmicheli/left_redirect2.c \
			rmicheli/list_create.c rmicheli/lst.c rmicheli/minishell.c rmicheli/pars_command.c \
			rmicheli/pars_line.c rmicheli/pars_redirect.c rmicheli/parsing_marks_utils.c \
			rmicheli/parsing_marks.c rmicheli/preparsing.c tconwy/utils.c rmicheli/pars_command_utils.c\
			tconwy/ft_pipe.c tconwy/ft_cd.c tconwy/ft_echo.c tconwy/ft_export.c tconwy/ft_export_help.c \
			tconwy/ft_export_print.c tconwy/env.c tconwy/ft_unset.c tconwy/ft_pwd.c rmicheli/pars_line_utils.c

INCLUDE	=	mini.h
 
INCLUDEL=	libft/libft.h
 
OBJS	=	$(SRCS:.c=.o)
 
CC	=	gcc
 
LIBFT	=	-Llibft -lft
 
CFLAGS 	=	-Wall -Wextra -Werror -g3
 
all : $(NAME)
 
%.o: %.c		$(SRCS)
				@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDEL) -c $< -o $@
 
$(NAME) : $(OBJS) $(INCLUDE)
	make bonus -C libft
	make -C libft
	make bonus -C libft
	$(CC) $(READLINE) $(LIBFT) $(CFLAGS) $(OBJS)  -o $(NAME)
clean :
	rm -rf $(OBJS)
	make clean -C libft

fclean	: clean
	rm -rf $(NAME)
	make fclean -C libft
 
re		: fclean all
 
.PHONY: clean fclean re all