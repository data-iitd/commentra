import sys

# Function to read an integer from standard input
def read_int():
    return int(sys.stdin.readline().strip())

# Function to read a float from standard input
def read_float():
    return float(sys.stdin.readline().strip())

# Function to read a string from standard input
def read_string():
    return sys.stdin.readline().strip()

# Main function
def main():
    # Read the number of elements n and the number of queries m from standard input
    n = read_int()
    m = read_int()
    
    # Initialize a list a to store the elements
    a = []
    # Initialize a variable sum to keep track of the sum of elements in the list
    total_sum = 0
    
    # Process each query
    for i in range(m):
        # Read an integer from standard input and add it to the list a
        a.append(read_int())
        # Add the current element to the total_sum
        total_sum += a[i]
        # Check if the total_sum is greater than the size of the array
        if total_sum > n:
            # If so, print -1 and exit the program
            print("-1")
            return
    
    # Print the result, which is the difference between the size of the array and the total_sum of its elements
    print(n - total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
