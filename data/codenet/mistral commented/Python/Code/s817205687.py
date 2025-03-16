# 参考 : https://at274.hatenablog.com/entry/2020/01/15/060000
# This code calculates the number of pairs that can be formed from a given list of integers
# such that each pair's elements have the same number of 2's as factors.

from functools import reduce  # Import reduce function for calculating the product of a list
import math


# Function to calculate the least common multiple of two numbers
def lcm(x, y):
    return (x * y) // math.gcd(x, y)


# Function to calculate the least common multiple of a list of numbers
def lcm_list(numbers):  # リストを投げると全要素のlcmが返ってくる
    return reduce(lcm, numbers, 1)


# Input the number of elements N and the number M from the user
N, M = map(int, input().split())

# Initialize a list A with N integers
A = list(map(int, input().split()))

# Replace each even number in A with its half
A = [a // 2 for a in A]

# Initialize a variable to store the number of 2's as factors for the first element in A
count_div_2 = None

# Check each element in A and store the number of 2's as factors
for a in A:
    # Initialize a counter for the number of 2's as factors
    cnt = 0
    # Divide the number by 2 until it's no longer even
    while a % 2 == 0:
        a //= 2
        cnt += 1

    # If this is the first element, save its number of 2's as factors
    if count_div_2 is None:
        count_div_2 = cnt
    # If the number of 2's as factors is different from the first element, exit the loop and print 0
    elif cnt != count_div_2:
        print(0)
        exit()

# Calculate the least common multiple of all elements in A
my_lcm = lcm_list(A)

# If the least common multiple is greater than M, print 0 and exit
if my_lcm > M:
    print(0)
    exit()

# Calculate the number of pairs that can be formed using the least common multiple and M
tmp = M // my_lcm
ans = (tmp + 1) // 2

# Print the answer
print(ans)
