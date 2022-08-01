NAME    =   libft.a
SRCS    =   ft_atoi.c       ft_isalpha.c        ft_putchar_fd.c\
            ft_memcpy.c     ft_itoa.c           ft_strmapi.c\
            ft_tolower.c    ft_bzero.c          ft_split.c\
            ft_isascii.c    ft_memmove.c        ft_strtrim.c\
            ft_strlcat.c    ft_strncmp.c        ft_strjoin.c\
            ft_toupper.c    ft_calloc.c         ft_isdigit.c    ft_error.c\
            ft_memchr.c     ft_memset.c         ft_strdup.c     ft_striteri.c\
            ft_strlcpy.c    ft_strnstr.c        ft_isalnum.c    ft_putnbr_fd.c\
            ft_isprint.c    ft_memcmp.c         ft_substr.c     ft_putendl_fd.c\
            ft_strchr.c     ft_strlen.c         ft_strrchr.c    ft_putstr_fd.c\

SRCS_B  =   ft_lstclear.c   ft_lstdelone.c      ft_lstlast.c    ft_lstadd_back.c    ft_lstsize.c\
            ft_lstnew.c     ft_lstadd_front.c   ft_lstmap.c     ft_lstiter.c\

HEADER	=	libft.h

OBJ		=	$(SRCS:.c=.o)

OBJ_B	=	$(SRCS_B:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I.

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

bonus	:	 $(OBJ_B) $(HEADER)
	ar rcs $(NAME) $(OBJ_B)

clean	:
	rm -f $(OBJ) $(OBJ_B)

fclean  :   clean
	rm -f $(NAME)

re      :   fclean all
