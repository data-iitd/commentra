# Import the sys module for reading input
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the first integer n from input
    m = int(data[1])  # Read the second integer m from input

    arr = [0] * n  # Declare and initialize a list to store n integers
    gen = [0] * 11  # Declare and initialize a list to count occurrences of integers

    # Read n integers from input and store them in arr, and count their occurrences in gen
    for i in range(n):
        arr[i] = int(data[i + 2])
        gen[arr[i]] += 1

    ans = 0  # Declare a variable to store the result

    # Calculate the number of pairs (i, k) where i ≠ k and gen[i] and gen[k] are non-zero
    for i in range(1, m + 1):
        for k in range(1, m + 1):
            if i != k:
                ans += gen[i] * gen[k]

    # Print the result, which is half of the calculated pairs
    print(ans // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
