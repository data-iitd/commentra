def sort(array):
    length = len(array)
    for cycle_start in range(length - 1):
        item = array[cycle_start]
        pos = find_position(array, cycle_start, item)  # Find the correct position for the item
        if pos == cycle_start:
            continue  # If the item is already in place, move to the next item
        item = place_item(array, item, pos)  # Place the item at its correct position
        while pos != cycle_start:
            pos = find_position(array, cycle_start, item)  # Recalculate the position if necessary
            item = place_item(array, item, pos)  # Place the item at its correct position
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
    return replace(array, pos, item)  # Replace the item at the correct position


def replace(array, pos, item):
    replaced_item = array[pos]
    array[pos] = item
    return replaced_item


# Main function to read input, sort the array, and print the sorted array
def main():
    n = int(input())  # Read the number of elements in the array
    array = list(map(int, input().split()))  # Read the elements of the array
    sorted_array = sort(array)  # Sort the array using the sort method
    print(" ".join(map(str, sorted_array)))  # Print the sorted array


main()
