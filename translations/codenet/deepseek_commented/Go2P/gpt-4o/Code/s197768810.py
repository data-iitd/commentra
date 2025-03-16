import sys

# Function to read a single integer from standard input
def read_int():
    return int(sys.stdin.readline().strip())

# Function to read a single float from standard input
def read_float():
    return float(sys.stdin.readline().strip())

# Function to read a single string from standard input
def read_string():
    return sys.stdin.readline().strip()

# Main function to execute the program
def main():
    # Read two integers n and m from the input
    n = read_int()
    m = read_int()

    # Initialize a list to hold m integers
    a = []
    total_sum = 0

    # Read m integers into the list a and calculate their sum
    for _ in range(m):
        a.append(read_int())
        total_sum += a[-1]

    # Check if the sum of integers exceeds n
    if total_sum > n:
        # Print -1 if the sum exceeds n and exit
        print("-1")
        return

    # Print the difference between n and the sum if it's within bounds
    print(n - total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
