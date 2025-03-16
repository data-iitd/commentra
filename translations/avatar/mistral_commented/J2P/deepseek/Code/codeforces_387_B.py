# Import necessary Python utility classes
from collections import deque

# Main method is the entry point of the Python application
def main():
    # Initialize deque to read input from the standard input
    input_line = deque(map(int, input().split()))

    # Read the number of requests and preemptions from the input
    n = input_line.popleft()
    m = input_line.popleft()

    # Create lists to store request and preemption indices
    req = list(input_line)
    pre = list(input_line)

    # Initialize index variables for requests and preemptions
    i = n - 1
    j = m - 1

    # Initialize answer variable
    ans = 0

    # While there are still requests and preemptions to compare
    while i >= 0 and j >= 0:
        # If the current request can preempt the current preemption
        if req[i] > pre[j]:
            # Increment answer variable
            ans += 1
        else:
            # Decrement preemption index
            j -= 1
        # Decrement request index
        i -= 1

    # Print the answer and the number of remaining requests
    print(ans + i + 1)

# Call the main method
main()
