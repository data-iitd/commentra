class Main:
    def sort(self, array):
        # Base case: if the array is empty, return without doing anything
        if len(array) == 0:
            return

        # Initialize two pointers, one at the beginning and another at the end of the array
        left = 0
        right = len(array) - 1

        # Repeat the following steps until the array is sorted
        while left < right:
            # Perform a forward pass to swap elements if they are in the wrong order
            right = self.perform_forward_pass(array, left, right)

            # Perform a backward pass to swap elements if they are in the wrong order
            left = self.perform_backward_pass(array, left, right)

    def perform_forward_pass(self, array, left, right):
        # Initialize a variable to keep track of the last index where a swap occurred
        last_swapped_index = left

        # Iterate through the array from the left pointer to the right pointer - 1
        for i in range(left, right):
            # If the current element is greater than the next element, swap them
            if array[i] > array[i + 1]:
                self.swap(array, i, i + 1)
                last_swapped_index = i

        # Return the last index where a swap occurred
        return last_swapped_index

    def perform_backward_pass(self, array, left, right):
        # Initialize a variable to keep track of the last index where a swap occurred
        last_swapped_index = right

        # Iterate through the array from the right pointer to the left pointer + 1
        for i in range(right, left, -1):
            # If the current element is smaller than the previous element, swap them
            if array[i] < array[i - 1]:
                self.swap(array, i - 1, i)
                last_swapped_index = i

        # Return the last index where a swap occurred
        return last_swapped_index

    def swap(self, array, i, j):
        # Swap the elements at the given indices
        array[i], array[j] = array[j], array[i]


if __name__ == "__main__":
    # Read the number of elements in the array from the user input
    n = int(input())

    # Allocate memory for an array of Integer type with the given size
    array = []

    # Read each element of the array from the user input
    for _ in range(n):
        array.append(int(input()))

    # Create an instance of the Main class and call the sort method to sort the array
    sorter = Main()
    sorter.sort(array)

    # Print each element of the sorted array to the console
    print(" ".join(map(str, array)))
    
# <END-OF-CODE>
