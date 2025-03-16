
import sys

n = int(input())
array = list(map(int, input().split()))
i, j = map(int, input().split())
swap(array, i, j)
print(*array)
sorted = is_sorted(array)
print(sorted)
left, right = map(int, input().split())
flip(array, left, right)
print(*array)

def swap(array, i, j):
    if i != j:
        array[i], array[j] = array[j], array[i]

def is_sorted(array):
    for i in range(1, len(array)):
        if array[i] < array[i - 1]:
            return False
    return True

def flip(array, left, right):
    while left <= right:
        array[left], array[right] = array[right], array[left]
        left += 1
        right -= 1

