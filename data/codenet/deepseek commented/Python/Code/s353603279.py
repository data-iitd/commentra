X = int(input())  # Taking an integer input X, which represents the total amount of money

# Calculating the number of 500 coins (h) in X
# Each 500 coin is worth 1000 points
h = X // 500

# Calculating the remainder of X when divided by 500
# This remainder is then used to find the number of 5 coins (a)
remainder = X % 500

# Calculating the number of 5 coins (a) in the remainder
# Each 5 coin is worth 5 points
a = remainder // 5

# Computing the total value (y)
# Each 500 coin is worth 1000 points and each 5 coin is worth 5 points
# Therefore, the total value is calculated by multiplying the number of 500 coins by 1000 and the number of 5 coins by 5, then adding these two values together
y = h * 1000 + a * 5

# Printing the result
print(y)