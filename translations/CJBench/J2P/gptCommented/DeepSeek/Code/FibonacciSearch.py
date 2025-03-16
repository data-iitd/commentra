def is_sorted(arr):
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

def find(arr, key):
    if len(arr) == 0:
        raise ValueError("Input array must not be empty.")
    if not is_sorted(arr):
        raise ValueError("Input array must be sorted.")
    if key is None:
        raise ValueError("Key must not be None.")

    fib_minus_1, fib_minus_2 = 1, 0
    fib_number = fib_minus_1 + fib_minus_2
    n = len(arr)

    while fib_number < n:
        fib_minus_2 = fib_minus_1
        fib_minus_1 = fib_number
        fib_number = fib_minus_1 + fib_minus_2

    offset = -1

    while fib_number > 1:
        i = min(offset + fib_minus_2, n - 1)
        if arr[i] < key:
            fib_number, fib_minus_1 = fib_minus_1, fib_minus_2
            fib_minus_2 = fib_number - fib_minus_1
            offset = i
        elif arr[i] > key:
            fib_number, fib_minus_1 = fib_minus_2, fib_minus_1 - fib_minus_2
            fib_minus_2 = fib_number - fib_minus_1
        else:
            return i

    if fib_minus_1 == 1 and offset + 1 < n and arr[offset + 1] == key:
        return offset + 1

    return -1

# Main function to read input and call the find method
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    array = list(map(int, data[1:n+1]))
    key = int(data[n+1])
    
    try:
        index = find(array, key)
        print(index)
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
