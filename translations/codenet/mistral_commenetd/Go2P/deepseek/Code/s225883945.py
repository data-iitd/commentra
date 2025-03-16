import sys

# Function to read a single word from the input
def next():
    return input().strip()

# Function to read an integer from the input
def next_int():
    return int(next())

# Function to read a float64 from the input
def next_float64():
    return float(next())

# Function to read n integers from the input
def next_ints(n):
    return [next_int() for _ in range(n)]

# Main function
def main():
    # Read number of elements n and the sum of elements k from the input
    n, k = next_int(), next_int()

    # Initialize sum and answer variables
    sum_ = 0
    ans = 1

    # Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
    while sum_ < n:
        # Subtract 1 from sum and add k to find the next index to check
        sum_ = sum_ - 1 + k
        # Increment the answer variable for each iteration
        ans += 1

    # Print the answer
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()
