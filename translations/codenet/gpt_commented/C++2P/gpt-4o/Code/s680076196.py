# Define the main function
def main():
    # Read four integer values from standard input
    a, b, c, d = map(int, input().split())

    # Calculate the product of the differences between the first two and the last two integers
    # This represents the area of a rectangle defined by the points (a, b) and (c, d)
    print((a - c) * (b - d))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
