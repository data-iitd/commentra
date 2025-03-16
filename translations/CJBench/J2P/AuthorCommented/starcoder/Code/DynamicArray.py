
import java.util.Arrays;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.Scanner;
import java.util.function.Consumer;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

class Main:
    DEFAULT_CAPACITY = 16

    def __init__(self, capacity=DEFAULT_CAPACITY):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
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
            raise IndexError("Index: " + index + ", Size: " + self.size)
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: " + index + ", Size: " + self.size)
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
            self.elements[index:self.size - 1] = self.elements[index + 1:self.size]
        self.elements[self.size - 1] = None
        self.size -= 1

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        return self.iterator()

    def iterator(self):
        return MainIterator(self)


class MainIterator:
    def __init__(self, main):
        self.main = main
        self.cursor = 0
        self.expectedModCount = main.modCount

    def hasNext(self):
        self.checkForComodification()
        return self.cursor < self.main.size

    def next(self):
        self.checkForComodification()
        if self.cursor >= self.main.size:
            raise NoSuchElementException()
        return self.main.elements[self.cursor]

    def checkForComodification(self):
        if self.main.modCount!= self.expectedModCount:
            raise ConcurrentModificationException()


if __name__ == "__main__":
    scanner = Scanner(System.in)
    dynamicArray = Main()

    operations = scanner.nextInt()
    scanner.nextLine()

    for i in range(operations):
        input = scanner.nextLine().split(" ")
        command = input[0]

        if command.upper() == "ADD":
            value = int(input[1])
            dynamicArray.add(value)
        elif command.upper() == "REMOVE":
            removeIndex = int(input[1])
            try:
                dynamicArray.remove(removeIndex)
            except IndexError as e:
                print("Error: " + e.getMessage())
        elif command.upper() == "GET":
            getIndex = int(input[1])
            try:
                print("Value at index " + getIndex + ": " + dynamicArray.get(getIndex))
            except IndexError as e:
                print("Error: " + e.getMessage())
        else:
            print("Invalid command.")

    print("Final array: " + str(dynamicArray))
    print("Array size: " + str(dynamicArray.getSize()))

