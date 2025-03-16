
import math

# Read two integers a and b from input
a = int(input())
b = int(input())

# Calculate the number formed by concatenating a and b
num = a * 10**len(str(b)) + b

# Initialize a variable to find the square root of num
i = 1
# Loop to check if there exists an integer i such that i*i equals num
while i <= 100100:
    if i * i == num:
        print("Yes")
        break
    i += 1
else:
    print("No")
