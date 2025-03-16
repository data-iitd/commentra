import math

# Reading the first long integer input N
N = int(input())

# Reading the next 5 long integer inputs and finding the minimum
min_value = int(input())
for _ in range(4):
    min_value = min(min_value, int(input()))

# Printing the answer using the p method
print(math.ceil(N / min_value) + 4)
