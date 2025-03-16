
import sys

class Main:
    # Maps to keep track of positive and negative counts for each node
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        # Initialize the positive and negative counters for each node
        self.pCounter = {i: 0 for i in range(n)}
        self.nCounter = {i: 0 for i in range(n)}

    # Method to increment the positive counter for the current node
    def increment(self):
        self.pCounter[self.myId] += 1

    # Method to increment the negative counter for the current node
    def decrement(self):
        self.nCounter[self.myId] += 1

    # Method to calculate the current value of the counter (positive - negative)
    def value(self):
        # Sum all positive counts
        sumP = sum(self.pCounter.values())
        # Sum all negative counts
        sumN = sum(self.nCounter.values())
        # Return the difference between positive and negative sums
        return sumP - sumN

    # Method to merge another PN-Counter into this one
    def merge(self, other):
        # Check if the number of nodes is the same before merging
        if self.n!= other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        # Merge the positive and negative counters by taking the maximum values
        for i in range(self.n):
            self.pCounter[i] = max(self.pCounter[i], other.pCounter[i])
            self.nCounter[i] = max(self.nCounter[i], other.nCounter[i])

# Main method to run the PN-Counter application
if __name__ == "__main__":
    # Read the ID of the current node
    myId = int(input())
    # Read the total number of nodes in the system
    totalNodes = int(input())
    # Create a new PN-Counter instance for the current node
    pnCounter = Main(myId, totalNodes)
    # Read the number of operations to perform
    operations = int(input())
    # Process each operation
    for _ in range(operations):
        operation = input().strip().upper()
        # Increment the counter if the operation is INCREMENT
        if operation == "INCREMENT":
            pnCounter.increment()
        # Decrement the counter if the operation is DECREMENT
        elif operation == "DECREMENT":
            pnCounter.decrement()
        # Handle invalid operations
        else:
            print(f"Invalid operation: {operation}")
    # Output the final value of the counter after all operations
    print(f"Final value of the counter: {pnCounter.value()}")

