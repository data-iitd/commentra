from collections import deque
import sys

def main():
    # Read the first integer input, which represents the number of elements
    n = int(input().strip())
    # Read the second integer input, which is the threshold value
    m = int(input().strip())
    
    # Initialize deque to store the elements
    q1 = deque()
    # Initialize deque to store the indices
    q2 = deque()
    
    # Read each element and add it to q1, and add the corresponding index to q2
    for i in range(1, n + 1):
        x = int(input().strip())
        q1.append(x)
        q2.append(i)
    
    # Initialize ans to store the result
    ans = 0
    
    # Continue the loop until q1 is empty
    while q1:
        # Check if the front element of q1 is less than or equal to m
        if q1[0] <= m:
            # Remove the front element from q1
            q1.popleft()
            # Assign the corresponding index to ans and remove it from q2
            ans = q2.popleft()
        # Check if the front element of q1 is greater than m
        elif q1[0] > m:
            # Remove the front element from q1
            x = q1.popleft()
            # Subtract m from the element
            val = x - m
            # Add the result back to q1
            q1.append(val)
            # Remove the corresponding index from q2
            val2 = q2.popleft()
            # Add the index back to the end of q2
            q2.append(val2)
    
    # Print the index of the last remaining element
    print(ans)

if __name__ == "__main__":
    main()
