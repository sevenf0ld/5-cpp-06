# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 12:19:46 by maiman-m          #+#    #+#              #
#    Updated: 2024/04/17 12:21:57 by maiman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = typeinfo

RESET = reset && make re && reset

SILENT_FCLEAN = make -s fclean

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g3 -pedantic

CPPFLAGS = -I include

SOURCE = main.cpp Base.cpp

SRCS = $(addprefix src/,$(SOURCE))
	   
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(CPPFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run:
	$(RESET) && ./$(NAME) && $(SILENT_FCLEAN)

leaks:
	$(RESET) && leaks --atExit -- ./$(NAME) && $(SILENT_FCLEAN)

debug:
	$(RESET) && lldb -- $(NAME) && $(SILENT_FCLEAN)

valgrind:
	$(RESET) && valgrind --leak-check=full --tool=memcheck -s --track-origins=yes ./$(NAME) && $(SILENT_FCLEAN)

.PHONY: all clean fclean re
