import math

# Define input variables and some auxiliary variables
n, a = [], []
p, b, c = 0, 0, 0

# Function to calculate nPr (n choose r)
def nPr(n, r):
    # Initialize result to 1
    res = 1
    # Iterate from 0 to r and multiply result with (n-i)
    for i in range(r):
        res *= (n - i)
    # Return the result
    return res

# Function to calculate nCr (n choose r)
def nCr(n, r):
    # Initialize result to 1
    res = 1
    # Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
    for i in range(r):
        res *= (n - i)
        res //= (i + 1)
    # Return the result
    return res

# Main function
if __name__ == "__main__":
    # Read input values of n and p from the user
    n, p = map(int, input().split())
    # Initialize b and c to count the number of even and odd elements in the array a
    a = list(map(int, input().split()))
    for i in range(n):
        if a[i] % 2 == 0:
            b += 1
        else:
            c += 1
    # Calculate the sum of 2^b and c
    bsum = 2 ** b
    # Calculate the sum of nCr(c, i) for i from 0 to c
    csum = 0
    if p == 0:
        for i in range(c + 1):
            if i % 2 == 0:
                csum += nCr(c, i)
    else:
        for i in range(c + 1):
            if i % 2 == 1:
                csum += nCr(c, i)
    # Multiply bsum and csum and store the result in ans
    ans = bsum * csum
    # Print the final answer
    print(ans)
