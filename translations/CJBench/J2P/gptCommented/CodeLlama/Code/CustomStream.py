
import sys

# Function to filter the list based on a given predicate
def filter(predicate, list):
    result = []
    for item in list:
        if predicate(item):
            result.append(item)
    return result

# Function to map the items in the list to a different type R
def map(mapper, list):
    mapped_list = []
    for item in list:
        mapped_list.append(mapper(item))
    return mapped_list

# Function to collect the results into a list after applying all actions
def collect_to_list(actions, list):
    for action in actions:
        list = action(list)
    return list

# Main method to execute the program
def main():
    # Read the number of items to be processed
    n = int(input())
    list = []
    # Read each item and add it to the list
    for i in range(n):
        x, y = map(int, input().split())
        list.append(Item(x, y))
    # Create a Main instance with the list of items
    stream = Main(list)
    # Filter items where y > 10, map to x values, and collect the results
    result = stream.filter(lambda item: item.y > 10) \
                   .map(lambda item: item.x) \
                   .collect_to_list()
    # Print the resulting list of integers
    print(result)

# Class representing an item with two integer properties
class Item:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Getter for x value
    def get_x(self):
        return self.x

    # Getter for y value
    def get_y(self):
        return self.y

    # Override toString method for better representation of Item
    def __str__(self):
        return "Item{" + "x=" + str(self.x) + ", y=" + str(self.y) + "}"

# Functional interface for actions to be applied to the stream
class Action:
    def __init__(self, action):
        self.action = action

    # Apply the action to the stream
    def apply(self, stream):
        self.action(stream)

# Main class to hold the items of type T and apply actions to the stream
class Main:
    # Constructor to initialize the list
    def __init__(self, list):
        self.list = list
        self.actions = []

    # Method to filter the list based on a given predicate
    def filter(self, predicate):
        # Add a new action to the list of actions
        self.actions.append(Action(lambda stream: stream.list = filter(predicate, stream.list)))
        return self # Return the current instance for method chaining

    # Method to map the items in the list to a different type R
    def map(self, mapper):
        mapped_list = map(mapper, self.list)
        return Main(mapped_list)

    # Method to collect the results into a list after applying all actions
    def collect_to_list(self):
        # Apply each action in the actions list to the current stream
        for action in self.actions:
            action.apply(self)
        # Return the final list after all actions have been applied
        return self.list

if __name__ == "__main__":
    main()

