def main():
    # Infinite loop to continuously accept input until a termination condition is met
    while True:
        # Read the values of n (number of elements) and r (number of operations)
        n, r = map(int, input().split())
        
        # Check for termination condition: if both n and r are zero, exit the loop
        if n == 0 and r == 0:
            break

        # Initialize array a with values from 1 to n
        a = list(range(1, n + 1))

        # Process each operation
        for _ in range(r):
            # Read the values of p (number of elements to move) and c (number of elements to copy)
            p, c = map(int, input().split())

            # Temporary array b to hold the elements that will be moved
            b = a[n - p - c + 1:n - p + 1]  # Copy elements from a to b

            # Shift elements in array a to make space for the new elements
            for j in range(p - 1):
                a[n - p - c + 1 + j] = a[n - p + j + 1]  # Move elements to the left

            # Insert the copied elements from b back into array a
            for j in range(c):
                a[n - p - c + 1 + j] = b[j]  # Place elements from b into the correct position in a

        # Print the last element of array a after all operations are completed
        print(a[n - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
