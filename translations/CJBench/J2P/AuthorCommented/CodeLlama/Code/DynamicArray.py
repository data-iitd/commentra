
class Main:
    def __init__(self, capacity=16):
        self.size = 0
        self.modCount = 0
        self.elements = [None] * capacity

    def add(self, element):
        self.ensureCapacity(self.size + 1)
        self.elements[self.size] = element
        self.size += 1
        self.modCount += 1

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: {}, Size: {}".format(index, self.size))
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: {}, Size: {}".format(index, self.size))
        oldElement = self.elements[index]
        self.fastRemove(index)
        self.modCount += 1
        return oldElement

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    def ensureCapacity(self, minCapacity):
        if minCapacity > len(self.elements):
            newCapacity = max(len(self.elements) * 2, minCapacity)
            self.elements = self.elements[:newCapacity]

    def fastRemove(self, index):
        numMoved = self.size - index - 1
        if numMoved > 0:
            self.elements[index:index + numMoved] = self.elements[index + 1:index + numMoved + 1]
        self.elements[self.size - 1] = None
        self.size -= 1

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        return MainIterator(self)

    def __repr__(self):
        return "Main({})".format(self.elements[:self.size])


class MainIterator:
    def __init__(self, main):
        self.main = main
        self.cursor = 0
        self.expectedModCount = main.modCount

    def __iter__(self):
        return self

    def __next__(self):
        self.checkForComodification()
        if self.cursor >= self.main.size:
            raise StopIteration
        return self.main.elements[self.cursor]

    def checkForComodification(self):
        if self.main.modCount != self.expectedModCount:
            raise ConcurrentModificationError


class MainDemo:
    def __init__(self):
        self.main = Main()

    def run(self):
        operations = int(input())
        for _ in range(operations):
            command, *args = input().split()
            if command == "ADD":
                self.main.add(int(args[0]))
            elif command == "REMOVE":
                try:
                    self.main.remove(int(args[0]))
                except IndexError as e:
                    print("Error:", e)
            elif command == "GET":
                try:
                    print("Value at index {}: {}".format(int(args[0]), self.main.get(int(args[0]))))
                except IndexError as e:
                    print("Error:", e)
            else:
                print("Invalid command.")

        print("Final array:", self.main)
        print("Array size:", self.main.getSize())


if __name__ == "__main__":
    MainDemo().run()

