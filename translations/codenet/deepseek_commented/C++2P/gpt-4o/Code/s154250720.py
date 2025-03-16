import sys

# Define constants
maxn = 200000 + 10  # Maximum number of elements
INF = int(1e8)      # A large value representing infinity

# Declare lists
maps = [0] * maxn
num = [0] * maxn

def main():
    for line in sys.stdin:
        n = int(line.strip())  # Read the number of elements
        # Read the elements into maps list and copy them to num list
        for i in range(1, n + 1):
            maps[i] = int(sys.stdin.readline().strip())
            num[i] = maps[i]

        # Sort the maps list to find the median easily
        maps[1:n + 1] = sorted(maps[1:n + 1])

        # Calculate the median index
        m = n // 2

        # Iterate through the num list and print the appropriate median value
        for i in range(1, n + 1):
            if num[i] <= maps[m]:
                print(maps[m + 1])  # Print the element after the median if num[i] is less than or equal to the median
            else:
                print(maps[m])      # Print the median if num[i] is greater than the median

if __name__ == "__main__":
    main()

# <END-OF-CODE>
