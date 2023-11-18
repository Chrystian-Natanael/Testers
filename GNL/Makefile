# Description: Makefile for Tester GNL
#
#
# colors
GREEN = \033[32m
YELLOW = \033[33m
PURPLE = \033[35m
RED = \033[31m
WHITE = \033[37m
FCOLOR = \033[0m

# Variables
FLAGS = -Wall -Wextra -Werror

NAME = tester_gnl

GNL_DIR = ./includes/

GNL_FILES =	$(GNL_DIR)get_next_line.c \
			$(GNL_DIR)get_next_line_utils.c

GNL_HEADER = get_next_line.h

GNL_HEADER_BONUS = get_next_line_bonus.h

GNL_DIR_BONUS = ./includes/bonus/

GNL_FILES_BONUS =	$(GNL_DIR_BONUS)get_next_line_bonus.c \
					$(GNL_DIR_BONUS)get_next_line_utils_bonus.c

BIN_DIR = ./bin/

SRC_DIR = ./src/

TESTER = $(SRC_DIR)tester_gnl.c

TESTER_HEADER = tester_gnl.h

TESTER_BONUS = $(SRC_DIR)tester_gnl_bonus.c

.phony: all re bonus clean

$(NAME):
	@echo "$(YELLOW)Compiling $(PURPLE)$(NAME)$(YELLOW)...$(FCOLOR)"
	@sleep 0.2
	@$(CC) $(FLAGS) -I$(GNL_DIR) -I$(SRC_DIR) $(GNL_FILES) $(TESTER) -o $(BIN_DIR)$(NAME) -g3
	@echo "$(GREEN)"Compiled [OK] "$(FCOLOR)"

# Compiler
all: $(NAME)

# recompile all
re: clean all
	@echo "$(GREEN)"Recompiled [OK] "$(FCOLOR)"
# compile bonus part
bonus:
	@echo "Compiling Bonus$(NAME)..."
	@$(CC) $(FLAGS) -I$(GNL_DIR_BONUS) -I$(SRC_DIR) $(GNL_FILES_BONUS) $(TESTER_BONUS) -o $(BIN_DIR)$(NAME)

# clean all
clean:
	@echo "$(RED)Cleaning $(PURPLE)$(NAME)...$(FCOLOR)"
	@sleep 0.2
	@rm -rf $(BIN_DIR)$(NAME)
	@echo "$(GREEN)"Cleaned [OK] "$(FCOLOR)"
