import array

class Main:
    def __init__(self, capacity=16):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0
        self.modCount = 0
        self.elements = array.array("O", [None] * capacity)

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
            self.elements = self.elements.copy()

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
        return "Main(size={}, modCount={}, elements={})".format(self.size, self.modCount, self.elements)


class MainIterator:
    def __init__(self, dynamicArray):
        self.dynamicArray = dynamicArray
        self.cursor = 0
        self.expectedModCount = dynamicArray.modCount

    def __iter__(self):
        return self

    def __next__(self):
        self.checkForComodification()
        if self.cursor >= self.dynamicArray.size:
            raise StopIteration
        value = self.dynamicArray.elements[self.cursor]
        self.cursor += 1
        return value

    def checkForComodification(self):
        if self.dynamicArray.modCount != self.expectedModCount:
            raise ConcurrentModificationError


class MainDemo:
    def main(self):
        operations = int(input())
        dynamicArray = Main()
        for i in range(operations):
            input_list = input().split()
            command = input_list[0]
            if command == "ADD":
                value = int(input_list[1])
                dynamicArray.add(value)
            elif command == "REMOVE":
                removeIndex = int(input_list[1])
                try:
                    dynamicArray.remove(removeIndex)
                except IndexError as e:
                    print("Error:", e)
            elif command == "GET":
                getIndex = int(input_list[1])
                try:
                    print("Value at index", getIndex, ":", dynamicArray.get(getIndex))
                except IndexError as e:
                    print("Error:", e)
            else:
                print("Invalid command.")
        print("Final array:", dynamicArray)
        print("Array size:", dynamicArray.getSize())


if __name__ == "__main__":
    MainDemo().main()
    # 