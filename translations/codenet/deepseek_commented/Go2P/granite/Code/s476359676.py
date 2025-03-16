

import sys

def main():
    # Read the number of elements in the sequence
    n = int(input())

    # Initialize the answer and the previous element in the sequence
    ans = 0
    aPrev = 0
    # Loop through each element in the sequence
    for i in range(n):
        # Read the current element
        a = int(input())
        # Check the conditions for the current element
        if a > i or a > aPrev + 1:
            # If the condition is met, print -1 and exit
            print(-1)
            sys.exit(0)
        elif a == aPrev + 1:
            # If the current element is one more than the previous, increment the answer
            ans += 1
        else:
            # Otherwise, add the current element's value to the answer
            ans += a
        # Update the previous element to the current element
        aPrev = a
    # Print the final answer after processing all elements
    print(ans)

