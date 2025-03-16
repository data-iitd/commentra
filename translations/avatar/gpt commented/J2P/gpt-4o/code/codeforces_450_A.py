from collections import deque

def main():
    # Create a deque for the values and their original indices
    q1 = deque()
    q2 = deque()
    
    # Read the number of elements (n) and the threshold value (m)
    n, m = map(int, input().split())
    
    # Populate the deques with input values and their corresponding indices
    for i in range(1, n + 1):
        q1.append(int(input()))  # Add the value to the first deque
        q2.append(i)  # Add the index to the second deque
    
    # Variable to store the final answer (the index of the last processed element)
    ans = 0
    
    # Process the elements in the deque until it is empty
    while q1:
        # Check if the front element of q1 is less than or equal to m
        if q1[0] <= m:
            # If yes, remove it from q1 and update the answer with the corresponding index from q2
            q1.popleft()
            ans = q2.popleft()
        # If the front element is greater than m
        else:
            # Remove the element, reduce it by m, and add it back to q1
            x = q1.popleft()
            val = x - m
            q1.append(val)
            
            # Remove the index from q2 and add it back to maintain the order
            val2 = q2.popleft()
            q2.append(val2)
    
    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
