def max_left(n):
    # Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n - 2 if n > 2 else 0


def main():
    # Read the number of test cases from the input
    t = int(input())

    # Iterate through each test case
    for _ in range(t):
        # Read the number of elements in the array
        n = int(input())

        # Print the maximum left sum
        print(max_left(n))


# Call the main function
main()

