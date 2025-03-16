# Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
def euclid(x, y):
    # Swap x and y if x is smaller than y
    if x < y:
        x, y = y, x

    # If x is divisible by y, return y as the GCD
    if x % y == 0:
        return y

    # Recursively call euclid function with y and the remainder of x divided by y
    return euclid(y, x % y)

# Main function
if __name__ == "__main__":
    # Read input values of A and B from the standard input
    A, B = map(int, input().split())

    # Calculate the product of A and B and print the result divided by their GCD
    print((A * B) // euclid(A, B))

# <END-OF-CODE>
