import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

def main():
    # Read the number of integers to process
    n = next_int()

    # Initialize variables for the answer and the previous integer
    ans = 0
    a_prev = 0

    # Loop through each integer input
    for i in range(n):
        a = next_int()  # Read the next integer

        # Check conditions based on the current and previous integers
        if a > i or a > a_prev + 1:  # If the current integer is greater than the index or previous integer + 1
            print(-1)  # Print -1 and exit if the condition is met
            return
        elif a == a_prev + 1:  # If the current integer is exactly one more than the previous integer
            ans += 1  # Increment the answer
        else:  # For all other cases
            ans += a  # Add the current integer to the answer
        
        a_prev = a  # Update the previous integer to the current one

    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
