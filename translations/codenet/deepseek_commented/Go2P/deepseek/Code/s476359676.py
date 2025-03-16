import sys
import os
import io

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def next_str():
    return input().decode().strip()

def next_int():
    return int(next_str())

def main():
    # Read the number of elements in the sequence
    n = next_int()

    # Initialize the answer and the previous element in the sequence
    ans = 0
    a_prev = 0
    # Loop through each element in the sequence
    for _ in range(n):
        # Read the current element
        a = next_int()
        # Check the conditions for the current element
        if a > _ or a > a_prev + 1:
            # If the condition is met, print -1 and exit
            print(-1)
            return
        elif a == a_prev + 1:
            # If the current element is one more than the previous, increment the answer
            ans += 1
        else:
            # Otherwise, add the current element's value to the answer
            ans += a
        # Update the previous element to the current element
        a_prev = a
    # Print the final answer after processing all elements
    print(ans)

main()
