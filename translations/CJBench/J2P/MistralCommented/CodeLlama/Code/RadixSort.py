
import sys

def main():
    n = int(sys.stdin.readline().strip())
    array = list(map(int, sys.stdin.readline().strip().split()))
    sort(array)
    print(*array, sep=' ')

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
    max_value = max(array)
    for exp in range(1, int(max_value / 10) + 1):
        counting_sort_by_digit(array, exp)

def counting_sort_by_digit(array, exp):
    count = [0] * 10
    output = [0] * len(array)

    for i in range(len(array)):
        count[(array[i] // exp) % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(len(array) - 1, -1, -1):
        digit = (array[i] // exp) % 10
        output[count[digit] - 1] = array[i]
        count[digit] -= 1

    array[:] = output

if __name__ == "__main__":
    main()

