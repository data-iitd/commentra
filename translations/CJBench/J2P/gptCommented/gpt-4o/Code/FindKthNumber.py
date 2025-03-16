import random

class Main:
    @staticmethod
    def find_kth_max(array, k):
        # Validate the value of k
        if k <= 0 or k > len(array):
            raise ValueError("k must be between 1 and the size of the array")
        # Call quick_select to find the k-th largest element
        return Main.quick_select(array, 0, len(array) - 1, len(array) - k)

    @staticmethod
    def quick_select(array, left, right, k_smallest):
        # Base case: if the list contains only one element
        if left == right:
            return array[left]
        # Randomly select a pivot index
        pivot_index = left + random.randint(0, right - left)
        # Partition the array around the pivot
        pivot_index = Main.partition(array, left, right, pivot_index)

        # Check if the pivot is the k-th smallest element
        if k_smallest == pivot_index:
            return array[k_smallest]
        elif k_smallest < pivot_index:
            return Main.quick_select(array, left, pivot_index - 1, k_smallest)
        else:
            return Main.quick_select(array, pivot_index + 1, right, k_smallest)

    @staticmethod
    def partition(array, left, right, pivot_index):
        # Store the pivot value
        pivot_value = array[pivot_index]
        # Move the pivot to the end of the array
        Main.swap(array, pivot_index, right)
        store_index = left

        # Rearrange the array elements based on the pivot value
        for i in range(left, right):
            if array[i] < pivot_value:
                Main.swap(array, store_index, i)
                store_index += 1
        # Move the pivot to its final place
        Main.swap(array, store_index, right)
        return store_index  # Return the final index of the pivot

    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    try:
        # Read the size of the array
        n = int(input())
        # Validate the size of the array
        if n <= 0:
            print("Array size must be positive.")
            exit()
        # Initialize the array and read its elements
        array = list(map(int, input().split()))
        # Read the value of k
        k = int(input())
        # Validate the value of k
        if k <= 0 or k > n:
            print("Error: k must be between 1 and the size of the array.")
            exit()
        # Find the k-th largest element and print the result
        result = Main.find_kth_max(array, k)
        print(f"The {k}-th largest element is: {result}")
    except Exception as e:
        # Handle any exceptions that occur during input or processing
        print(f"An error occurred: {e}")
