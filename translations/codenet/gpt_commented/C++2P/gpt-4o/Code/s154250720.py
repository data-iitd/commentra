import sys

# Define constants for maximum size and infinity value
maxn = 200000 + 10
INF = int(1e8)

# Arrays to hold input values and sorted values
maps = [0] * maxn
num = [0] * maxn

def main():
    # Continuously read input until EOF
    for line in sys.stdin:
        n = int(line.strip())  # Read the number of elements
        
        # Read n integers into the maps array and copy to num array
        for i in range(1, n + 1):
            maps[i] = int(sys.stdin.readline().strip())
            num[i] = maps[i]

        # Sort the maps array to find the median
        maps[1:n + 1] = sorted(maps[1:n + 1])
        
        # Calculate the index for the median element
        m = n // 2

        # For each element in the original array, determine and print the appropriate value
        for i in range(1, n + 1):
            # If the current number is less than or equal to the median
            if num[i] <= maps[m]:
                # Print the next higher number (the one after the median)
                print(maps[m + 1])
            else:
                # Print the median value
                print(maps[m])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
