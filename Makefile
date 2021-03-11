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

COMMON_SRC	=	${SRC_DIR}error_handling.c	\
				${SRC_DIR}check_file.c	\
				${SRC_DIR}load_file.c	\
				${SRC_DIR}check_file_format.c	\
				${SRC_DIR}get_file_architecture.c	\

NM_DIR			=	$(SRC_DIR)nm/

MAIN_NM			=	${NM_DIR}main.c

SRC_NM			=	\
					${NM_DIR}main_nm.c	\
					${NM_DIR}get_function_architecture_nm.c	\
					${NM_DIR}nm_32b.c	\
					${NM_DIR}nm_64b.c	\
					${NM_DIR}get_symbol_char_32b.c	\
					${NM_DIR}get_symbol_char_64b.c	\
					${NM_DIR}sort_symbol_names.c	\
					${NM_DIR}print_symbols.c	\
				# ${NM_DIR}example.c

OBJ_NM			=	$(COMMON_SRC:.c=.o)
OBJ_NM			+=	$(SRC_NM:.c=.o)
OBJ_NM			+=	$(MAIN_NM:.c=.o)

NAME_NM			=	my_nm

OBJDUMP_DIR			=	$(SRC_DIR)objdump/

MAIN_OBJDUMP		=	${OBJDUMP_DIR}main.c

SRC_OBJDUMP			=		\
						${OBJDUMP_DIR}main_objdump.c	\
						${OBJDUMP_DIR}get_function_architecture_objdump.c	\
						${OBJDUMP_DIR}objdump_64b.c	\
						${OBJDUMP_DIR}objdump_32b.c	\
						${OBJDUMP_DIR}print_section_name_64b.c	\
						${OBJDUMP_DIR}print_section_name_32b.c	\
						${OBJDUMP_DIR}print_section_body.c	\
						${OBJDUMP_DIR}print_section_body_64b.c	\
						${OBJDUMP_DIR}print_section_body_32b.c	\
						# ${OBJDUMP_DIR}example.c

OBJ_OBJDUMP			=	$(COMMON_SRC:.c=.o)
OBJ_OBJDUMP			+=	$(SRC_OBJDUMP:.c=.o)
OBJ_OBJDUMP			+=	$(MAIN_OBJDUMP:.c=.o)

NAME_OBJDUMP		=	my_objdump
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

## Shared Library
# SHARED_LIB
SHARED_LIB_NAME	=	libnm.so

SHARED_LIB_DIR	=	./src/

SHARED_LIB_SRC	=		\
					# $(SHARED_LIB_DIR)example.c	\

SHARED_LIB_OBJ	=	$(SHARED_LIB_SRC:.c=.o)
## !Shared Library

## Tests
TEST_NAME	=	unit_tests

TEST_FLAGS	=   --coverage -lcriterion

TEST_DIR	=	./tests/

TEST_FILES	=	$(TEST_DIR)criterion_utils.c	\
				$(TEST_DIR)file_load_tests.c	\
				#  $(TEST_DIR)unit_tests.c

TEST_OBJ	=	$(COMMON_SRC:.c=.o)
TEST_OBJ	+=	$(SRC_NM:.c=.o)
TEST_OBJ	+=	$(SRC_OBJDUMP:.c=.o)
TEST_OBJ	+=	$(TEST_FILES:.c=.o)
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


all:		nm objdump

nm:			$(OBJ_NM)
			@$(ECHO)
			$(MSG_POST_BUILD)
			@$(ECHO)
			$(CC) -o $(NAME_NM) $(OBJ_NM) \
			&& ($(MSG_BUILD_SUCCESS) $(NAME_NM)$(DEFAULT)) \
			|| ($(MSG_BUILD_FAILURE) $(NAME_NM)$(DEFAULT))
			@($(ECHO))
			@($(ECHO))

objdump:	$(OBJ_OBJDUMP)
			@$(ECHO)
			$(MSG_POST_BUILD)
			@$(ECHO)
			$(CC) -o $(NAME_OBJDUMP) $(OBJ_OBJDUMP) \
			&& ($(MSG_BUILD_SUCCESS) $(NAME_OBJDUMP)$(DEFAULT)) \
			|| ($(MSG_BUILD_FAILURE) $(NAME_OBJDUMP)$(DEFAULT))
			@($(ECHO))
			@($(ECHO))
lib:
			@$(ECHO)
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make -C $$MAKE_PATH -s ; \
			done

lib_clean:
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make clean -C $$MAKE_PATH -s ; \
			done

clean:		lib_clean
			$(RM) $(RM_FLAGS)
			$(RM) $(OBJ_NM)
			@($(MSG_CLEAN)$(NAME_NM)$(DEFAULT))
			$(RM) $(OBJ_OBJDUMP)
			@($(MSG_CLEAN)$(NAME_OBJDUMP)$(DEFAULT))
			$(RM) $(TEST_OBJ)
			@($(MSG_CLEAN)$(TEST_NAME)$(DEFAULT))
			@($(ECHO))
			@($(ECHO))

lib_fclean:
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make fclean -C $$MAKE_PATH -s ; \
			done

fclean:		lib_fclean clean
			$(RM) $(NAME_NM)
			@($(MSG_FCLEAN)$(NAME_NM)$(DEFAULT))
			$(RM) $(NAME_OBJDUMP)
			@($(MSG_FCLEAN)$(NAME_OBJDUMP)$(DEFAULT))
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

shared_lib:	C_FLAGS += -fPIC
shared_lib:	$(SHARED_LIB_OBJ)
			@$(ECHO)
			$(CC) -shared -o $(SHARED_LIB_NAME) $(SHARED_LIB_OBJ) \
			&& $(MSG_BUILD_SUCCESS) \
			|| $(MSG_BUILD_FAILURE)
			@$(ECHO)

re_shared_lib:	fclean shared_lib

shared:	shared_lib
shared:	LD_FLAGS += -L. -l:./$(SHARED_LIB_NAME)
shared:	$(NAME)

re_shared:	fclean shared

%.o :		%.c
			$(CC) -c -o $@ $^ $(C_FLAGS) \
			&& $(MSG_COMPILATION_SUCCESS) \
			|| $(MSG_COMPILATION_FAILURE) \
			&& $(ECHO) $(BOLD) $< | rev | cut -d'/' --fields="1 2" | rev

.PHONY:		all title clean fclean re tests_run debug lib probuilding
## !Rules
