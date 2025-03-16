# Declare the main function
def main():
    # Read data from the standard input and store it into x and a
    x, a = map(int, input().split())

    # Check if x is greater than or equal to a
    result = int(x >= a)

    # Multiply the result by 10
    result *= 10

    # Print the result to the standard output
    print(result)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
