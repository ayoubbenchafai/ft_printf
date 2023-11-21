NAME= libftprintf.a
CC= CC
CFLAGS= -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_putstr.c nbr_digits.c \
	ft_putnbr_unsigned.c ft_putnbr.c hex.c \
	hex_p.c check_conversions.c \
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
 
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all 