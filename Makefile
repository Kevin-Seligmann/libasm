VPATH = src

# Files
OBJ = hello.o

# Target
NAME = hello_world

# Project
PROJ = libasm

# Directories
OBJ_DIR = obj

INC_DIR = inc

OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

# DEPS = $(OBJ_PATH:.o=.d)

# Include
# INCLUDES = -I./$(INC_DIR)

# Compilation Flags
CFLAGS = -f elf64

# Linker
LK = ld

# Compiler
CC = nasm

# Colors
YELLOW = "\e[33m"
GREEN = "\e[32m"
NO_COLOR = "\e[0m"

# Linking
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_PATH) Makefile
	@$(LK) $(OBJ_PATH) -o $(NAME)
	@echo $(YELLOW)$(PROJ) - Creating exec:$(NO_COLOR) $(NAME)

# Compilation
$(OBJ_DIR)/%.o:%.s
	@$(CC) $(INCLUDES) $(CFLAGS) $< -o $@
	@echo $(YELLOW)$(PROJ) - Compiling object file:$(NO_COLOR) $(notdir $@)

# Utils
-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(YELLOW)$(PROJ) - Removing:$(NO_COLOR) Object and dependency files

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@echo $(YELLOW)$(PROJ) - Removing:$(NO_COLOR) $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean fclean all re $(OBJ_DIR)
