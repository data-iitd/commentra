
import sys

class Main:
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        self.pCounter = {}
        self.nCounter = {}
        for i in range(n):
            self.pCounter[i] = 0
            self.nCounter[i] = 0

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
    myId, n = map(int, sys.stdin.readline().split())
    pnCounter = Main(myId, n)
    operations = int(sys.stdin.readline())
    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        if operation.lower() == "increment":
            pnCounter.increment()
        elif operation.lower() == "decrement":
            pnCounter.decrement()
        else:
            print(f"Invalid operation: {operation}")
    print(f"Final value of the counter: {pnCounter.value()}")

