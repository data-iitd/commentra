# Step 1: Input Handling
# The program starts by taking a string input from the user.
source = input()

# It checks if the length of the input string is within the valid range (1 to 10 characters).
# If not, it returns -1.
if len(source) > 10 or len(source) < 1:
    print(-1)
    exit()

# Step 2: Calculation Setup
# The program calculates the maximum number of combinations that can be formed
# by placing '+' signs between the digits of the input string.
# This is done using the formula 2^(n-1), where n is the length of the input string.
max_i = 2 ** (len(source) - 1)

# Step 3: Iterating Over Combinations
# The program iterates over all possible combinations of placing '+' signs between the digits.
# For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
sum = 0
for i in range(max_i):
    plus = bin(i)[2:]
    number = 0
    working = source
    while plus!= '':
        i = 0
        while plus[i] == '0':
            i += 1
        number += float(working[:i + 1])
        plus = plus[i + 1:]
        working = working[i + 1:]
    number += float(working)
    sum += number

# Step 4: Output
# Finally, the program outputs the sum of all possible combinations.
print(sum)

# 