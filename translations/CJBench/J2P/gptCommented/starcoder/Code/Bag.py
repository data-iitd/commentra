import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;

class Main:
    # The first element of the linked list
    firstElement = None
    # The size of the linked list
    size = 0

    # Inner class representing a node in the linked list
    class Node:
        content = None
        nextElement = None

    # Constructor to initialize the linked list
    def __init__(self):
        self.firstElement = None
        self.size = 0

    # Method to check if the linked list is empty
    def isEmpty(self):
        return self.size == 0

    # Method to get the size of the linked list
    def size(self):
        return self.size

    # Method to add an element to the linked list
    def add(self, element):
        newNode = self.Node()
        newNode.content = element
        newNode.nextElement = self.firstElement
        self.firstElement = newNode
        self.size += 1

    # Method to check if the linked list contains a specific element
    def contains(self, element):
        for value in self:
            if value == element:
                return True
        return False

    # Method to return an iterator for the linked list
    def iterator(self):
        return self.ListIterator(self.firstElement)

    # Inner class implementing the iterator for the linked list
    class ListIterator(Iterator):
        currentElement = None

        # Constructor to initialize the iterator with the first element
        def __init__(self, firstElement):
            self.currentElement = firstElement

        # Method to check if there are more elements to iterate
        def hasNext(self):
            return self.currentElement!= None

        # Method to get the next element in the iteration
        def next(self):
            if not self.hasNext():
                raise NoSuchElementException("No more elements in the bag.")
            element = self.currentElement.content
            self.currentElement = self.currentElement.nextElement
            return element

    # Main method to run the program
    def main(self):
        scanner = Scanner(System.in)
        bag = Main()
        n = scanner.nextInt()
        scanner.nextLine()

        for i in range(n):
            element = scanner.nextLine()
            bag.add(element)

        # Print the contents of the linked list
        print("Main contents:")
        for element in bag:
            print(element)

        # Check if a specific element is contained in the linked list
        checkElement = scanner.nextLine()
        print("Contains " + checkElement + ": " + bag.contains(checkElement))

        # Print the size of the linked list
        print("Main size: " + bag.size())

        # Check if the linked list is empty
        print("Is bag empty: " + bag.isEmpty())

# 