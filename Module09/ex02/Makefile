# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 16:18:22 by omartela          #+#    #+#              #
#    Updated: 2025/03/21 12:14:03 by omartela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++

TARGET = PmergeMe
INC_DIR = inc
SRC = src/main.cpp src/RPN.cpp
OBJ = $(SRC:.cpp=.o)
CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(COMPILER) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ) $(TARGET)

re: fclean all
