import sys

# Function to read a single word from the input
def next():
    return sys.stdin.readline().strip()

# Function to read an integer from the input
def next_int():
    return int(next())

# Function to read n integers from the input
def next_ints(n):
    return [next_int() for _ in range(n)]

# Main function
def main():
    # Read number of elements n and the sum of elements k from the input
    n, k = next_int(), next_int()

    # Initialize sum and answer variables
    sum_value, ans = 0, 1

    # Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
    while sum_value < n:
        # Subtract 1 from sum and add k to find the next index to check
        sum_value = sum_value - 1 + k
        # Increment the answer variable for each iteration
        ans += 1

    # Print the answer
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
