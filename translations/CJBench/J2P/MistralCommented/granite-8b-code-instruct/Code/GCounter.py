

class Main:
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        # Initialize an empty dictionary with size n
        self.counterMap = {i: 0 for i in range(n)}

    # Increment the counter for the current process
    def increment(self):
        self.counterMap[self.myId] += 1

    # Return the sum of all counters
    def value(self):
        return sum(self.counterMap.values())

    # Compare the counters of this process with another process
    def compare(self, other):
        for i in range(self.n):
            # If the counter for any process i is greater in this process than in the other process, return False
            if self.counterMap[i] > other.counterMap[i]:
                return False
        # If all counters are less or equal, return True
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
if __name__ == "__main__":
    import sys
    # Read the total number of processes and the ID of the current process
    n, myId = map(int, sys.stdin.readline().split())
    # Create a new instance of the Main class with the given parameters
    counter = Main(myId, n)
    # Read the number of operations
    operations = int(sys.stdin.readline())
    # Iterate through all operations
    for _ in range(operations):
        operation = int(sys.stdin.readline())
        # If the operation is to increment the counter, call the increment method
        if operation == 1:
            counter.increment()
        # If the operation is to merge the counters with another process, read the ID of the other process and its counters, and call the merge method
        elif operation == 2:
            mergeId = int(sys.stdin.readline())
            otherCounter = Main(mergeId, n)
            # Read the counters for the other process and initialize a new instance of the Main class with the given parameters
            for i in range(n):
                otherCounter.counterMap[i] = int(sys.stdin.readline())
            # Call the merge method with the other instance of the Main class
            counter.merge(otherCounter)
        # If the operation is invalid, print an error message
        else:
            print("Invalid operation.")
    # Print the final counter value and state
    print("Final counter value:", counter.value())
    print("Final counter state:", counter.getState())
