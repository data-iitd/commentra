
import sys

def sort(array):
    if len(array) == 0:
        return
    left = 0
    right = len(array) - 1
    while left < right:
        right = perform_forward_pass(array, left, right)
        left = perform_backward_pass(array, left, right)

def perform_forward_pass(array, left, right):
    last_swapped_index = left
    for i in range(left, right):
        if array[i] > array[i + 1]:
            swap(array, i, i + 1)
            last_swapped_index = i
    return last_swapped_index

def perform_backward_pass(array, left, right):
    last_swapped_index = right
    for i in range(right, left, -1):
        if array[i] < array[i - 1]:
            swap(array, i - 1, i)
            last_swapped_index = i
    return last_swapped_index

def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

if __name__ == "__main__":
    n = int(input())
    array = [int(x) for x in input().split()]
    sort(array)
    print(" ".join(map(str, array)))

