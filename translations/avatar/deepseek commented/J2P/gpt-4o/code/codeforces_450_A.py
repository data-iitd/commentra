from collections import deque

def main():
    n = int(input())  # Read the first integer input, which represents the number of elements
    m = int(input())  # Read the second integer input, which is the threshold value

    q1 = deque()  # Initialize queue to store the elements
    q2 = deque()  # Initialize queue to store the indices

    for i in range(1, n + 1):
        q1.append(int(input()))  # Read each element and add it to q1
        q2.append(i)  # Add the corresponding index to q2

    ans = 0  # Initialize ans to store the result

    while q1:  # Continue the loop until q1 is empty
        if q1[0] <= m:  # Check if the front element of q1 is less than or equal to m
            q1.popleft()  # Remove the front element from q1
            ans = q2.popleft()  # Assign the corresponding index to ans and remove it from q2
        else:  # Check if the front element of q1 is greater than m
            x = q1.popleft()  # Remove the front element from q1
            val = x - m  # Subtract m from the element
            q1.append(val)  # Add the result back to q1
            val2 = q2.popleft()  # Remove the corresponding index from q2
            q2.append(val2)  # Add the index back to the end of q2

    print(ans)  # Print the index of the last remaining element

if __name__ == "__main__":
    main()

# <END-OF-CODE>
