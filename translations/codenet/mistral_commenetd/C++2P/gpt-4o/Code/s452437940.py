# Main function begins here
def main():
    # Read input values from standard input
    a, b, x = map(int, input().split())

    # Calculate the difference between the number of complete x-blocks in b and a
    s = (b // x) - (a // x)

    # If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
    if a % x == 0:
        s += 1

    # Print the result to standard output
    print(s)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
