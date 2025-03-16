# Importing the sys module for input
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of elements
    N = int(1e5) + 5  # Define a constant N for array size
    cnt = [0] * 21  # Initialize a list to count occurrences of each value shifted by 10

    # Count the occurrences of each value shifted by 10
    for _ in range(n):
        cnt[int(sys.stdin.readline().strip()) + 10] += 1

    res = 0  # Initialize result variable

    # Calculate the number of pairs that sum up to 20
    for i in range(10):
        res += cnt[i] * cnt[20 - i]

    # Special case for pairs where both elements are the same (i.e., i = 10)
    res += (cnt[10] * (cnt[10] - 1)) // 2

    # Output the result
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
