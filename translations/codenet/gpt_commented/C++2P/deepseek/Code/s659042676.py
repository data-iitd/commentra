def main():
    # Read two integer values from standard input
    a, b = map(int, input().split())

    # Calculate and output the result of the expression (6 - a - b)
    # This assumes that a and b are part of a game or problem where their sum should not exceed 6
    result = 6 - a - b
    print(result)


# Call the main function
if __name__ == "__main__":
    main()
