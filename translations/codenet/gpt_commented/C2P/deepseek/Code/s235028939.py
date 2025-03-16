def main():
    # Read two integers from standard input
    # n represents the number of rows, and m represents the number of columns
    n, m = map(int, input().split())

    # Calculate the product of (n - 1) and (m - 1)
    # This represents the number of internal edges in a grid of n by m cells
    result = (n - 1) * (m - 1)

    # Print the result to standard output
    print(result)


# Call the main function to execute the program
if __name__ == "__main__":
    main()
