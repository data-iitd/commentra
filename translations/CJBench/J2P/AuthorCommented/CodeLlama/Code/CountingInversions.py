

import sys


def count_inversions(arr):
    if len(arr) <= 1:
        return 0

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    left_inversions = count_inversions(left)
    right_inversions = count_inversions(right)
    cross_inversions = merge_and_count(left, right)

    return left_inversions + right_inversions + cross_inversions


def merge_and_count(left, right):
    left_arr = left
    right_arr = right

    left_index = 0
    right_index = 0
    inversions = 0

    while left_index < len(left_arr) and right_index < len(right_arr):
        if left_arr[left_index] <= right_arr[right_index]:
            left_index += 1
        else:
            inversions += len(left_arr) - left_index
            right_index += 1

    return inversions


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))

    result = count_inversions(arr)
    print("Number of inversions:", result)

