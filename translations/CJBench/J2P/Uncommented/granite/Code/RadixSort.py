
import sys

BASE = 10

def sort(array):
    if len(array) == 0:
        return array
    check_for_negative_input(array)
    radix_sort(array)
    return array

def check_for_negative_input(array):
    for number in array:
        if number < 0:
            raise ValueError("Array contains negative integers.")

def radix_sort(array):
    max_ = max(array)
    for exp in range(1, max_ // BASE + 1):
        counting_sort_by_digit(array, exp)

def counting_sort_by_digit(array, exp):
    count = [0] * BASE
    output = [0] * len(array)
    for i in range(len(array)):
        digit = (array[i] // exp) % BASE
        count[digit] += 1
    for i in range(1, BASE):
        count[i] += count[i - 1]
    for i in range(len(array) - 1, -1, -1):
        digit = (array[i] // exp) % BASE
        output[count[digit] - 1] = array[i]
        count[digit] -= 1
    array[:] = output

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    print(" ".join(map(str, sort(array))))

