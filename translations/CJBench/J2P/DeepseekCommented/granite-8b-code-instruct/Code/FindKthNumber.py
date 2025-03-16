
import random

def find_kth_max(array, k):
    if k <= 0 or k > len(array):
        raise ValueError("k must be between 1 and the size of the array")
    return quick_select(array, 0, len(array) - 1, len(array) - k)

def quick_select(array, left, right, k_smallest):
    if left == right:
        return array[left]
    pivot_index = left + random.randint(0, right - left)
    pivot_index = partition(array, left, right, pivot_index)
    if k_smallest == pivot_index:
        return array[k_smallest]
    elif k_smallest < pivot_index:
        return quick_select(array, left, pivot_index - 1, k_smallest)
    else:
        return quick_select(array, pivot_index + 1, right, k_smallest)

def partition(array, left, right, pivot_index):
    pivot_value = array[pivot_index]
    array[pivot_index], array[right] = array[right], array[pivot_index]
    store_index = left
    for i in range(left, right):
        if array[i] < pivot_value:
            array[i], array[store_index] = array[store_index], array[i]
            store_index += 1
    array[right], array[store_index] = array[store_index], array[right]
    return store_index

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    if n <= 0:
        print("Array size must be positive.")
        exit()
    array = [int(x) for x in input("Enter the elements of the array: ").split()]
    k = int(input("Enter the value of k: "))
    if k <= 0 or k > n:
        print("Error: k must be between 1 and the size of the array.")
        exit()
    result = find_kth_max(array, k)
    print(f"The {k}-th largest element is: {result}")

