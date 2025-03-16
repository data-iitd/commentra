import sys

class Main:
    def sort(self, array):
        length = len(array)
        for cycleStart in range(0, length - 2):
            item = array[cycleStart]
            pos = self.findPosition(array, cycleStart, item)
            if pos == cycleStart:
                continue
            item = self.placeItem(array, item, pos)
            while pos!= cycleStart:
                pos = self.findPosition(array, cycleStart, item)
                item = self.placeItem(array, item, pos)
        return array

    def findPosition(self, array, cycleStart, item):
        pos = cycleStart
        for i in range(cycleStart + 1, len(array)):
            if array[i] < item:
                pos += 1
        return pos

    def placeItem(self, array, item, pos):
        while item == array[pos]:
            pos += 1
        return self.replace(array, pos, item)

    def replace(self, array, pos, item):
        replacedItem = array[pos]
        array[pos] = item
        return replacedItem

if __name__ == "__main__":
    main = Main()
    array = [int(x) for x in sys.stdin.readline().split()]
    print(" ".join(str(x) for x in main.sort(array)))

