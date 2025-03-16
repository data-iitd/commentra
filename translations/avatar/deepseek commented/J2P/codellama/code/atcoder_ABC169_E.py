
import sys
import math

# Declare and initialize a constant integer
num = 998244353

# Create a BufferedReader object to read input from the standard input
bf = sys.stdin

# Create a PrintWriter object to write output to the standard output
out = sys.stdout

# Read the number of elements 'n' from the input
n = int(bf.readline())

# Create two ArrayList objects to store the pairs of integers
ai = []
bi = []

# Read the pairs of integers from the input and store them in the ArrayList objects
for i in range(n):
    st = bf.readline().split()
    ai.append(int(st[0]))
    bi.append(int(st[1]))

# Sort both the ArrayList objects
ai.sort()
bi.sort()

# Check if 'n' is odd or even
if n % 2 == 1:
    # If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
    out.write(str(bi[int(math.floor(n / 2))] - ai[int(math.floor(n / 2))] + 1) + '\n')
    out.close()
else:
    # If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
    b = (ai[int(math.floor(n / 2))] + ai[int(math.floor(n / 2)) - 1]) / 2
    c = (bi[int(math.floor(n / 2))] + bi[int(math.floor(n / 2)) - 1]) / 2
    out.write(str(int(2 * (c - b) + 1)) + '\n')
    out.close()

# 