import sys

# Initialize arrays 'maps' and 'num' with given size 'maxn'
maps = [0] * (200000 + 10)
num = [0] * (200000 + 10)

# Main function starts here
def main():
    # Start an infinite loop to read multiple test cases
    while True:
        try:
            # Initialize variable 'n' to read input from standard input
            n = int(sys.stdin.readline().strip())
            # Initialize 'maps' and 'num' arrays with input values
            for i in range(1, n + 1):
                maps[i] = int(sys.stdin.readline().strip())
                num[i] = maps[i]  # copy input values to 'num' array
            # Sort 'maps' array in ascending order
            maps[1:n + 1] = sorted(maps[1:n + 1])
            # Calculate the middle index 'm' of sorted 'maps' array
            m = n // 2
            # Process each element in 'num' array based on the middle index 'm'
            for i in range(1, n + 1):
                # If current element 'num[i]' is smaller than or equal to middle element 'maps[m]'
                if num[i] <= maps[m]:
                    # Print the next element in sorted 'maps' array
                    print(maps[m + 1])
                # Otherwise print the current middle element 'maps[m]'
                else:
                    print(maps[m])
        except EOFError:
            break

# Call the main function
if __name__ == "__main__":
    main()
