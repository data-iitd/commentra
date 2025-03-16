
import math

N, K = map(int, input().split()) # 1. Reading the values of N and K from the standard input.

v = list(map(int, input().split())) # 2. Initializing a list to store N integers.

# 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
count = math.ceil((N - 1) / (K - 1))
print(count) # 5. Outputting the calculated count.
