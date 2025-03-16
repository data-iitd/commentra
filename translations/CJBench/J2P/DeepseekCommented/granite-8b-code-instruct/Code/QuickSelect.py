
import random

def select(list, n):
    # Ensure the list is not null
    if list is None:
        raise ValueError("The list of elements must not be null.")
    
    # Check if the list is empty
    if len(list) == 0:
        raise ValueError("The list of elements must not be empty.")
    
    # Check if the index is within the valid range
    if n < 0 or n >= len(list):
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    
    # Find the index of the n-th smallest element
    index = select_index(list, n)
    
    # Return the n-th smallest element
    return list[index]

def select_index(list, n):
    return select_index_helper(list, 0, len(list) - 1, n)

def select_index_helper(list, left, right, n):
    while True:
        if left == right:
            return left
        pivot_index = pivot(list, left, right)
        pivot_index = partition(list, left, right, pivot_index, n)
        if n == pivot_index:
            return n
        elif n < pivot_index:
            right = pivot_index - 1
        else:
            left = pivot_index + 1

def partition(list, left, right, pivot_index, n):
    pivot_value = list[pivot_index]
    list[pivot_index], list[right] = list[right], list[pivot_index]
    store_index = left
    for i in range(left, right):
        if list[i] < pivot_value:
            list[i], list[store_index] = list[store_index], list[i]
            store_index += 1
    store_index_eq = store_index
    for i in range(store_index, right):
        if list[i] == pivot_value:
            list[i], list[store_index_eq] = list[store_index_eq], list[i]
            store_index_eq += 1
    list[right], list[store_index_eq] = list[store_index_eq], list[right]
    return min(n, store_index)

def pivot(list, left, right):
    if right - left < 5:
        return partition_5(list, left, right)
    for i in range(left, right, 5):
        sub_right = min(i + 4, right)
        median_5 = partition_5(list, i, sub_right)
        list[median_5], list[left + (i - left) // 5] = list[left + (i - left) // 5], list[median_5]
    mid = left + (right - left) // 10 + 1
    right_index = left + (right - left) // 5
    return select_index_helper(list, left, right_index, mid)

def partition_5(list, left, right):
    sublist = list[left:right + 1]
    sublist.sort()
    return left + (right - left) // 2

# Main method to read input, call the select method, and print the result
if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    list = [int(x) for x in input("Enter the elements separated by spaces: ").split()]
    index = int(input("Enter the index of the n-th smallest element: "))
    try:
        result = select(list, index)
        print(f"The {index}-th smallest element is: {result}")
    except Exception as e:
        print(e)