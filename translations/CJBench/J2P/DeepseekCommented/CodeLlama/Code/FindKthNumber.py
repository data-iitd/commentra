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
            array[store_index], array[i] = array[i], array[store_index]
            store_index += 1
    array[right], array[store_index] = array[store_index], array[right]
    return store_index

# This is the entry point of the program.
if __name__ == "__main__":
    try:
        n = int(input("Enter the size of the array: "))
        if n <= 0:
            raise ValueError("Array size must be positive.")
        array = [int(input("Enter the elements of the array: ")) for _ in range(n)]
        k = int(input("Enter the value of k: "))
        if k <= 0 or k > n:
            raise ValueError("Error: k must be between 1 and the size of the array.")
        result = find_kth_max(array, k)
        print("The " + str(k) + "-th largest element is: " + str(result))
    except Exception as e:
        print("An error occurred: " + str(e))
    finally:
        print("