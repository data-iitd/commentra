
import heapq

def patience_sort(array):
    piles = form_piles(array)
    pq = merge_piles(piles)
    extract_piles(array, pq)

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
        heapq.heappush(pq, (pile[0], pile))
    return pq

def extract_piles(array, pq):
    index = 0
    while pq:
        value, pile = heapq.heappop(pq)
        array[index] = value
        if pile:
            heapq.heappush(pq, (pile.pop(), pile))
        index += 1

def binary_search(array, x):
    left, right = 0, len(array) - 1
    while left <= right:
        mid = (left + right) // 2
        if array[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return left

# Input: size of the array
n = int(input())
array = [int(x) for x in input().split()]

# Sort the array using Patience Sort
patience_sort(array)

# Output: sorted array
print(" ".join(map(str, array)))

# 