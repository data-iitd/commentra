# Include necessary headers for input and output operations

# Define a type alias 'll' for 'long long' (not needed in Python as int can handle large values)

def main():
    x1, y1, x2, y2 = map(int, input().split())  # Read four integers from the standard input

    # Calculate the differences between the coordinates
    dx = x2 - x1
    dy = y2 - y1

    # Compute the new coordinates based on the differences
    x3 = x2 - dy
    y3 = y2 + dx
    x4 = x1 - dy
    y4 = y1 + dx

    # Output the new coordinates
    print(x3, y3, x4, y4)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
