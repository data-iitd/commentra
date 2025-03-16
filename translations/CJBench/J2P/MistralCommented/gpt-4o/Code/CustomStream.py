from typing import List, Callable, TypeVar, Generic

T = TypeVar('T')
R = TypeVar('R')

# Main class for handling a list of items and applying filters and transformations
class Main(Generic[T]):
    def __init__(self, items: List[T]):
        self.items = items
        self.actions: List[Callable[['Main[T]'], None]] = []

    # Method for filtering the items based on a given predicate
    def filter(self, predicate: Callable[[T], bool]) -> 'Main[T]':
        # Add an action to the list of actions to filter the items
        self.actions.append(lambda stream: stream.items[:] = [item for item in stream.items if predicate(item)])
        # Return the current Main object for method chaining
        return self

    # Method for transforming each item in the list using a given mapper function
    def map(self, mapper: Callable[[T], R]) -> 'Main[R]':
        # Create a new list to store the transformed items
        mapped_list = [mapper(item) for item in self.items]
        # Return a new Main object with the transformed list
        return Main(mapped_list)

    # Method for collecting the items in the list into a List
    def collect_to_list(self) -> List[T]:
        # Iterate through each action in the list of actions and apply it to the stream
        for action in self.actions:
            action(self)
        # Return the original list after applying all the actions
        return self.items

# Static inner class for defining the Item object
class Item:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    # Getter method for retrieving the x coordinate
    def get_x(self) -> int:
        return self.x

    # Getter method for retrieving the y coordinate
    def get_y(self) -> int:
        return self.y

    # Override the __str__ method for printing the Item object in a readable format
    def __str__(self) -> str:
        return f"Item{{x={self.x}, y={self.y}}}"

# Main method for running the program and demonstrating the usage of the Main class
if __name__ == "__main__":
    # Read the number of items to be added to the list from the console
    n = int(input())
    # Create a list to store the items
    items = []
    # Iterate through each item and add it to the list
    for _ in range(n):
        x, y = map(int, input().split())
        # Create an Item object with the given x and y coordinates and add it to the list
        items.append(Item(x, y))
    
    # Create a Main object with the given list and apply filters and transformations to it
    stream = Main(items)
    # Filter the items based on the y coordinate being greater than 10
    result = stream.filter(lambda item: item.get_y() > 10) \
                    .map(Item.get_x) \
                    .collect_to_list()
    # Print the result to the console
    print(result)

# <END-OF-CODE>
