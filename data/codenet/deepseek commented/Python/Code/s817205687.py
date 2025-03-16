from functools import reduce
import math

# Function to calculate the least common multiple (LCM) using the greatest common divisor (GCD)
def lcm(x, y):
    return (x * y) // math.gcd(x, y)

# Function to calculate the LCM of a list of numbers using the reduce function
def lcm_list(numbers):  # リストを投げると全要素のlcmが返ってくる
    return reduce(lcm, numbers, 1)

# Read two integers N and M from input
N, M = map(int, input().split())

# Read a list of integers A from input
A = list(map(int, input().split()))

# Replace each element in A with half of itself, assuming all elements are initially even
A = [a // 2 for a in A]

# Check if all elements in A are divisible by 2 the same number of times
count_div_2 = None
for a in A:
    cnt = 0
    while a % 2 == 0:
        a //= 2
        cnt += 1
    # Save the count for the first element
    if count_div_2 is None:
        count_div_2 = cnt
    # Check if all elements have the same number of divisions by 2
    elif cnt != count_div_2:
        print(0)
        exit()

# Calculate the LCM of the modified list A
my_lcm = lcm_list(A)

# If the LCM exceeds M, print 0 and exit
if my_lcm > M:
    print(0)
    exit()

# Calculate how many times the LCM can fit into M
tmp = M // my_lcm

# Calculate the number of valid integers that can be formed
ans = (tmp + 1) // 2
print(ans)