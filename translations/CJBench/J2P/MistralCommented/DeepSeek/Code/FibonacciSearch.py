def find(array, key):
    if len(array) == 0:
        raise ValueError("Input array must not be empty.")

    if not is_sorted(array):
        raise ValueError("Input array must be sorted.")

    if key is None:
        raise ValueError("Key must not be None.")

    fib_minus_1, fib_minus_2 = 1, 0
    fib_number = fib_minus_1 + fib_minus_2

    n = len(array)

    while fib_number < n:
        fib_minus_2 = fib_minus_1
        fib_minus_1 = fib_number
        fib_number = fib_minus_1 + fib_minus_2

    offset = -1

    while fib_number > 1:
        i = min(offset + fib_minus_2, n - 1)

        if array[i] < key:
            fib_number = fib_minus_1
            fib_minus_1 = fib_minus_2
            fib_minus_2 = fib_number - fib_minus_1
            offset = i
        elif array[i] > key:
            fib_number = fib_minus_2
            fib_minus_1 = fib_minus_1 - fib_minus_2
            fib_minus_2 = fib_number - fib_minus_1
        else:
            return i

    if fib_minus_1 == 1 and offset + 1 < n and array[offset + 1] == key:
        return offset + 1

    return -1


def is_sorted(array):
    for i in range(1, len(array)):
        if array[i - 1] > array[i]:
            return False
    return True


if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    array = list(map(int, data[1:n + 1]))
    key = int(data[n + 1])

    index = find(array, key)
    print(index)
