GTEST_DIR		=	./googletest/googletest
GMOCK_DIR		=	./googletest/googlemock

GTEST_SRCS		=	$(GTEST_DIR)/src/gtest-all.cc $(GTEST_DIR)/src/gtest_main.cc
GTEST_OBJS		=	$(GTEST_SRCS:.cc=.o)

NAME			=	unit_test

LIBASM_DIR		=	../

TEST_DIR		=	./src
TEST_SRCS		=	$(TEST_DIR)/ft_strlen-test.cpp
TEST_OBJS		=	$(TEST_SRCS:.cpp=.o)
TEST_HEADERS	=	./src

CXX				=	g++

CPPFLAGS		+=	-isystem $(GTEST_DIR)/include -isystem $(GMOCK_DIR)/include \
					-isystem $(GTEST_DIR) -isystem $(GMOCK_DIR) \
					-isystem $(TEST_HEADERS)

CXXFLAGS		+=	-g -Wall -Wextra -Werror -pthread -std=c++17
LDFLAGS			=	-lpthread -L$(LIBASM_DIR) -lasm

.PHONY: all clean fclean re run run_valgrind test

all: $(NAME)

$(NAME): $(GTEST_OBJS) $(TEST_OBJS) Makefile
		$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(GTEST_OBJS) $(TEST_OBJS) -o $(NAME) $(LDFLAGS)

run: re
		./$(NAME) --gtest_brief=1

run_valgrind: re
		valgrind -q --log-file=output --leak-check=full --trace-children=yes ./$(NAME) --gtest_brief=1

clean:
		$(RM) $(NAME) $(TEST_OBJS)

fclean: clean
		$(RM) $(GTEST_OBJS)

re: clean all
