CC = cc
CFALGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long

LIBDIR = libft-custom
LIB = libft.a
INC = -I$(LIBDIR) -L$(LIBDIR) -lft

SRC = source/main.c source/parser.c source/utils.c source/way_to_win.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) mk_lib
	$(CC) $(CFALGS) $(OBJ) $(INC) -o $(NAME)

%.o : %.c so_long.h
	@$(CC) $(CFALGS) -c $< -o $@

mk_lib :
	@make -C $(LIBDIR)
	@echo "making custom-lib"

clean :
	@make -C $(LIBDIR) clean
	@$(RM) $(OBJ)

fclean : clean
	@make -C $(LIBDIR) fclean
	@$(RM) $(OBJ) $(NAME)

re : fclean all

.PHONY : clean mk_lib