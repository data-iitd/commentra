import sys

class Main:
    # This map keeps track of the number of increment operations per node.
    pCounter = {}
    # This map keeps track of the number of decrement operations per node.
    nCounter = {}
    # The ID of the current node.
    myId = 0
    # The total number of nodes.
    n = 0

    # Constructor initializes the node ID, total number of nodes, and the counters.
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        # Initialize the counters for each node to zero.
        for i in range(n):
            self.pCounter[i] = 0
            self.nCounter[i] = 0

    # Increments the counter for the current node.
    def increment(self):
        self.pCounter[self.myId] = self.pCounter[self.myId] + 1

    # Decrements the counter for the current node.
    def decrement(self):
        self.nCounter[self.myId] = self.nCounter[self.myId] + 1

    # Calculates the value of the counter by subtracting the sum of decrements from the sum of increments.
    def value(self):
        sumP = sum(self.pCounter.values())
        sumN = sum(self.nCounter.values())
        return sumP - sumN

    # Merges the state of another Main object into the current one, ensuring that the maximum values are taken.
    def merge(self, other):
        if self.n != other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        for i in range(self.n):
            self.pCounter[i] = max(self.pCounter[i], other.pCounter[i])
            self.nCounter[i] = max(self.nCounter[i], other.nCounter[i])

    # Main method to read inputs, process operations, and print the final value of the counter.
    def main(self):
        myId = int(sys.stdin.readline().strip())
        totalNodes = int(sys.stdin.readline().strip())
        pnCounter = Main(myId, totalNodes)
        operations = int(sys.stdin.readline().strip())
        for i in range(operations):
            operation = sys.stdin.readline().strip()
            if operation.upper() == "INCREMENT":
                pnCounter.increment()
            elif operation.upper() == "DECREMENT":
                pnCounter.decrement()
            else:
                print("Invalid operation: " + operation)
        print("Final value of the counter: " + str(pnCounter.value()))


if __name__ == "__main__":
    Main().main()
    print("