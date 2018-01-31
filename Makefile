NO_COLOR= \x1b[0m
B_GRY	= \x1b[30;01m
B_RED	= \x1b[31;01m
B_GRN	= \x1b[32;01m
B_YEL	= \x1b[33;01m
B_BLU	= \x1b[34;01m
B_PURP	= \x1b[35;01m
B_TURQ	= \x1b[36;01m
B_WHT	= \x1b[37;01m
GRY		= \x1b[30m
RED		= \x1b[31m
GRN		= \x1b[32m
YEL		= \x1b[33m
BLU		= \x1b[34m
PURP	= \x1b[35m
TURQ	= \x1b[36m
WHT		= \x1b[37m
CC		= gcc
CFLAGS	= -Wall -Wextra
SRC		= $(shell ls src | grep -E ".+\.c")
VSRC	= $(shell ls visual | grep -E ".+\.c")
ODIR	:= obj
OBJ		:= $(addprefix $(ODIR)/,$(SRC:%.c=%.o))
VOBJ	:= $(addprefix $(ODIR)/,$(VSRC:%.c=%.o))
INC		= includes
LIB		= libft.a
EX		= players/elopez.filler
BONUS	= visualizer


all: $(LIB) $(EX) $(BONUS)

visual: $(BONUS) $(EX)
	@-touch output
	@-chmod 666 output
	-./filler_vm -p1 $(EX) -p2 players/abanlin.filler -f maps/map00 > output
	-./$(BONUS) output
	@rm -f output

$(EX): $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC) -o $(EX) $(OBJ) -L. -lft

$(ODIR)/%.o:src/%.c | $(ODIR)
	@$(CC) $(CFLAGS) -I $(INC) -I minilibx -o $@ -c $<

$(ODIR):
	@mkdir $(ODIR)

$(LIB):
	@make -C libft/

$(BONUS): $(LIB) $(OBJ) $(VOBJ)
	@make -C minilibx/
	@$(CC) $(CFLAGS) -I $(INC) -I ./minilibx -o $(BONUS) $(VOBJ) -L. -lft -L minilibx -lmlx -framework OpenGL -framework AppKit

$(ODIR)/%.o:visual/%.c | $(ODIR)
	@$(CC) $(CFLAGS) -I $(INC) -I minilibx -o $@ -c $<

clean:
	@rm -rf obj
	@make -C libft/ clean
	@make -C minilibx/ clean

fclean: clean
	@rm -f $(EX) $(BONUS)
	@make -C libft/ fclean

re: fclean all

.PHONY: clean fclean all re visual

