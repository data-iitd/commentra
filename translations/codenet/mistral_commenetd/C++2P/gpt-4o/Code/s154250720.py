import sys

# Define a large constant value used as INF
INF = int(1e8)

# Main function starts here
def main():
    # Start an infinite loop to read multiple test cases
    for line in sys.stdin:
        n = int(line.strip())
        # Initialize lists 'maps' and 'num' with given size 'n'
        maps = [0] * (n + 1)
        num = [0] * (n + 1)

        # Read input values into 'maps' and copy to 'num'
        for i in range(1, n + 1):
            maps[i] = int(sys.stdin.readline().strip())
            num[i] = maps[i]  # copy input values to 'num' list

        # Sort 'maps' list in ascending order
        maps[1:n + 1] = sorted(maps[1:n + 1])
        # Calculate the middle index 'm' of sorted 'maps' list
        m = n // 2

        # Process each element in 'num' list based on the middle index 'm'
        for i in range(1, n + 1):
            # If current element 'num[i]' is smaller than or equal to middle element 'maps[m]'
            if num[i] <= maps[m]:
                # Print the next element in sorted 'maps' list
                print(maps[m + 1])
            else:
                # Otherwise print the current middle element 'maps[m]'
                print(maps[m])

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
