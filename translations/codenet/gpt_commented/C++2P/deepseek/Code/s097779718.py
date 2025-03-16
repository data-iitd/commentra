def euclid(x, y):
    # Ensure x is the larger number
    if x < y:
        x, y = y, x

    # If y divides x evenly, y is the GCD
    if x % y == 0:
        return y

    # Recursively call Euclid with y and the remainder of x divided by y
    return euclid(y, x % y)

def main():
    A, B = map(int, input().split())  # Read input values for A and B

    # Calculate and output the Least Common Multiple (LCM) using the formula LCM(A, B) = (A * B) / GCD(A, B)
    print((A * B) // euclid(A, B))

main()

