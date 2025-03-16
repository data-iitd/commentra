
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the user
sc = Scanner(System.in)

# Read the number of elements (n) and the threshold value (m)
n = sc.nextInt()
m = sc.nextInt()

# Initialize two queues: one for the values and one for their original indices
q1 = LinkedList()
q2 = LinkedList()

# Populate the queues with input values and their corresponding indices
for i in range(1, n + 1):
    q1.add(sc.nextInt())  # Add the value to the first queue
    q2.add(i)  # Add the index to the second queue

# Variable to store the final answer (the index of the last processed element)
ans = 0

# Process the elements in the queue until it is empty
while not q1.isEmpty():
    # Check if the front element of q1 is less than or equal to m
    if q1.peek() <= m:
        # If yes, remove it from q1 and update the answer with the corresponding index from q2
        q1.poll()
        ans = q2.poll()
    # If the front element is greater than m
    else:
        # Remove the element, reduce it by m, and add it back to q1
        x = q1.poll()
        val = x - m
        q1.add(val)

        # Remove the index from q2 and add it back to maintain the order
        val2 = q2.poll()
        q2.add(val2)

# Output the final answer
print(ans)

