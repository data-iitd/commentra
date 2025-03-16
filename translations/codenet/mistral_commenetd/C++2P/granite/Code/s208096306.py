

# Python code to find the greatest common divisor (GCD) of two integers

def gcd(a, b):
    if a < b:
        a, b = b, a # Swap 'a' and 'b' if 'a' is smaller than 'b'

    # Use Euclidean algorithm to find the GCD of 'a' and 'b'
    while (r := a%b) > 0:
        a = b
        b = r

    # Return the GCD of 'a' and 'b'
    return b

if __name__ == "__main__":
    n = int(input()) # Read the number of integers 'n' from the standard input

    ans = int(input()) # Read the first integer 'ans' from the standard input and store it in the variable 'ans'

    # Read and process the remaining integers
    for i in range(1, n):
        a = int(input()) # Read the next integer 'a' from the standard input and store it in the variable 'a'

        # Update the answer by finding the GCD of the current answer and the new integer 'a'
        ans = gcd(ans, a)

    print(ans) # Print the final answer to the standard output

