
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
        # Initialize the array with the given capacity.

    def add(self, element):
        self.ensureCapacity(self.size + 1)
        self.elements[self.size] = element
        self.size += 1
        self.modCount += 1
        # Increment the modification counter.

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: " + index + ", Size: " + self.size)
        return self.elements[index]
        # Return the element at the specified index.

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: " + index + ", Size: " + self.size)
        oldElement = self.elements[index]
        self.fastRemove(index)
        self.modCount += 1
        return oldElement
        # Remove the element at the specified index and return it.

    def getSize(self):
        return self.size
        # Return the size of this list.

    def isEmpty(self):
        return self.size == 0
        # Return true if this list contains no elements.

    def ensureCapacity(self, minCapacity):
        if minCapacity > len(self.elements):
            newCapacity = max(len(self.elements) * 2, minCapacity)
            self.elements = self.elements[:newCapacity]
            # Increase the capacity of the array if needed.

    def fastRemove(self, index):
        numMoved = self.size - index - 1
        if numMoved > 0:
            self.elements[index:self.size - 1] = self.elements[index + 1:self.size]
        self.elements[self.size - 1] = None
        self.size -= 1
        # Remove the element at the specified index and shift the subsequent elements left.

    def __str__(self):
        return str(self.elements[:self.size])
        # Return a string representation of the underlying array.

    def __iter__(self):
        return self.iterator()
        # Return an iterator to traverse the elements in this list.

    def iterator(self):
        return MainIterator(self)
        # Return an iterator to traverse the elements in this list.

class MainIterator(Iterator):
    def __init__(self, main):
        self.main = main
        self.cursor = 0
        self.expectedModCount = main.modCount
        # Initialize the cursor and the expected modification counter.

    def hasNext(self):
        self.checkForComodification()
        return self.cursor < self.main.size
        # Check if there are more elements to iterate.

    def next(self):
        self.checkForComodification()
        if self.cursor >= self.main.size:
            raise NoSuchElementException()
        return self.main.elements[self.cursor]
        # Return the next element and increment the cursor.

    def checkForComodification(self):
        if self.main.modCount!= self.expectedModCount:
            raise ConcurrentModificationException()
        # Throw a ConcurrentModificationException if the list has been modified.

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
    # Demonstrate the usage of the Main class by reading commands from the standard input.

