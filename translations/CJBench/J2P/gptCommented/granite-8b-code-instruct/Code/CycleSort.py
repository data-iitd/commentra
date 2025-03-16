
import sys

def sort(array):
    length = len(array)
    
    for cycleStart in range(length - 1):
        item = array[cycleStart]
        pos = find_position(array, cycleStart, item)
        
        if pos == cycleStart:
            continue
        
        item = place_item(array, item, pos)
        
        while pos!= cycleStart:
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
    while item == array[pos]:
        pos += 1
    
    return replace(array, pos, item)

def replace(array, pos, item):
    replacedItem = array[pos]
    array[pos] = item
    return replacedItem

if __name__ == "__main__":
    n = int(input())
    array = [int(x) for x in input().split()]
    sorted_array = sort(array)
    print(" ".join(map(str, sorted_array)))

