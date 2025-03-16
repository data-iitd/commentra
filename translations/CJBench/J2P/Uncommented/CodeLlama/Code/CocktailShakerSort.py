import sys

n = int(sys.stdin.readline())
array = list(map(int, sys.stdin.readline().split()))

def sort(array):
    if len(array) == 0:
        return
    left = 0
    right = len(array) - 1
    while left < right:
        right = forward_pass(array, left, right)
        left = backward_pass(array, left, right)

def forward_pass(array, left, right):
    last_swapped_index = left
    for i in range(left, right):
        if array[i] > array[i + 1]:
            array[i], array[i + 1] = array[i + 1], array[i]
            last_swapped_index = i
    return last_swapped_index

def backward_pass(array, left, right):
    last_swapped_index = right
    for i in range(right, left, -1):
        if array[i] < array[i - 1]:
            array[i - 1], array[i] = array[i], array[i - 1]
            last_swapped_index = i
    return last_swapped_index

sort(array)
for num in array:
    print(num, end=' ')

# 