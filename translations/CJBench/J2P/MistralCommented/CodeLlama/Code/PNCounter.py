
import sys

# Initialize two hash maps to store positive and negative counter values for each node
pCounter = {}
nCounter = {}

# Initialize instance variables
myId = int(sys.argv[1])
n = int(sys.argv[2])

# Initialize the hash maps with zero values for all nodes
for i in range(n):
    pCounter[i] = 0
    nCounter[i] = 0

# Increment the positive counter for the current node
def increment():
    pCounter[myId] += 1

# Increment the negative counter for the current node
def decrement():
    nCounter[myId] += 1

# Calculate the difference between positive and negative counters
def value():
    sumP = 0
    sumN = 0

    # Sum up all positive counter values
    for value in pCounter.values():
        sumP += value

    # Sum up all negative counter values
    for value in nCounter.values():
        sumN += value

    # Return the difference between positive and negative counters
    return sumP - sumN

# Merge the positive and negative counters of two PN-Counters
def merge(other):
    if n != other.n:
        raise ValueError("Cannot merge PN-Counters with different number of nodes")

    # Merge positive counters
    for i in range(n):
        pCounter[i] = max(pCounter[i], other.pCounter[i])

    # Merge negative counters
    for i in range(n):
        nCounter[i] = max(nCounter[i], other.nCounter[i])

# Main method to read input and call methods
if __name__ == "__main__":
    # Read input: my ID and total number of nodes
    myId = int(sys.argv[1])
    n = int(sys.argv[2])

    # Initialize a PN-Counter instance for the given myId and totalNodes
    pnCounter = Main(myId, n)

    # Read input: number of operations
    operations = int(sys.argv[3])

    # Read input: operations and call corresponding methods
    for i in range(operations):
        operation = sys.stdin.readline().strip()

        if operation.upper() == "INCREMENT":
            pnCounter.increment() # Increment the positive counter for the current node
        elif operation.upper() == "DECREMENT":
            pnCounter.decrement() # Increment the negative counter for the current node
        else:
            print("Invalid operation: " + operation)

    # Print the final value of the counter
    print("Final value of the counter: " + str(pnCounter.value()))

