
import sys
from collections import defaultdict

class Main:
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        self.pCounter = defaultdict(int)
        self.nCounter = defaultdict(int)

    def increment(self):
        self.pCounter[self.myId] += 1

    def decrement(self):
        self.nCounter[self.myId] += 1

    def value(self):
        sumP = sum(self.pCounter.values())
        sumN = sum(self.nCounter.values())
        return sumP - sumN

    def merge(self, other):
        if self.n!= other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        for i in range(self.n):
            self.pCounter[i] = max(self.pCounter[i], other.pCounter[i])
            self.nCounter[i] = max(self.nCounter[i], other.nCounter[i])

if __name__ == "__main__":
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

