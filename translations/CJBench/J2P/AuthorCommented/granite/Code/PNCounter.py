

import sys

class Main:
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        self.pCounter = [0] * n
        self.nCounter = [0] * n

    def increment(self):
        self.pCounter[self.myId] += 1

    def decrement(self):
        self.nCounter[self.myId] += 1

    def value(self):
        return sum(self.pCounter) - sum(self.nCounter)

    def merge(self, other):
        if self.n!= other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        for i in range(self.n):
            self.pCounter[i] = max(self.pCounter[i], other.pCounter[i])
            self.nCounter[i] = max(self.nCounter[i], other.nCounter[i])

if __name__ == "__main__":
    myId = int(sys.stdin.readline())
    totalNodes = int(sys.stdin.readline())
    operations = int(sys.stdin.readline())

    pnCounter = Main(myId, totalNodes)

    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        if operation.upper() == "INCREMENT":
            pnCounter.increment()
        elif operation.upper() == "DECREMENT":
            pnCounter.decrement()
        else:
            print(f"Invalid operation: {operation}")

    print(f"Final value of the counter: {pnCounter.value()}")

