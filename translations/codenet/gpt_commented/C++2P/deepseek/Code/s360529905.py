def main():
    # Read the number of elements
    N = int(input())

    # Read elements into array 'a' and copy them to array 'b'
    a = list(map(int, input().split()))
    b = a.copy()

    # Sort the array 'b' to find the median values
    b.sort()

    # Determine the two middle values (for even-sized arrays)
    frontHalf = b[N // 2 - 1]  # Value just before the median
    backHalf = b[N // 2]        # Median value

    # Output the appropriate value based on the original array 'a'
    for element in a:
        # If the current element is less than the backHalf (median), print backHalf
        if element < backHalf:
            print(backHalf)
        # Otherwise, print frontHalf
        else:
            print(frontHalf)

# Call the main function
if __name__ == "__main__":
    main()
