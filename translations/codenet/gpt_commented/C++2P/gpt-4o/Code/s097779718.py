# Function to compute the Greatest Common Divisor (GCD) using Euclid's algorithm
def euclid(x, y):
    # Ensure x is the larger number
    if x < y:
        x, y = y, x  # Swap x and y if x is smaller

    # If y divides x evenly, y is the GCD
    if x % y == 0:
        return y

    # Recursively call euclid with y and the remainder of x divided by y
    return euclid(y, x % y)

# Main function
if __name__ == "__main__":
    A, B = map(int, input().split())  # Read input values for A and B

    # Calculate and output the Least Common Multiple (LCM) using the formula LCM(A, B) = (A * B) / GCD(A, B)
    print((A * B) // euclid(A, B))  # Use integer division

# <END-OF-CODE>
