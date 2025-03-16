import sys

class Main:
    def __init__(self):
        self.scanner = sys.stdin

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

    def main(self):
        n = int(self.scanner.readline())
        array = []
        for i in range(0, n):
            array.append(int(self.scanner.readline()))
        array = self.sort(array)
        for num in array:
            print(num, end=" ")
        print()

    def __del__(self):
        del self.scanner

if __name__ == "__main__":
    main = Main()
    main.main()

