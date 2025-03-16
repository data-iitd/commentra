def main():
    # Read two integers from the standard input
    n, m = map(int, input().split())

    # Calculate the product of (n - 1) and (m - 1)
    result = (n - 1) * (m - 1)

    # Print the result to the standard output
    print(result)


# Call the main function to execute the program
if __name__ == "__main__":
    main()
