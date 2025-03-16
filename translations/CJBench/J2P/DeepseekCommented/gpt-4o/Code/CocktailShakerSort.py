def main():
    # Read the number of elements in the array
    n = int(input())
    # Read n elements into the array
    array = list(map(int, input().split()))
    # Create an instance of the Main class to use its sorting method
    sorter = Main()
    # Call the sort method on the array
    sorter.sort(array)
    # Print the sorted array
    print(" ".join(map(str, array)))

class Main:
    def sort(self, array):
        # If the array is empty, return immediately
        if len(array) == 0:
            return
        # Initialize pointers for the forward and backward passes
        left = 0
        right = len(array) - 1
        # Continue sorting until the left pointer meets the right pointer
        while left < right:
            # Perform the forward pass and update the right pointer
            right = self.perform_forward_pass(array, left, right)
            # Perform the backward pass and update the left pointer
            left = self.perform_backward_pass(array, left, right)

    def perform_forward_pass(self, array, left, right):
        # Track the last swapped index in the forward pass
        last_swapped_index = left
        # Iterate through the array from left to right-1
        for i in range(left, right):
            # Swap if the current element is greater than the next element
            if array[i] > array[i + 1]:
                self.swap(array, i, i + 1)
                last_swapped_index = i
        # Return the last swapped index for the next pass
        return last_swapped_index

    def perform_backward_pass(self, array, left, right):
        # Track the last swapped index in the backward pass
        last_swapped_index = right
        # Iterate through the array from right to left+1
        for i in range(right, left, -1):
            # Swap if the current element is less than the previous element
            if array[i] < array[i - 1]:
                self.swap(array, i - 1, i)
                last_swapped_index = i
        # Return the last swapped index for the next pass
        return last_swapped_index

    def swap(self, array, i, j):
        array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    main()
