def sort(array):
    length = len(array)
    for cycleStart in range(length - 1):
        item = array[cycleStart]
        pos = find_position(array, cycleStart, item)
        if pos == cycleStart:
            continue
        item = place_item(array, item, pos)
        while pos != cycleStart:
            pos = find_position(array, cycleStart, item)
            item = place_item(array, item, pos)
    return array

def find_position(array, cycleStart, item):
    pos = cycleStart
    for i in range(cycleStart + 1, len(array)):
        if array[i] < item:
            pos += 1
    return pos

def place_item(array, item, pos):
    temp = array[pos]
    array[pos] = item
    return temp

def replace(array, pos, item):
    temp = array[pos]
    array[pos] = item
    return temp

# Main function to read input and print output
def main():
    n = int(input())
    array = list(map(int, input().split()))
    sorted_array = sort(array)
    print(" ".join(map(str, sorted_array)))

# Call the main function
main()

