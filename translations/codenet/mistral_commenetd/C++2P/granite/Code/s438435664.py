
# Python code
import sys

# Function to find the greatest common divisor (GCD) of two numbers
def gcd(x, y):
    # Base case: if x is smaller than y, swap x and y
    if x < y:
        x, y = y, x

    # Recursive case: find the remainder of x divided by y and repeat
    while y > 0:
        r = x % y
        x = y
        y = r

    # Return the GCD (the last non-zero value of x)
    return x

# Function to find the least common multiple (LCM) of two numbers
def lcm(x, y):
    # Return the product of x and y divided by their GCD
    return x // gcd(x, y) * y

# Function to calculate the factorial (kaijo) of a number
def kaijo(k):
    sum = 1
    # Calculate the factorial by multiplying the number with all the numbers less than it
    for i in range(1, k + 1):
        sum *= i
        # Modulo the result by 10000000000+7 to keep the result within a certain range
        sum %= 10000000000 + 7
    # Return the result
    return sum

# Main function
def main():
    # Read the input values for n and k from the standard input
    n, k = map(int, sys.stdin.readline().split())

    # Initialize a variable to store the sum of the results
    sum = 0

    # Iterate through all possible block sizes from 1 to n
    for b in range(1, n + 1):
        # Calculate the number of blocks of size b that can fit into n+1
        cnt = (n + 1) // b

        # Calculate the remainder of n+1 when divided by b
        md = (n + 1) % b

        # Add the number of blocks of size b that cover k or more numbers to the sum
        sum += cnt * max(b - k, 0) + max(md - k, 0)

    # Print the result to the standard output
    print(sum)

# Call the main function
if __name__ == "__main__":
    main()

