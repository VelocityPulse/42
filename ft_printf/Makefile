#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/12 19:31:40 by                   #+#    #+#             *#
#*   Updated: 2016/09/01 18:00:08 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#



FILES =				ft_printf.c \
					process.c \
					select_conversion.c \
					select_lenght.c \
					select_flags.c \
					select_precision.c \
					call_percent.c \
					call_putnbr.c \
					call_putnbr_l.c \
					call_putstr.c \
					call_putchar.c \
					call_putbase.c \
					call_putbase_l.c \
					call_putpointer.c \
					call_putwchar.c \
					call_putwstr.c \
					fields.c \
					sharp.c \
					help_print_d.c \
					help_print_s.c \
					help_print_b.c \
					help_print_c.c

SRC =				$(addprefix srcs/, $(FILES))

OBJS =				$(FILES:.c=.o)

CC = 				gcc

NAME =				ft_printf.a

FLAGS =				 -Wextra -Werror -Wall

RM =				rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all
