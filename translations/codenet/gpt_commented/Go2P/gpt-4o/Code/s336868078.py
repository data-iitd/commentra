import sys

# Function to solve the problem based on the given parameters a, b, and c
def solve(a, b, c):
    # Check if c is equal to the sum of a and b
    if c == a + b:
        # If true, calculate the result as b + c
        return b + c
    elif c - 1 > a + b:
        # If c-1 is greater than the sum of a and b, calculate the difference
        temp = (c - 1) - (a + b)
        # Adjust the result based on the calculated difference
        return b + c - temp
    else:
        # If neither condition is met, simply return b + c
        return b + c

def main():
    # Read three integers from standard input
    a, b, c = map(int, sys.stdin.readline().strip().split())
    
    # Call the solve function with the input values and store the result
    ans = solve(a, b, c)
    
    # Print the result to standard output
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
