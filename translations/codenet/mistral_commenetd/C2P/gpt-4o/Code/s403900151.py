# The main function is the entry point of the program
def main():
    while True:
        n, r = map(int, input().split())  # Read the values of n and r from the standard input
        if n == 0 and r == 0:  # Check if both n and r are 0
            break  # If yes, break out of the loop

        a = list(range(1, n + 1))  # Initialize array a with values from 1 to n

        # Iterate r times
        for _ in range(r):
            p, c = map(int, input().split())  # Read the values of p and c from the standard input

            b = [0] * c  # Initialize array b with size c
            # Initialize array b with elements from array a
            for j in range(c):
                b[j] = a[n - p - c + 1 + j]

            # Shift elements of array a to the left by p-1 positions
            for j in range(p - 1):
                a[n - p + j + 1] = a[n - p + j]

            # Copy elements from array b to the end of array a
            for j in range(n - p - c + 1, n - p + 1):
                a[j] = b[j - (n - p - c + 1)]

            # Print the last element of array a
            print(a[n - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
