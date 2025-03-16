def sort(array):
    if len(array) == 0:
        return array
    check_for_negative_input(array)
    radix_sort(array)
    return array

def check_for_negative_input(array):
    if any(x < 0 for x in array):
        raise ValueError("Array contains negative integers.")

def radix_sort(array):
    max_val = max(array)
    exp = 1
    while max_val // exp > 0:
        counting_sort_by_digit(array, exp)
        exp *= 10

def counting_sort_by_digit(array, exp):
    n = len(array)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        digit = (array[i] // exp) % 10
        count[digit] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        digit = (array[i] // exp) % 10
        output[count[digit] - 1] = array[i]
        count[digit] -= 1
        i -= 1

    for i in range(n):
        array[i] = output[i]

# Main function to read input and print output
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    array = [int(x) for x in data[1:n+1]]
    sorted_array = sort(array)
    print(" ".join(map(str, sorted_array)))

if __name__ == "__main__":
    main()
