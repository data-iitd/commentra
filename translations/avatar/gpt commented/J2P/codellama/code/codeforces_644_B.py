
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the console
sc = Scanner(System.in)

# Read the number of elements (n) and the maximum size of the queue (b)
n = sc.nextInt()
b = sc.nextInt()

# Initialize an array to store the results
ans = [0] * n

# Create a LinkedList to act as a queue for managing time values
q = LinkedList()

# Process each element based on the input
for i in range(n):
    # Read the time (t) and duration (d) for the current element
    t = sc.nextInt()
    d = sc.nextInt()

    # Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
    while not q.isEmpty() and q.getFirst() <= t:
        q.pollFirst()

    # Check if the size of the queue is within the allowed limit
    if q.size() <= b:
        # If the queue is empty, set the answer to the current time (t) plus duration (d)
        # Otherwise, set it to the last element in the queue plus duration (d)
        ans[i] = (q.isEmpty() and t + d) or q.getLast() + d

        # Add the computed answer to the queue
        q.add(ans[i])
    else:
        # If the queue size exceeds the limit, set the answer to -1
        ans[i] = -1

# Print the results stored in the ans array
for i in range(n):
    print(ans[i], end=" ")

# End of code
