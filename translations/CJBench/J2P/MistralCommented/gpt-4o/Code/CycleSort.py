class Main:
    def sort(self, array):
        length = len(array)  # Get the length of the array

        # The outer loop runs through each cycle of the bubble sort algorithm
        for cycle_start in range(length - 1):
            item = array[cycle_start]  # Get the item to be placed at its correct position
            pos = self.find_position(array, cycle_start, item)  # Find the position where the item should be placed

            # If the item is already at its correct position, skip to the next cycle
            if pos == cycle_start:
                continue

            # Swap the item with the element at its correct position
            item = self.place_item(array, item, pos)

            # Repeat the process for the next item in the array
            while pos != cycle_start:
                pos = self.find_position(array, cycle_start, item)
                item = self.place_item(array, item, pos)

        # Return the sorted array
        return array

    # The find_position method finds the position where the given item should be placed in the array
    def find_position(self, array, cycle_start, item):
        pos = cycle_start  # Initialize the position variable

        # Iterate through the array starting from the position after the current cycle start
        for i in range(cycle_start + 1, len(array)):
            # If the current element is less than the item, increment the position variable
            if array[i] < item:
                pos += 1

        # Return the position where the item should be placed
        return pos

    # The place_item method swaps the item with the element at its correct position in the array
    def place_item(self, array, item, pos):
        # Swap the item with the element at its correct position
        temp = array[pos]
        array[pos] = item
        return temp

# Main execution
if __name__ == "__main__":
    # Read the size of the array from the user
    n = int(input("Enter the size of the array: "))

    # Create a list of the given size
    array = []

    # Read the elements of the array from the user
    print("Enter the elements of the array:")
    for _ in range(n):
        array.append(int(input()))

    # Create an instance of the Main class and call its sort method to sort the array
    sorter = Main()
    sorted_array = sorter.sort(array)

    # Print the sorted elements of the array to the console
    print("Sorted array:", ' '.join(map(str, sorted_array)))

# <END-OF-CODE>
