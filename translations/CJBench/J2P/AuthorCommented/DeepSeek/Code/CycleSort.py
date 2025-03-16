def cycle_sort(array):
    length = len(array)
    for cycle_start in range(length - 1):
        item = array[cycle_start]
        pos = find_position(array, cycle_start, item)

        if pos == cycle_start:
            continue  # Item is already in the correct position

        item = place_item(array, item, pos)

        # Rotate the rest of the cycle
        while pos != cycle_start:
            pos = find_position(array, cycle_start, item)
            item = place_item(array, item, pos)

    return array


def find_position(array, cycle_start, item):
    pos = cycle_start
    for i in range(cycle_start + 1, len(array)):
        if array[i] < item:
            pos += 1
    return pos


def place_item(array, item, pos):
    while item == array[pos]:
        pos += 1
    array[pos], item = item, array[pos]
    return item


# Example usage:
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    array = list(map(int, data[1:n+1]))

    sorted_array = cycle_sort(array)

    for num in sorted_array:
        print(num, end=" ")
