def main():
    while True:  # Loop until both n and r are zero
        n, r = map(int, input().split())  # Read the number of elements and the number of operations
        if n == 0 and r == 0:
            break  # Exit the loop if both n and r are zero

        # Initialize array a with elements from 1 to n
        a = list(range(1, n + 1))

        # Perform r operations
        for _ in range(r):
            p, c = map(int, input().split())  # Read the position and count of elements to be moved

            # Copy the last c elements to be moved to array b
            b = a[n - p - c + 1:n - p + 1]

            # Shift the first p-1 elements before the position where the c elements will be moved
            for j in range(n - p - c + 1, n - p):
                a[j] = a[j + 1]

            # Place the elements from b back into array a at the correct position
            for j in range(n - p - c + 1, n - p - c + 1 + c):
                a[j] = b[j - (n - p - c + 1)]

        # Print the last element of the array a after all operations
        print(a[n - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
