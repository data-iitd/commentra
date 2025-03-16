import sys

# Initialize a function to read input
def next_int():
    return int(sys.stdin.readline().strip())

# Main function to read input and process it
def main():
    # Read the number of test cases
    n = next_int()

    # Initialize variables for processing the input
    ans = 0
    a_prev = 0

    # Process each test case
    for i in range(n):
        # Read the next integer as 'a'
        a = next_int()

        # Check if 'a' is valid based on the conditions in the problem statement
        if a > i or a > a_prev + 1:  # 'a' is not valid, print -1 and exit
            print(-1)
            return
        elif a == a_prev + 1:  # Increment the answer if 'a' is consecutive with the previous number
            ans += 1
        else:  # Add 'a' to the answer if it's not consecutive but greater than the previous number
            ans += a

        # Update the previous number
        a_prev = a

    # Print the final answer
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
