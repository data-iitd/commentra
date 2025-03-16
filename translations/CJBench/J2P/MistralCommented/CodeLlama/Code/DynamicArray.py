
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
            raise IndexError("Index: " + str(index) + ", Size: " + str(self.size))
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: " + str(index) + ", Size: " + str(self.size))
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

    def __next__(self):
        if self.main.modCount != self.expectedModCount:
            raise ConcurrentModificationException()
        if self.cursor >= self.main.size:
            raise StopIteration()
        value = self.main.elements[self.cursor]
        self.cursor += 1
        return value

    def __iter__(self):
        return self

if __name__ == "__main__":
    import sys
    import io
    input = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    n = int(input())
    dynamicArray = Main()
    for _ in range(n):
        command = input().split()
        if command[0] == "ADD":
            dynamicArray.add(int(command[1]))
        elif command[0] == "REMOVE":
            try:
                dynamicArray.remove(int(command[1]))
            except IndexError as e:
                print("Error:", e)
        elif command[0] == "GET":
            try:
                print("Value at index", int(command[1]), ":", dynamicArray.get(int(command[1])))
            except IndexError as e:
                print("Error:", e)
        else:
            print("Invalid command.")
    print("Final array:", dynamicArray)
    print("Array size:", dynamicArray.getSize())
    # Demonstrate the usage of the Main class by reading commands from the standard input.

