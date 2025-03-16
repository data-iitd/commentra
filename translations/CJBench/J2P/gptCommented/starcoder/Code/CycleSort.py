import sys

class Main:
    def __init__(self):
        self.array = []
        self.length = 0

    def sort(self, array):
        self.array = array
        self.length = len(array)

        for cycleStart in range(0, self.length - 2):
            item = self.array[cycleStart]
            pos = self.findPosition(cycleStart, item)

            if pos == cycleStart:
                continue

            item = self.placeItem(item, pos)

            while pos!= cycleStart:
                pos = self.findPosition(cycleStart, item)
                item = self.placeItem(item, pos)

        return self.array

    def findPosition(self, cycleStart, item):
        pos = cycleStart

        for i in range(cycleStart + 1, self.length):
            if self.array[i] < item:
                pos += 1

        return pos

    def placeItem(self, item, pos):
        while item == self.array[pos]:
            pos += 1

        replacedItem = self.array[pos]
        self.array[pos] = item

        return replacedItem

if __name__ == "__main__":
    main = Main()
    array = [int(x) for x in sys.stdin.readline().split()]
    print(" ".join(str(x) for x in main.sort(array)))

