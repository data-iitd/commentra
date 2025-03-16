# Importing required libraries
import fractions
import math

# Taking input of n and number of distinct numbers
n, num = map(int, input().split())

# Creating a set of distinct numbers
num_set = set(map(lambda x: int(x), input().split()))

# Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
two_times_set = set()
for i in num_set:
    # Initializing a counter to keep track of the number of times 2 is divided
    power_of_two = 0
    
    # Dividing i by 2 repeatedly until it is no longer odd
    while i % 2 == 0:
        power_of_two += 1
        i //= 2

    # If the number of times 2 is divided is not exactly 1, then the answer is 0
    if power_of_two > 1:
        print(0)
        break

    # Add the power of 2 to two_times_set
    two_times_set.add(power_of_two)

# If the size of two_times_set is not exactly 1, then the answer is 0
if len(two_times_set) != 1:
    print(0)
    exit()

# Finding the least common multiple of all numbers in num_set
num_list = list(num_set)
lcm = num_list[0]

# Finding the least common multiple of the first number and the next number
for i in range(1, len(num_list)):
    lcm = lcm * num_list[i] // fractions.gcd(lcm, num_list[i])

# Printing the answer
print((num - lcm // 2) // (lcm) + 1)
