import sys

# Function to read an integer from standard input
def read_int():
    # Read a word from standard input
    word = input().strip()
    # Convert the read word to an integer
    return int(word)

# Function to read a float64 from standard input
def read_float64():
    # Read a word from standard input
    word = input().strip()
    # Convert the read word to a float64
    return float(word)

# Function to read a string from standard input
def read_string():
    # Read a word from standard input
    word = input().strip()
    # Return the read word as a string
    return word

# Main function
def main():
    # Set the scanner to read words as input
    # Read the number of elements n and the number of queries m from standard input
    n, m = read_int(), read_int()
    # Allocate a list a of size n
    a = []
    # Initialize a variable sum to keep track of the sum of elements in the list
    sum_ = 0
    # Process each query
    for i in range(m):
        # Read an integer from standard input and add it to the list a
        a.append(read_int())
        # Add the current element to the sum
        sum_ += a[i]
        # Check if the sum is greater than the size of the list
        if sum_ > n:
            # If so, print -1 and exit the program
            print("-1")
            return
    # Print the result, which is the difference between the size of the list and the sum of its elements
    print(n - sum_)

# Call the main function
if __name__ == "__main__":
    main()
