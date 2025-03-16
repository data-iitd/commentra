
import random

def find_kth_max(array, k):
    # Validate the value of k
    if k <= 0 or k > len(array):
        raise ValueError("k must be between 1 and the size of the array")
    # Call quick_select to find the k-th largest element
    return quick_select(array, 0, len(array) - 1, len(array) - k)

def quick_select(array, left, right, k_smallest):
    # Base case: if the list contains only one element
    if left == right:
        return array[left]
    # Randomly select a pivot index
    pivot_index = left + random.randint(0, right - left)
    # Partition the array around the pivot
    pivot_index = partition(array, left, right, pivot_index)
    # Check if the pivot is the k-th smallest element
    if k_smallest == pivot_index:
        return array[k_smallest]
    # If k_smallest is less than pivot_index, search in the left subarray
    elif k_smallest < pivot_index:
        return quick_select(array, left, pivot_index - 1, k_smallest)
    # If k_smallest is greater than pivot_index, search in the right subarray
    else:
        return quick_select(array, pivot_index + 1, right, k_smallest)

def partition(array, left, right, pivot_index):
    # Store the pivot value
    pivot_value = array[pivot_index]
    # Move the pivot to the end of the array
    array[pivot_index], array[right] = array[right], array[pivot_index]
    store_index = left
    # Rearrange the array elements based on the pivot value
    for i in range(left, right):
        if array[i] < pivot_value:
            array[i], array[store_index] = array[store_index], array[i]
            store_index += 1
    # Move the pivot to its final place
    array[right], array[store_index] = array[store_index], array[right]
    return store_index # Return the final index of the pivot

# Main method to execute the program
def main():
    n = int(input("Enter the size of the array: "))
    # Validate the size of the array
    if n <= 0:
        print("Array size must be positive.")
        return
    array = [int(x) for x in input("Enter the elements of the array separated by spaces: ").split()]
    k = int(input("Enter the value of k: "))
    # Validate the value of k
    if k <= 0 or k > n:
        print("Error: k must be between 1 and the size of the array.")
        return
    # Find the k-th largest element and print the result
    result = find_kth_max(array, k)
    print(f"The {k}-th largest element is: {result}")

if __name__ == "__main__":
    main()

