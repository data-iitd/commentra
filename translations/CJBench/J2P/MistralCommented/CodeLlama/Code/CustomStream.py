
# Main class for handling a list of items and applying filters and transformations
class Main:
    # Private instance variable for the list of items
    list = []
    # Private instance variable for the list of actions to be applied to the stream
    actions = []

    # Constructor for initializing the Main object with the given list
    def __init__(self, list):
        self.list = list

    # Method for filtering the items based on a given predicate
    def filter(self, predicate):
        # Add an action to the list of actions to filter the items
        self.actions.append(lambda stream: self.filter_items(stream, predicate))
        # Return the current Main object for method chaining
        return self

    # Method for transforming each item in the list using a given mapper function
    def map(self, mapper):
        # Create a new list to store the transformed items
        mapped_list = []
        # Iterate through each item in the list and apply the mapper function to transform it
        for item in self.list:
            # Apply the mapper function to the item and add the transformed result to the new list
            mapped_list.append(mapper(item))
        # Return a new Main object with the transformed list
        return Main(mapped_list)

    # Method for collecting the items in the list into a List
    def collect_to_list(self):
        # Iterate through each action in the list of actions and apply it to the stream
        for action in self.actions:
            action(self)
        # Return the original list after applying all the actions
        return self.list

    # Method for filtering the items based on a given predicate
    def filter_items(self, stream, predicate):
        # Create a new list to store the filtered items
        result = []
        # Iterate through each item in the list and add it to the result list if it satisfies the predicate
        for item in stream.list:
            if predicate(item):
                result.append(item)
        # Replace the original list with the filtered list
        stream.list = result

    # Main method for running the program and demonstrating the usage of the Main class
    @staticmethod
    def main():
        # Create a Scanner object for reading input from the console
        scanner = Scanner()
        # Read the number of items to be added to the list from the console
        n = scanner.next_int()
        # Create an ArrayList to store the items
        list = []
        # Iterate through each item and add it to the list
        for i in range(n):
            x = scanner.next_int()
            y = scanner.next_int()
            # Create an Item object with the given x and y coordinates and add it to the list
            list.append(Item(x, y))
        # Create a Main object with the given list and apply filters and transformations to it
        stream = Main(list)
        # Filter the items based on the y coordinate being greater than 10
        result = stream \
            # Apply the filter method to the stream object
            .filter(lambda item: item.y > 10) \
            # Map each filtered item to its x coordinate
            .map(lambda item: item.x) \
            # Collect the transformed items into a List
            .collect_to_list()
        # Print the result to the console
        print(result)
        # Close the Scanner object
        scanner.close()

    # Static inner class for defining the Item object
    class Item:
        # Private instance variables for storing the x and y coordinates
        x = 0
        y = 0

        # Constructor for initializing the Item object with the given x and y coordinates
        def __init__(self, x, y):
            self.x = x
            self.y = y

        # Getter method for retrieving the x coordinate
        def get_x(self):
            return self.x

        # Getter method for retrieving the y coordinate
        def get_y(self):
            return self.y

        # Override the toString method for printing the Item object in a readable format
        def __str__(self):
            return "Item{" + "x=" + str(self.x) + ", y=" + str(self.y) + "}"

# Main method for running the program and demonstrating the usage of the Main class
if __name__ == "__main__":
    Main.main()

