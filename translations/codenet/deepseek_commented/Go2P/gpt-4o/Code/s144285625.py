import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    n = next_int()  # Read the number of elements
    ar = [next_int() for _ in range(3 * n)]  # Create a list of size 3*n and populate it with integers from input
    ar.sort()  # Sort the list
    sum_value = 0  # Initialize sum to 0
    for i in range(n):
        sum_value += ar[3 * n - (i + 1) * 2]  # Calculate the sum of the last n elements, skipping every second element
    print(sum_value)  # Print the sum

if __name__ == "__main__":
    main()

# <END-OF-CODE>
