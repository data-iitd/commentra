
import sys

class Main:
    def __init__(self):
        pass

    # The sort method sorts the given array using the bubble sort algorithm
    def sort(self, array):
        length = len(array) # Get the length of the array

        # The outer loop runs through each cycle of the bubble sort algorithm
        for cycleStart in range(0, length - 2):
            item = array[cycleStart] # Get the item to be placed at its correct position
            pos = self.findPosition(array, cycleStart, item) # Find the position where the item should be placed

            # If the item is already at its correct position, skip to the next cycle
            if pos == cycleStart:
                continue

            # Swap the item with the element at its correct position
            item = self.placeItem(array, item, pos)

            # Repeat the process for the next item in the array
            while pos!= cycleStart:
                pos = self.findPosition(array, cycleStart, item)
                item = self.placeItem(array, item, pos)

        # Return the sorted array
        return array

    # The findPosition method finds the position where the given item should be placed in the array
    def findPosition(self, array, cycleStart, item):
        pos = cycleStart # Initialize the position variable

        # Iterate through the array starting from the position after the current cycle start
        for i in range(cycleStart + 1, len(array)):
            # If the current element is less than the item, increment the position variable
            if array[i] < item:
                pos += 1

        # Return the position where the item should be placed
        return pos

    # The placeItem method swaps the item with the element at its correct position in the array
    def placeItem(self, array, item, pos):
        # Swap the item with the element at its correct position
        temp = array[pos]
        array[pos] = item
        return temp

    # The replace method swaps the elements at the given positions in the array
    def replace(self, array, pos, item):
        # Swap the elements at the given positions
        temp = array[pos]
        array[pos] = item
        return temp

# Create a Main object and call its sort method to sort the array
if __name__ == "__main__":
    main = Main()
    array = [int(x) for x in sys.stdin.readline().split()]
    array = main.sort(array)

    # Print the sorted elements of the array to the console
    for num in array:
        print(num, end=" ")

