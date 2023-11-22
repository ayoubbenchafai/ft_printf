NAME= libftprintf.a
CC= CC
CFLAGS= -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_nbr_digits.c \
	ft_putnbr_unsigned.c ft_putnbr.c ft_hex.c \
	ft_hex_p.c ft_hex_p.c ft_check_conversions.c \
	
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
