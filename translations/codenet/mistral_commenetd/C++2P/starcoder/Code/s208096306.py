
# Define a function to find the greatest common divisor (GCD) of two integers
def gcd(a, b):
    if a < b:
        a, b = b, a # Swap 'a' and 'b' if 'a' is smaller than 'b'

    # Use Euclidean algorithm to find the GCD of 'a' and 'b'
    while b > 0:
        a, b = b, a % b

    # Return the GCD of 'a' and 'b'
    return a

# Read the number of integers 'n' from the standard input
n = int(input())

# Read the first integer 'ans' from the standard input
ans = int(input())

# Read and process the remaining integers
for i in range(1, n):
    # Read the next integer 'a' from the standard input
    a = int(input())

    # Update the answer by finding the GCD of the current answer and the new integer 'a'
    ans = gcd(ans, a)

# Print the final answer to the standard output
print(ans)

