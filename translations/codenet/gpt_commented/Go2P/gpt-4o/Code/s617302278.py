import sys

# Function to read a line of integers from standard input
def next_ints_line():
    return list(map(int, sys.stdin.readline().strip().split()))

# Main function where the program execution begins
def main():
    tmp = next_ints_line()  # Read a line of integers
    x = tmp[0]  # Store the first integer in variable x
    i = 1  # Initialize counter
    sum = 0  # Initialize sum
    while True:
        sum += i  # Incrementally add to sum
        if sum >= x:  # Check if sum has reached or exceeded x
            break  # Exit the loop if condition is met
        i += 1  # Increment counter
    print(i)  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
