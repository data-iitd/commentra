import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

class Main:
    # List to hold the items of type T
    list = []
    # List to hold actions that will be applied to the stream
    actions = []

    # Constructor to initialize the list
    def __init__(self, list):
        self.list = list

    # Method to filter the list based on a given predicate
    def filter(self, predicate):
        # Add a new action to the list of actions
        self.actions.append(lambda stream: {
            result = []
            # Iterate through the items in the stream's list
            for item in stream.list:
                # If the item matches the predicate, add it to the result list
                if predicate(item):
                    result.append(item)
            # Update the stream's list to the filtered result
            stream.list = result
        })
        return self # Return the current instance for method chaining

    # Method to map the items in the list to a different type R
    def map(self, mapper):
        mappedList = []
        # Iterate through the items in the current list
        for item in self.list:
            # Apply the mapper function to each item and add to the mapped list
            mappedList.append(mapper(item))
        # Return a new Main instance containing the mapped list
        return Main(mappedList)

    # Method to collect the results into a list after applying all actions
    def collectToList(self):
        # Apply each action in the actions list to the current stream
        for action in self.actions:
            action(self)
        # Return the final list after all actions have been applied
        return self.list

# Main method to execute the program
if __name__ == '__main__':
    scanner = Scanner(System.in)
    # Read the number of items to be processed
    n = scanner.nextInt()
    list = []
    # Read each item and add it to the list
    for i in range(n):
        x = scanner.nextInt()
        y = scanner.nextInt()
        list.append(Item(x, y))
    # Create a Main instance with the list of items
    stream = Main(list)
    # Filter items where y > 10, map to x values, and collect the results
    result = stream \
       .filter(lambda item: item.getY() > 10) # Filter condition \
       .map(lambda item: item.getX()) # Mapping function to get x values \
       .collectToList() # Collect the results into a list
    # Print the resulting list of integers
    print(result)
    # Close the scanner to prevent resource leaks
    scanner.close()

# Class representing an item with two integer properties
class Item:
    x = 0
    y = 0

    # Constructor to initialize the item with x and y values
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Getter for x value
    def getX(self):
        return self.x

    # Getter for y value
    def getY(self):
        return self.y

    # Override toString method for better representation of Item
    def __str__(self):
        return "Item{" + "x=" + self.x + ", y=" + self.y + '}'

