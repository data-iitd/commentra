import sys

class Main:
    # Maps to keep track of positive and negative counts for each node
    pCounter = {}
    nCounter = {}
    
    # Identifier for the current node
    myId = 0
    
    # Total number of nodes in the system
    n = 0

    # Constructor to initialize the PN-Counter with a given ID and number of nodes
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        
        # Initialize the positive and negative counters for each node
        for i in range(n):
            self.pCounter[i] = 0 # Initialize positive counter for node i
            self.nCounter[i] = 0 # Initialize negative counter for node i

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
            raise Exception("Cannot merge PN-Counters with different number of nodes")
        # Merge the positive and negative counters by taking the maximum values
        for i in range(self.n):
            self.pCounter[i] = max(self.pCounter[i], other.pCounter[i])
            self.nCounter[i] = max(self.nCounter[i], other.nCounter[i])

    # Main method to run the PN-Counter application
    @staticmethod
    def main():
        # Read the ID of the current node
        myId = int(sys.stdin.readline().strip())
        # Read the total number of nodes in the system
        totalNodes = int(sys.stdin.readline().strip())
        
        # Create a new PN-Counter instance for the current node
        pnCounter = Main(myId, totalNodes)
        
        # Read the number of operations to perform
        operations = int(sys.stdin.readline().strip())
        
        # Process each operation
        for i in range(operations):
            operation = sys.stdin.readline().strip()
            # Increment the counter if the operation is INCREMENT
            if operation.upper() == "INCREMENT":
                pnCounter.increment()
            # Decrement the counter if the operation is DECREMENT
            elif operation.upper() == "DECREMENT":
                pnCounter.decrement()
            # Handle invalid operations
            else:
                print("Invalid operation: " + operation)
        
        # Output the final value of the counter after all operations
        print("Final value of the counter: " + str(pnCounter.value()))

# Run the main method
if __name__ == "__main__":
    Main.main()

