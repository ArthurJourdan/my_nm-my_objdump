##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compilation
##

## Aliases
ECHO	=	   /bin/echo -e
DEFAULT =	   "\033[00m"

## Print colors
DEFAULT =	   "\e[0m"
BOLD	=	   "\e[1m"
DIM	 	=	   "\e[2m"
UNDLN   =	   "\e[4m"
SHINE   =	   "\e[5;37m"
RODE	=	   "\e[9;37m"

BLACK   =	   "\e[30m"
RED	 	=	   "\e[31m"
GREEN   =	   "\e[32m"
YELLOW  =	   "\e[33m"
BLUE	=	   "\e[34m"
MAGEN   =	   "\e[35m"
CYAN	=	   "\e[36m"
WHITE   =	   "\e[1;37m"
## !Print colors

## Shortcut / unity of variables
CC			= 	@gcc

INCLUDE		=	-I include

C_FLAGS		=	-W -Wall -Wextra $(INCLUDE)

RM_FLAGS	=	*.gcda *.gcno src/*.gcda src/*.gcno

RM			=	@rm -rf
## !Shortcut / unity of variables

## Source
SRC_DIR		=	./src/

SRC			=	${SRC_DIR}main.c	\
				# ${SRC_DIR}example.c

OBJ			=	$(SRC:.c=.o)

NAME		=	executable
## Source

## Library
LIB_DIR		=	./lib/

SRC_LIB		=	linked_list	\
				print		\
				my			\
				file		\

LIB_PATHS	=   $(LIB_DIR)lib_my			\
				$(LIB_DIR)lib_file			\
				$(LIB_DIR)lib_linked_list	\
				$(LIB_DIR)lib_print			\

LIBRARIES   =	$(SRC_LIB:%=-l%)

LD_FLAGS	=	-L$(LIB_DIR) $(LIBRARIES)
## !Library


## Tests
TEST_NAME	=	unit_tests

TEST_FLAGS	=   --coverage -lcriterion

TEST_DIR	=	./tests/

TEST_SRC	=		\
				# ${SRC_DIR}example.c

TEST_FILES	=		\
				#  $(TEST_DIR)unit_tests.c

TEST_OBJ	+=	$(TEST_SRC:.c=.o)
TEST_OBJ	=	$(TEST_FILES:.c=.o)
## !Tests
## !Aliases


## Rules

## Messages
MSG_POST_BUILD	=	@$(ECHO) $(BOLD) $(YELLOW) Built $(NAME) $(WHITE) "\t$(C_FLAGS)" $(DEFAULT)

MSG_BUILD_SUCCESS	= 	$(ECHO) $(BOLD) $(GREEN)"\n-> BUILD SUCCESS"$(YELLOW)"\n\t\t\t"

MSG_BUILD_FAILURE	=	$(ECHO) $(BOLD) $(RED)"\n-> BUILD FAILED"$(YELLOW)"\n\t\t\t"

MSG_COMPILATION_SUCCESS	=	$(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE)

MSG_COMPILATION_FAILURE	=	$(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE)

MSG_CLEAN	=	$(ECHO) $(BOLD) $(GREEN)✓" CLEAN "

MSG_FCLEAN	=	$(ECHO) $(BOLD) $(GREEN)✓" FULL CLEAN "
## !Messages


all:		$(NAME)

lib:
			@$(ECHO)
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make -C $$MAKE_PATH -s ; \
			done

$(NAME):	lib  $(OBJ)
			@$(ECHO)
			$(MSG_POST_BUILD)
			@$(ECHO)
			$(CC) -o  $(NAME) $(OBJ) $(LD_FLAGS) \
			&& ($(MSG_BUILD_SUCCESS) $(NAME)$(DEFAULT)) \
			|| ($(MSG_BUILD_FAILURE) $(NAME)$(DEFAULT))
			@($(ECHO))
			@($(ECHO))

clean:
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make clean -C $$MAKE_PATH -s ; \
			done
			$(RM) $(RM_FLAGS)
			$(RM) $(OBJ) \
			&& @($(MSG_CLEAN)$(NAME)$(DEFAULT))
			$(RM) $(TEST_OBJ) \
			&& @($(MSG_CLEAN)$(TEST_NAME)$(DEFAULT))
			@($(ECHO))
			@($(ECHO))

fclean:
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make fclean -C $$MAKE_PATH -s ; \
			done
			$(RM) $(OBJ)
			$(RM) $(RM_FLAGS)
			$(RM) $(NAME)
			@($(MSG_FCLEAN)$(NAME)$(DEFAULT))
			$(RM) $(TEST_NAME)
			@($(MSG_FCLEAN)$(TEST_NAME)$(DEFAULT))
			@($(ECHO))
			@($(ECHO))

re:		 fclean all

tests_run:	fclean lib $(TEST_OBJ)
			@$(ECHO)
			$(CC) -o $(TEST_NAME) $(TEST_OBJ) $(TEST_FLAGS) $(LD_FLAGS) \
			&& ($(MSG_BUILD_SUCCESS) $(NAME)$(DEFAULT)) \
			|| ($(MSG_BUILD_FAILURE) $(NAME)$(DEFAULT))
			@($(ECHO))
			@($(ECHO))
			@if [ -f $(TEST_NAME) ]; \
			then \
				./$(TEST_NAME) ; \
			fi
			@$(ECHO)

debug:		C_FLAGS += -g
debug:		re


%.o :		%.c
			$(CC) -c -o $@ $^ $(C_FLAGS) \
			&& $(MSG_COMPILATION_SUCCESS) \
			|| $(MSG_COMPILATION_FAILURE) \
			&& $(ECHO) $(BOLD) $< | rev | cut -d'/' --fields="1 2" | rev

.PHONY:		all title clean fclean re tests_run debug lib probuilding
## !Rules
