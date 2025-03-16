
import sys

def main():
    # Create a Scanner object to read input from the user
    scanner = Scanner(sys.stdin)

    # Read the size of the array from the user
    n = scanner.nextInt()

    # Create an Integer array of the given size
    array = [None] * n

    # Read the elements of the array from the user
    for i in range(n):
        array[i] = scanner.nextInt()

    # Create an instance of the Main class and call its sort method to sort the array
    sorter = Main()
    array = sorter.sort(array)

    # Print the sorted elements of the array to the console
    for num in array:
        print(num, end=" ")

    # Close the Scanner object to free up system resources
    scanner.close()

class Main:
    # The sort method sorts the given array using the bubble sort algorithm
    def sort(self, array):
        length = len(array) # Get the length of the array

        # The outer loop runs through each cycle of the bubble sort algorithm
        for cycleStart in range(length - 1):
            item = array[cycleStart] # Get the item to be placed at its correct position
            pos = self.findPosition(array, cycleStart, item) # Find the position where the item should be placed

            # If the item is already at its correct position, skip to the next cycle
            if pos == cycleStart:
                continue

            # Swap the item with the element at its correct position
            item = self.placeItem(array, item, pos)

            # Repeat the process for the next item in the array
            while pos != cycleStart:
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

if __name__ == "__main__":
    main()

