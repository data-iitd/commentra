def main():
    # Read the number of elements from standard input
    n = int(input())

    # Initialize a list to hold the float numbers
    a = []

    # Read n float numbers from standard input into the list
    for _ in range(n):
        a.append(float(input()))

    # Perform a series of operations to reduce the list
    for _ in range(n - 1):
        # Sort the list in ascending order
        a.sort()

        # Create a new list to hold the modified values
        na = []

        # Append all elements from the third element onward to the new list
        na.extend(a[2:])

        # Calculate the average of the first two elements and append it to the new list
        na.append((a[0] + a[1]) / 2)

        # Update the original list to be the new list
        a = na

    # Print the final remaining element in the list
    print(a[0])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
