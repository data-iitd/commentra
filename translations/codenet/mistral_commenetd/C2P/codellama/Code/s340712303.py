
#include<stdio.h>
#define N 2000
num1 = 0
math = [0] * (N + 1)

# Initialize variables
a = 0
num2 = 0
ans = 0
sum = 0
i = 0
j = 0

# Initialize math array with first element as 1
math[0] = 1

# Read the number of integers to be input
print("Enter the number of integers to be input:\n")
num1 = int(input())

# Read each integer and calculate its sum
for i in range(num1):
    print("Enter an integer:\n")
    a = int(input())

    # Add the current integer to the sum
    sum += a

    # Mark all the previous numbers as visited
    for j in range(sum - a, -1, -1):
        if math[j] == 1:
            math[j + a] = 1

# Read the number of integers to be checked
print("Enter the number of integers to be checked:\n")
num2 = int(input())

# Check each integer and print the result
for i in range(num2):
    print("Enter an integer to check:\n")
    ans = int(input())

    # Check if the current integer is marked as visited
    if math[ans] == 1:
        print("yes\n")
    else:
        print("no\n")

# Return 0 to indicate successful execution
return 0

