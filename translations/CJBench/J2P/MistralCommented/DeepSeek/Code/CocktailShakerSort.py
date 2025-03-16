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
            array[i], array[i + 1] = array[i + 1], array[i]
            last_swapped_index = i

    return last_swapped_index

def perform_backward_pass(array, left, right):
    last_swapped_index = right

    for i in range(right, left, -1):
        if array[i] < array[i - 1]:
            array[i], array[i - 1] = array[i - 1], array[i]
            last_swapped_index = i

    return last_swapped_index

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    array = list(map(int, data[1:n+1]))

    sort(array)

    for num in array:
        print(num, end=" ")
