
import sys

class Main:
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        self.counterMap = {}
        for i in range(n):
            self.counterMap[i] = 0

    def increment(self):
        self.counterMap[self.myId] += 1

    def value(self):
        sum = 0
        for v in self.counterMap.values():
            sum += v
        return sum

    def compare(self, other):
        for i in range(self.n):
            if self.counterMap[i] > other.counterMap[i]:
                return False
        return True

    def merge(self, other):
        for i in range(self.n):
            self.counterMap[i] = max(self.counterMap[i], other.counterMap[i])

    def getState(self):
        return self.counterMap

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    myId = int(sys.stdin.readline())
    counter = Main(myId, n)
    operations = int(sys.stdin.readline())
    for i in range(operations):
        operation = int(sys.stdin.readline())
        if operation == 1:
            counter.increment()
        elif operation == 2:
            mergeId = int(sys.stdin.readline())
            otherCounter = Main(mergeId, n)
            for i in range(n):
                otherCounter.counterMap[i] = int(sys.stdin.readline())
            counter.merge(otherCounter)
        else:
            print("Invalid operation.")
    print("Final counter value: " + str(counter.value()))
    print("Final counter state: " + str(counter.getState()))

