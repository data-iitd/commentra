import sys

n = int(input())
array = list(map(int, input().split()))

def sort(array):
    for cycleStart in range(len(array)):
        item = array[cycleStart]
        pos = findPosition(array, cycleStart, item)
        if pos == cycleStart:
            continue
        item = placeItem(array, item, pos)
        while pos != cycleStart:
            pos = findPosition(array, cycleStart, item)
            item = placeItem(array, item, pos)
    return array

def findPosition(array, cycleStart, item):
    pos = cycleStart
    for i in range(cycleStart + 1, len(array)):
        if array[i] < item:
            pos += 1
    return pos

def placeItem(array, item, pos):
    while item == array[pos]:
        pos += 1
    return replace(array, pos, item)

def replace(array, pos, item):
    replacedItem = array[pos]
    array[pos] = item
    return replacedItem

print(*sort(array), sep=' ')

