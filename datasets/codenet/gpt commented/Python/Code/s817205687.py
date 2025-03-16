# 参考 : https://at274.hatenablog.com/entry/2020/01/15/060000
from functools import reduce
import math

# Function to calculate the least common multiple (LCM) of two numbers
def lcm(x, y):
    return (x * y) // math.gcd(x, y)

# Function to calculate the LCM of a list of numbers
def lcm_list(numbers):  # リストを投げると全要素のlcmが返ってくる
    return reduce(lcm, numbers, 1)

# Read input values for N and M
N, M = map(int, input().split())
# Read the list of integers A
A = list(map(int, input().split()))

# Replace each element in A with its half (assuming all elements are even)
A = [a // 2 for a in A]

# Initialize a variable to track the count of divisions by 2
count_div_2 = None
# Iterate through each element in the modified list A
for a in A:
    cnt = 0
    # Count how many times the element can be divided by 2
    while a % 2 == 0:
        a //= 2
        cnt += 1
    # Store the count for the first element without condition
    if count_div_2 is None:
        count_div_2 = cnt
    # For subsequent elements, check if the count matches the first
    elif cnt != count_div_2:
        print(0)  # If counts do not match, print 0 and exit
        exit()

# Calculate the LCM of all elements in A
# This LCM must be an odd multiple to satisfy the problem's conditions
my_lcm = lcm_list(A)
# If the LCM exceeds M, it's impossible to form any valid numbers
if my_lcm > M:
    print(0)  # Print 0 and exit if LCM is greater than M
    exit()

# Calculate how many multiples of my_lcm fit into M
tmp = M // my_lcm
# Determine the number of valid even multiples that can be formed
# The formula accounts for pairs of multiples (1,2), (3,4), etc.
ans = (tmp + 1) // 2
# Print the final answer
print(ans)
