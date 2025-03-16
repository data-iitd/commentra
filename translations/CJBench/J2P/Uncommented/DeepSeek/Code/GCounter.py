from collections import defaultdict
import sys

class Main:
    def __init__(self, myId, n):
        self.counterMap = defaultdict(int)
        self.myId = myId
        self.n = n
        for i in range(n):
            self.counterMap[i] = 0

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
        return dict(self.counterMap)

    @staticmethod
    def main(args):
        n = int(sys.stdin.readline().strip())
        myId = int(sys.stdin.readline().strip())
        counter = Main(myId, n)
        operations = int(sys.stdin.readline().strip())
        for _ in range(operations):
            operation = list(map(int, sys.stdin.readline().strip().split()))
            if operation[0] == 1:
                counter.increment()
            elif operation[0] == 2:
                mergeId = int(sys.stdin.readline().strip())
                otherCounter = Main(mergeId, n)
                otherState = list(map(int, sys.stdin.readline().strip().split()))
                for i in range(n):
                    otherCounter.counterMap[i] = otherState[i]
                counter.merge(otherCounter)
            else:
                print("Invalid operation.")
        print("Final counter value: " + str(counter.value()))
        print("Final counter state: " + str(counter.getState()))

Main.main(sys.argv)
