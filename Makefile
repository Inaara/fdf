OS :=	$(shell uname)

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_ORANGE	= \033[38m
F_RED		= \033[31m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m

adds =

FLAGS	= -Wall -Wextra -Werror 

ifeq ($(OS), Linux)
	COMPILE = Linux Compile...
	#@echo "$(F_GREEN) Linux Compile...$(F_NONE)"
	MINILIBX_DIR = minilibx/minilbx_linux
	LIB_MLX = ./minilibx/minilbx_linux
	OPENGL = -lm -lbsd -lX11 -lXext 
	MLX_A = libmlx_Linux.a  
	FLAGS	+= -D LINUX=1
	#adds = sudo apt-get install gcc make xorg libxext-dev libbsd-dev
endif
ifeq ($(OS), Darwin)
	COMPILE = MAC OS Compile...
	#@echo "$(F_GREEN)MAC OS Compile...$(F_NONE)"
	MINILIBX_DIR = minilibx/minilbx_mac
	LIB_MLX = ./minilibx/minilbx_mac
	OPENGL = -lz -framework OpenGL -framework AppKit
	MLX_A = libmlx.dylib
	FLAGS	+= -D DARWIN=1
endif

NAME_PROJECT = fdf

LIB_DIR =  ./libft/
LIB_NAME =	libft/libft.a
LIB_HEADER = libft/includes


MINILIBX_A_DIR 		=	$(MINILIBX_DIR)/$(MLX_A)


LIBFT = libft.a

CC		= gcc

HEADER	= includes
#depth -> recurse len



OBJS	 = $(SRCS:.c=.o)


DIR		= ./srcs/

SRCS = $(DIR)main.c $(DIR)ft_parse_map.c $(DIR)ft_parse_map2.c $(DIR)malloc_x.c  $(DIR)utils_atoi_base.c\
		$(DIR)menu.c $(DIR)draw.c $(DIR)projection_line.c $(DIR)color_fun.c $(DIR)mlx_fun.c  $(DIR)points.c $(DIR)rgb.c $(DIR)ft_keyboard.c \
		$(DIR)ft_keyboard2.c $(DIR)mouse_event.c


AR		= ar rc


.c.o:
	@echo "$(F_BLUE)Created object files $(NAME_PROJECT) ! $(F_NONE)"
	$(CC) $(FLAGS) -c  -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)
	@echo "$(F_BLUE)Object files $(NAME_PROJECT) in ready! $(F_NONE)"

all: $(LIBFT) $(MLX_A) $(NAME_PROJECT) 

bonus : $(LIBFT) $(MLX_A) $(NAME_PROJECT)	

$(MLX_A):
		$(adds)
		@echo "$(F_CYAN)Compile libmlx.a ...$(F_NONE)"
		make  -C $(LIB_MLX)
		@echo "$(F_CYAN)Compile libmlx.a END !...$(F_NONE)"
		@echo "$(F_CYAN)Copy libmlx.a ...$(F_NONE)"
		cp $(MINILIBX_A_DIR) $(MLX_A)
		@echo "$(F_CYAN)Copy libmlx.a END !...$(F_NONE)"

$(LIBFT):
		@echo "$(F_YELLOW)START RUN Makefile in libft $(F_NONE)"
		@$(MAKE) -C $(LIB_DIR)
		@echo "$(F_YELLOW)END RUN Makefile in libft $(F_NONE)"
$(NAME_PROJECT): $(OBJS)  
		@echo "$(F_CYAN)Compile $(NAME_PROJECT) ...$(F_NONE)"
		@echo "$(F_GREEN)$(COMPILE) $(F_NONE)"
		$(CC) $(FLAGS)  -I$(HEADER) $(OBJS) -L. $(LIB_NAME)  $(MINILIBX_A_DIR) $(OPENGL)  -o $(NAME_PROJECT)
		@echo "$(F_GREEN) $(NAME_PROJECT) is Ready! GOOD LUCK:) $(F_NONE)"		
clean:
	make clean -C $(LIB_DIR)
	make clean -C $(LIB_MLX)
	rm -rf $(OBJS) 
	@echo "$(F_GREEN)Cleaned! $(F_NONE)"
fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME_PROJECT)
	rm -rf $(MLX_A)
	@echo "$(F_GREEN)FCleaned! $(F_NONE)"

re: fclean all

norm:
	norminette *.c *.h

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(F_BOLD)  * Make code, *"
	@echo "$(F_BOLD)   * not war! *"
	@echo "$(F_RED)    ..10101.."
	@echo "$(F_ORANGE)  01   1   011"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE) 010   1   110"
	@echo "$(F_BLUE)   11011010**$(F_NONE)"

.PHONY: all clean fclean re code bonus norm
