

import sys

class Main:
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        self.counterMap = {i: 0 for i in range(n)}

    def increment(self):
        self.counterMap[self.myId] += 1

    def value(self):
        return sum(self.counterMap.values())

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
    n = int(input())
    myId = int(input())
    operations = int(input())

    counter = Main(myId, n)

    for _ in range(operations):
        operation = int(input())

        if operation == 1:
            counter.increment()
        elif operation == 2:
            mergeId = int(input())
            otherCounter = Main(mergeId, n)
            for i in range(n):
                otherCounter.counterMap[i] = int(input())
            counter.merge(otherCounter)
        else:
            print("Invalid operation.")

    print("Final counter value:", counter.value())
    print("Final counter state:", counter.getState())

