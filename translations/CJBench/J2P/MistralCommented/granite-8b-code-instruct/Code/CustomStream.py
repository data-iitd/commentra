

import sys

# Main class for handling a list of items and applying filters and transformations
class Main:
    # Private instance variable for the list of items
    def __init__(self, list):
        self.list = list

    # Method for filtering the items based on a given predicate
    def filter(self, predicate):
        # Add an action to the list of actions to filter the items
        self.actions.append(lambda stream: {
            'list': [item for item in stream.list if predicate(item)]
        })
        # Return the current Main object for method chaining
        return self

    # Method for transforming each item in the list using a given mapper function
    def map(self, mapper):
        # Create a new list to store the transformed items
        mappedList = [mapper(item) for item in self.list]
        # Return a new Main object with the transformed list
        return Main(mappedList)

    # Method for collecting the items in the list into a List
    def collectToList(self):
        # Iterate through each action in the list of actions and apply it to the stream
        for action in self.actions:
            stream = action(self)
            self.list = stream['list']
        # Return the original list after applying all the actions
        return self.list

    # Main method for running the program and demonstrating the usage of the Main class
    @staticmethod
    def main():
        # Create a Scanner object for reading input from the console
        scanner = sys.stdin
        # Read the number of items to be added to the list from the console
        n = int(scanner.readline())
        # Create an ArrayList to store the items
        list = []
        # Iterate through each item and add it to the list
        for i in range(n):
            x, y = map(int, scanner.readline().split())
            # Create an Item object with the given x and y coordinates and add it to the list
            list.append((x, y))
        # Create a Main object with the given list and apply filters and transformations to it
        stream = Main(list)
        # Filter the items based on the y coordinate being greater than 10
        result = stream \
            # Apply the filter method to the stream object
           .filter(lambda item: item[1] > 10) \
            # Map each filtered item to its x coordinate
           .map(lambda item: item[0]) \
            # Collect the transformed items into a List
           .collectToList()
        # Print the result to the console
        print(result)
        # Close the Scanner object
        scanner.close()

# Static inner class for defining the Item object
class Item:
    # Private instance variables for storing the x and y coordinates
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Override the __str__ method for printing the Item object in a readable format
    def __str__(self):
        return f"Item(x={self.x}, y={self.y})"

# Call the main method to run the program
Main.main()

Translate the above Python code to JavaScript and end with comment "