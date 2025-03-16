import sys

def swap(array, i, j):
    if i != j:
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

def is_sorted_list(lst):
    for i in range(1, len(lst)):
        if less(lst[i], lst[i - 1]):
            return False
    return True

# Main function to run the program
def main():
    n = int(input().strip())
    array = list(map(int, input().strip().split()))
    i, j = map(int, input().strip().split())
    swap(array, i, j)
    print_array(array)
    sorted = is_sorted(array)
    print(sorted)
    left, right = map(int, input().strip().split())
    flip(array, left, right)
    print_array(array)

if __name__ == "__main__":
    main()
