import sys

# Function to read an integer from input
def read_int():
    return int(sys.stdin.readline().strip())  # Read a line from input and convert it to an integer

def main():
    # Read two integers n and m from input
    n = read_int()
    m = read_int()

    # Initialize a list to hold m integers
    a = []

    # Initialize a variable to hold the sum of the integers read
    total_sum = 0

    # Read m integers from input and calculate their sum
    for _ in range(m):
        a.append(read_int())  # Read an integer and store it in the list
        total_sum += a[-1]  # Add the integer to the sum

    # Check if the sum of the integers exceeds n
    if total_sum > n:
        print("-1")  # Print -1 if the sum is greater than n
        return  # Exit the function

    # Print the difference between n and the sum of the integers
    print(n - total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
