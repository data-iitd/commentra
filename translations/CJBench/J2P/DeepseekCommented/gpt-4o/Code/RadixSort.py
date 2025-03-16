import sys

BASE = 10

def sort(array):
    if len(array) == 0:
        return array
    check_for_negative_input(array)
    radix_sort(array)
    return array

def check_for_negative_input(array):
    if any(num < 0 for num in array):
        raise ValueError("Array contains negative integers.")

def radix_sort(array):
    max_val = max(array)
    exp = 1
    while max_val // exp > 0:
        counting_sort_by_digit(array, exp)
        exp *= BASE

def counting_sort_by_digit(array, exp):
    n = len(array)
    output = [0] * n
    count = [0] * BASE

    for i in range(n):
        index = array[i] // exp
        count[index % BASE] += 1

    for i in range(1, BASE):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = array[i] // exp
        output[count[index % BASE] - 1] = array[i]
        count[index % BASE] -= 1
        i -= 1

    for i in range(n):
        array[i] = output[i]

# Main function to read input and print output
def main():
    n = int(input().strip())
    array = list(map(int, input().strip().split()))
    sorted_array = sort(array)
    print(" ".join(map(str, sorted_array)))

if __name__ == "__main__":
    main()
