def main():
    # Read input values for A and B from the user
    A, B = map(int, input().split())

    # Check if A is between 6 (inclusive) and 13 (exclusive)
    if 6 <= A < 13:
        # If true, output half of B
        print(B // 2)

    # Check if A is less than 6
    if A < 6:
        # If true, output 0
        print(0)

    # Check if A is greater than or equal to 13
    if A >= 13:
        # If true, output the value of B
        print(B)

# Call the main function
main()

