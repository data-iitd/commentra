import sys

# Maps to keep track of positive and negative counts for each node
pCounter = {}
nCounter = {}

# Identifier for the current node
myId = int(sys.stdin.readline().strip())

# Total number of nodes in the system
n = int(sys.stdin.readline().strip())

# Constructor to initialize the PN-Counter with a given ID and number of nodes
def Main(myId, n):
    # Initialize the positive and negative counters for each node
    for i in range(n):
        pCounter[i] = 0 # Initialize positive counter for node i
        nCounter[i] = 0 # Initialize negative counter for node i

# Method to increment the positive counter for the current node
def increment():
    pCounter[myId] += 1

# Method to increment the negative counter for the current node
def decrement():
    nCounter[myId] += 1

# Method to calculate the current value of the counter (positive - negative)
def value():
    # Sum all positive counts
    sumP = sum(pCounter.values())
    # Sum all negative counts
    sumN = sum(nCounter.values())
    # Return the difference between positive and negative sums
    return sumP - sumN

# Method to merge another PN-Counter into this one
def merge(other):
    # Check if the number of nodes is the same before merging
    if n != other.n:
        raise ValueError("Cannot merge PN-Counters with different number of nodes")
    # Merge the positive and negative counters by taking the maximum values
    for i in range(n):
        pCounter[i] = max(pCounter[i], other.pCounter[i])
        nCounter[i] = max(nCounter[i], other.nCounter[i])

# Main method to run the PN-Counter application
def main():
    # Read the number of operations to perform
    operations = int(sys.stdin.readline().strip())

    # Process each operation
    for i in range(operations):
        operation = sys.stdin.readline().strip()
        # Increment the counter if the operation is INCREMENT
        if operation.upper() == "INCREMENT":
            increment()
        # Decrement the counter if the operation is DECREMENT
        elif operation.upper() == "DECREMENT":
            decrement()
        # Handle invalid operations
        else:
            print("Invalid operation:", operation)

    # Output the final value of the counter after all operations
    print("Final value of the counter:", value())

# Create a new PN-Counter instance for the current node
Main(myId, n)

# Read the number of operations to perform
operations = int(sys.stdin.readline().strip())

# Process each operation
for i in range(operations):
    operation = sys.stdin.readline().strip()
    # Increment the counter if the operation is INCREMENT
    if operation.upper() == "INCREMENT":
        increment()
    # Decrement the counter if the operation is DECREMENT
    elif operation.upper() == "DECREMENT":
        decrement()
    # Handle invalid operations
    else:
        print("Invalid operation:", operation)

# Output the final value of the counter after all operations
print("Final value of the counter:", value())

# END-OF-CODE
