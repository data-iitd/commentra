
import sys

class Main:
    # Initialize a map to store the counter for each process
    counterMap = {}
    # Initialize the ID of the current process
    myId = 0
    # Initialize the total number of processes
    n = 0

    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        # Initialize an empty map with size n
        for i in range(n):
            self.counterMap[i] = 0

    # Increment the counter for the current process
    def increment(self):
        self.counterMap[self.myId] += 1

    # Return the sum of all counters
    def value(self):
        sum = 0
        # Iterate through all counters and sum them up
        for v in self.counterMap.values():
            sum += v
        return sum

    # Compare the counters of this process with another process
    def compare(self, other):
        for i in range(self.n):
            # If the counter for any process i is greater in this process than in the other process, return false
            if self.counterMap[i] > other.counterMap[i]:
                return False
        # If all counters are less or equal, return true
        return True

    # Merge the counters of this process with another process
    def merge(self, other):
        for i in range(self.n):
            # Update the counter for each process i with the maximum value between this process and the other process
            self.counterMap[i] = max(self.counterMap[i], other.counterMap[i])

    # Return the current state of the counters
    def getState(self):
        return self.counterMap

    # Main method to read input and run the simulation
    def main(self):
        # Read the total number of processes and the ID of the current process
        n = int(sys.stdin.readline())
        myId = int(sys.stdin.readline())
        # Create a new instance of the Main class with the given parameters
        counter = Main(myId, n)
        # Read the number of operations
        operations = int(sys.stdin.readline())
        # Iterate through all operations
        for i in range(operations):
            operation = int(sys.stdin.readline())
            # If the operation is to increment the counter, call the increment method
            if operation == 1:
                counter.increment()
            # If the operation is to merge the counters with another process, read the ID of the other process and its counters, and call the merge method
            elif operation == 2:
                mergeId = int(sys.stdin.readline())
                otherCounter = Main(mergeId, n)
                # Read the counters for the other process and initialize a new instance of the Main class with the given parameters
                for j in range(n):
                    otherCounter.counterMap[j] = int(sys.stdin.readline())
                # Call the merge method with the other instance of the Main class
                counter.merge(otherCounter)
            # If the operation is invalid, print an error message
            else:
                print("Invalid operation.")
        # Print the final counter value and state
        print("Final counter value: " + str(counter.value()))
        print("Final counter state: " + str(counter.getState()))

# 