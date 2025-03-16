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
    # Default capacity for the dynamic array
    DEFAULT_CAPACITY = 16
    size = 0 # Current number of elements in the array
    modCount = 0 # Modification count for tracking changes
    elements = [] # Array to store the elements

    # Constructor with specified capacity
    def __init__(self, capacity=DEFAULT_CAPACITY):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0 # Initialize size to 0
        self.modCount = 0 # Initialize modification count to 0
        self.elements = [None] * capacity # Create an array with the specified capacity

    # Default constructor that uses the default capacity
    def __init__(self):
        self.__init__(self.DEFAULT_CAPACITY)

    # Method to add an element to the dynamic array
    def add(self, element):
        self.ensureCapacity(self.size + 1) # Ensure there is enough capacity
        self.elements[self.size] = element # Add the element and increment size
        self.modCount += 1 # Increment modification count

    # Method to retrieve an element at a specific index
    def get(self, index):
        # Check if the index is within bounds
        if index < 0 or index >= self.size:
            raise IndexError("Index: " + index + ", Size: " + self.size)
        return self.elements[index] # Return the element at the specified index

    # Method to remove an element at a specific index
    def remove(self, index):
        # Check if the index is within bounds
        if index < 0 or index >= self.size:
            raise IndexError("Index: " + index + ", Size: " + self.size)
        oldElement = self.elements[index] # Store the element to be removed
        self.fastRemove(index) # Remove the element
        self.modCount += 1 # Increment modification count
        return oldElement # Return the removed element

    # Method to get the current size of the dynamic array
    def getSize(self):
        return self.size # Return the size

    # Method to check if the dynamic array is empty
    def isEmpty(self):
        return self.size == 0 # Return true if size is 0, otherwise false

    # Method to ensure the array has enough capacity to accommodate new elements
    def ensureCapacity(self, minCapacity):
        # If the current capacity is less than the minimum required capacity
        if minCapacity > self.elements.length:
            # Calculate new capacity (double the current or minimum required)
            newCapacity = max(self.elements.length * 2, minCapacity)
            self.elements = self.elements[:newCapacity] # Resize the array

    # Method to remove an element quickly without shifting all elements
    def fastRemove(self, index):
        numMoved = self.size - index - 1 # Calculate number of elements to move
        if numMoved > 0:
            # Shift elements to fill the gap
            self.elements[index:self.size - 1] = self.elements[index + 1:self.size]
        self.elements[self.size - 1] = None # Null out the last element and decrement size

    # Override toString method to display the dynamic array
    def __str__(self):
        return str(self.elements[:self.size]) # Return a string representation of the array

    # Override iterator method to return an instance of the custom iterator
    def __iter__(self):
        return self.MainIterator() # Return a new iterator instance

    # Inner class for the custom iterator
    class MainIterator(Iterator):
        cursor = 0 # Current position in the iteration
        expectedModCount = 0 # Expected modification count for fail-fast behavior

        # Constructor for the iterator
        def __init__(self):
            self.expectedModCount = self.modCount # Initialize expected modification count

        # Method to check if there are more elements to iterate over
        def hasNext(self):
            self.checkForComodification() # Check for concurrent modifications
            return self.cursor < self.size # Return true if there are more elements

        # Method to retrieve the next element in the iteration
        def next(self):
            self.checkForComodification() # Check for concurrent modifications
            if self.cursor >= self.size:
                raise StopIteration() # Throw exception if no more elements
            return self.elements[self.cursor++] # Return the current element and increment cursor

        # Method to check for concurrent modifications
        def checkForComodification(self):
            if self.modCount!= self.expectedModCount:
                raise ConcurrentModificationException() # Throw exception if modification count has changed

    # Main class for demonstration
    @staticmethod
    def main(args):
        scanner = Scanner(System.in) # Create a scanner for input
        dynamicArray = Main() # Create a new dynamic array instance
        operations = scanner.nextInt() # Read the number of operations
        scanner.nextLine() # Consume the newline character

        # Loop through the number of operations
        for i in range(operations):
            input = scanner.nextLine().split(" ") # Read and split the input line
            command = input[0] # Get the command
            if command.upper() == "ADD":
                value = int(input[1]) # Parse the value to add
                dynamicArray.add(value) # Add the value to the dynamic array
            elif command.upper() == "REMOVE":
                removeIndex = int(input[1]) # Parse the index to remove
                try:
                    dynamicArray.remove(removeIndex) # Attempt to remove the element
                except IndexError as e:
                    print("Error: " + e.getMessage()) # Handle index out of bounds
            elif command.upper() == "GET":
                getIndex = int(input[1]) # Parse the index to get
                try:
                    print("Value at index " + getIndex + ": " + dynamicArray.get(getIndex)) # Retrieve and print the value
                except IndexError as e:
                    print("Error: " + e.getMessage()) # Handle index out of bounds
            else:
                print("Invalid command.") # Handle invalid commands
        # Print the final state of the dynamic array and its size
        print("Final array: " + str(dynamicArray))
        print("Array size: " + str(dynamicArray.getSize()))

# 