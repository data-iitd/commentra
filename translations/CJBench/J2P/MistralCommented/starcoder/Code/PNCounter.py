
import sys

class Main:
    # Initialize two hash maps to store positive and negative counter values for each node
    pCounter = {}
    nCounter = {}
    
    # Initialize instance variables
    myId = 0
    n = 0
    
    # Constructor
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        
        # Initialize the hash maps with zero values for all nodes
        for i in range(0, n):
            self.pCounter[i] = 0
            self.nCounter[i] = 0
    
    # Increment the positive counter for the current node
    def increment(self):
        self.pCounter[self.myId] = self.pCounter[self.myId] + 1
    
    # Increment the negative counter for the current node
    def decrement(self):
        self.nCounter[self.myId] = self.nCounter[self.myId] + 1
    
    # Calculate the difference between positive and negative counters
    def value(self):
        sumP = 0
        sumN = 0
        
        # Sum up all positive counter values
        for value in self.pCounter.values():
            sumP += value
        
        # Sum up all negative counter values
        for value in self.nCounter.values():
            sumN += value
        
        # Return the difference between positive and negative counters
        return sumP - sumN
    
    # Merge the positive and negative counters of two PN-Counters
    def merge(self, other):
        if self.n!= other.n:
            raise Exception("Cannot merge PN-Counters with different number of nodes")
        
        # Merge positive counters
        for i in range(0, self.n):
            self.pCounter[i] = max(self.pCounter[i], other.pCounter[i])
        
        # Merge negative counters
        for i in range(0, self.n):
            self.nCounter[i] = max(self.nCounter[i], other.nCounter[i])
    
    # Main method to read input and call methods
    def main(self):
        # Read input: my ID and total number of nodes
        self.myId = int(sys.stdin.readline().strip())
        self.n = int(sys.stdin.readline().strip())
        
        # Initialize a PN-Counter instance for the given myId and totalNodes
        pnCounter = Main(self.myId, self.n)
        
        # Read input: number of operations
        operations = int(sys.stdin.readline().strip())
        
        # Read input: operations and call corresponding methods
        for i in range(0, operations):
            operation = sys.stdin.readline().strip()
            
            if operation.upper() == "INCREMENT":
                pnCounter.increment() # Increment the positive counter for the current node
            elif operation.upper() == "DECREMENT":
                pnCounter.decrement() # Increment the negative counter for the current node
            else:
                print("Invalid operation: " + operation)
        
        # Print the final value of the counter
        print("Final value of the counter: " + str(pnCounter.value()))

