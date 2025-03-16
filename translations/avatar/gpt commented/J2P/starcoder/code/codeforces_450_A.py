
# <START-OF-CODE>

# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)

# Read the number of elements (n) and the threshold value (m)
n = sc.nextInt()
m = sc.nextInt()

# Initialize two queues: one for the values and one for their original indices
q1 = []
q2 = []

# Populate the queues with input values and their corresponding indices
for i in range(1, n + 1):
    q1.append(sc.nextInt())  # Add the value to the first queue
    q2.append(i)  # Add the index to the second queue

# Variable to store the final answer (the index of the last processed element)
ans = 0

# Process the elements in the queue until it is empty
while len(q1) > 0:
    # Check if the front element of q1 is less than or equal to m
    if q1[0] <= m:
        # If yes, remove it from q1 and update the answer with the corresponding index from q2
        q1.pop(0)
        ans = q2.pop(0)
    # If the front element is greater than m
    else:
        # Remove the element, reduce it by m, and add it back to q1
        x = q1.pop(0)
        val = x - m
        q1.append(val)

        # Remove the index from q2 and add it back to maintain the order
        val2 = q2.pop(0)
        q2.append(val2)

# Output the final answer
print(ans)

# 