# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_rpn.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 15:07:28 by omartela          #+#    #+#              #
#    Updated: 2025/03/20 15:28:27 by omartela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Path to your compiled program
PROGRAM="./RPN"

# List of test cases
TEST_CASES=(
    "3 4 +"          # Valid: 7
    "5 1 2 + 4 * + 3 -" # Valid: 14
    "1 1 + 1"        # Invalid: Extra operand
    "4 0 /"          # Invalid: Division by zero
    "3 a +"          # Invalid: Non-numeric operand
    "42"             # Valid: Single operand
    "1 +"            # Invalid: Not enough operands
    "1 1 +"          # Valid: 2
    "7 2 3 * -"      # Valid: 1
    "2147483647 1 +" # Error: overflow
    "-2147483648 1 -" # Error: overflow
    "100000 100000 *" # Error: overflow
    "-2147483648 -1 /" # Error: overflow
    "2147483647 0 +" # Valid: 2147483646
    "-2147483648 0 +" # Valid: -2147483648
    "0 0 +"          # Valid: 0
    "1"             # Valid: 1
)

# Loop through each test case
for TEST in "${TEST_CASES[@]}"; do
    echo "Input: \"$TEST\""
    $PROGRAM "$TEST"
    echo "---------------------------------"
done
