import sys

# Read a single integer from the standard input
def read_int():
    return int(sys.stdin.readline().strip())

# Read a single float64 from the standard input
def read_float64():
    return float(sys.stdin.readline().strip())

# Read a single string from the standard input
def read_string():
    return sys.stdin.readline().strip()

# Main function to execute the program
def main():
    # Read two integers n and m from the input
    n, m = map(int, read_string().split())

    # Read m integers into the list a and calculate their sum
    a = list(map(int, read_string().split()))
    sum_a = sum(a)

    # Check if the sum of integers exceeds n
    if sum_a > n:
        # Print -1 if the sum exceeds n and exit
        print("-1")
        return

    # Print the difference between n and the sum if it's within bounds
    print(n - sum_a)

# Call the main function
if __name__ == "__main__":
    main()
