
import sys

class Main:
    # Map to hold the count for each ID
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        # Initialize the counter for each ID to zero
        self.counterMap = {i: 0 for i in range(n)}

    # Method to increment the count for the current ID
    def increment(self):
        self.counterMap[self.myId] += 1

    # Method to calculate the total count across all IDs
    def value(self):
        return sum(self.counterMap.values())

    # Method to compare the counts of this instance with another instance
    def compare(self, other):
        # Check if this instance's counts are less than or equal to the other instance's counts
        for i in range(self.n):
            if self.counterMap[i] > other.counterMap[i]:
                return False
        return True

    # Method to merge counts from another instance into this instance
    def merge(self, other):
        # For each ID, take the maximum count from both instances
        for i in range(self.n):
            self.counterMap[i] = max(self.counterMap[i], other.counterMap[i])

    # Method to get the current state of the counterMap
    def getState(self):
        return self.counterMap

# Main method to run the program
if __name__ == "__main__":
    # Read the total number of IDs
    n = int(input())
    # Read the unique ID for this instance
    myId = int(input())
    # Create a new counter instance
    counter = Main(myId, n)
    # Read the number of operations to perform
    operations = int(input())
    
    # Process each operation
    for i in range(operations):
        operation = int(input())
        # Increment the count for the current ID
        if operation == 1:
            counter.increment()
        # Merge counts from another instance
        elif operation == 2:
            mergeId = int(input())
            otherCounter = Main(mergeId, n)
            # Read the counts for the other instance
            for j in range(n):
                otherCounter.counterMap[j] = int(input())
            # Merge the other instance's counts into this instance
            counter.merge(otherCounter)
        # Handle invalid operation input
        else:
            print("Invalid operation.")
    
    # Output the final total count and state of the counter
    print("Final counter value: " + str(counter.value()))
    print("Final counter state: " + str(counter.getState()))

