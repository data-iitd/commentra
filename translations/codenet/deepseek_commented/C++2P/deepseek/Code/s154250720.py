import sys

# Define constants
maxn = 200000 + 10
INF = int(1e8)

# Declare arrays
maps = [0] * maxn
num = [0] * maxn

def main():
    while True:
        try:
            n = int(sys.stdin.readline().strip())
            # Read the elements into maps array and copy them to num array
            for i in range(1, n + 1):
                maps[i] = int(sys.stdin.readline().strip())
                num[i] = maps[i]

            # Sort the maps array to find the median easily
            maps[1:n + 1] = sorted(maps[1:n + 1])

            # Calculate the median index
            m = n // 2

            # Iterate through the num array and print the appropriate median value
            for i in range(1, n + 1):
                if num[i] <= maps[m]:
                    print(maps[m + 1])
                else:
                    print(maps[m])
        except ValueError:
            break

if __name__ == "__main__":
    main()

