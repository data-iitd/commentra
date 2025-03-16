
import sys

# Define a function to filter items based on a given predicate
def filter(predicate):
    def decorator(func):
        def wrapper(stream):
            result = []
            for item in stream:
                if predicate(item):
                    result.append(item)
            return result
        return wrapper
    return decorator

# Define a function to map items to a different type R
def map(mapper):
    def decorator(func):
        def wrapper(stream):
            mapped_list = []
            for item in stream:
                mapped_list.append(mapper(item))
            return mapped_list
        return wrapper
    return decorator

# Define a function to collect the results into a list after applying all actions
def collect_to_list():
    def decorator(func):
        def wrapper(stream):
            result = func(stream)
            return result
        return wrapper
    return decorator

# Define a class to represent an item with two integer properties
class Item:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Override __str__ method for better representation of Item
    def __str__(self):
        return f"Item(x={self.x}, y={self.y})"

# Main function to execute the program
def main():
    n = int(input())
    items = []
    # Read each item and add it to the list
    for _ in range(n):
        x, y = map(int, input().split())
        items.append(Item(x, y))
    # Create a Main instance with the list of items
    stream = items
    # Filter items where y > 10, map to x values, and collect the results
    result = stream \
        |> filter(lambda item: item.y > 10) \
        |> map(lambda item: item.x) \
        |> collect_to_list()
    # Print the resulting list of integers
    print(result)

# Execute the main function
if __name__ == "__main__":
    main()

