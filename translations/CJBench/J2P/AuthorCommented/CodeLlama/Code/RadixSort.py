
def radix_sort(array):
    if len(array) == 0:
        return array

    max_value = max(array)
    for exp in range(1, int(max_value / 10) + 1):
        counting_sort_by_digit(array, exp)

    return array


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


def check_for_negative_input(array):
    for number in array:
        if number < 0:
            raise ValueError("Array contains negative integers.")


def main():
    array = [170, 45, 75, 90, 802, 24, 2, 66]
    check_for_negative_input(array)
    radix_sort(array)
    print(array)


if __name__ == "__main__":
    main()

