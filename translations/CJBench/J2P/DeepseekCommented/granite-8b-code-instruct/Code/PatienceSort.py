
import heapq

def patience_sort(array):
    if len(array) == 0:
        return array
    piles = form_piles(array)
    pq = merge_piles(piles)
    extract_piles(array, pq)
    return array

def form_piles(array):
    piles = []
    last_elements = []
    for x in array:
        pos = binary_search(last_elements, x)
        if pos < 0:
            pos = -pos - 1
        if pos < len(piles):
            piles[pos].append(x)
            last_elements[pos] = x
        else:
            new_pile = [x]
            piles.append(new_pile)
            last_elements.append(x)
    return piles

def merge_piles(piles):
    pq = []
    for pile in piles:
        heapq.heappush(pq, (pile[-1], pile))
    return pq

def extract_piles(array, pq):
    index = 0
    while len(pq) > 0:
        node = heapq.heappop(pq)
        array[index] = node[0]
        index += 1
        if len(node[1]) > 0:
            heapq.heappush(pq, (node[1][-1], node[1]))

def binary_search(array, target):
    left = 0
    right = len(array) - 1
    while left <= right:
        mid = (left + right) // 2
        if array[mid] < target:
            left = mid + 1
        elif array[mid] > target:
            right = mid - 1
        else:
            return mid
    return -left - 1

# Call the patience_sort function with an array of integers
array = [5, 2, 8, 1, 9, 3, 7, 4, 6]
patience_sort(array)
print(array) # Print the sorted array

