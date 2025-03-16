
import sys

def swap(array, i, j):
    if i!= j:
        array[i], array[j] = array[j], array[i]

def less(first_element, second_element):
    return first_element < second_element

def greater(first_element, second_element):
    return first_element > second_element

def greater_or_equal(first_element, second_element):
    return first_element >= second_element

def print_list(list_to_print):
    print(" ".join(map(str, list_to_print)))

def print_array(array):
    print(array)

def flip(array, left, right):
    while left <= right:
        swap(array, left, right)
        left += 1
        right -= 1

def is_sorted(array):
    for i in range(1, len(array)):
        if less(array[i], array[i - 1]):
            return False
    return True

def is_sorted_list(list):
    for i in range(1, len(list)):
        if less(list[i], list[i - 1]):
            return False
    return True

if __name__ == "__main__":
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    array = data[1:n + 1]
    i = data[n + 1]
    j = data[n + 2]
    swap(array, i, j)
    print_array(array)
    sorted_array = sorted(array)
    print(sorted_array == array)
    left = data[n + 3]
    right = data[n + 4]
    flip(array, left, right)
    print_array(array)
    print(is_sorted(array))
    print(is_sorted_list(array))

