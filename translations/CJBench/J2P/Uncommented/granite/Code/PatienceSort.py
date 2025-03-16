
import heapq
def patience_sort(array):
    if len(array) == 0:
        return array
    piles = form_piles(array)
    pq = merge_piles(piles)
    extract_piles(array, pq)
    return array
def form_piles(array):
    last_elements = []
    piles = []
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
        heapq.heappush(pq, (pile[0], 0, pile))
    return pq
def extract_piles(array, pq):
    index = 0
    while len(pq) > 0:
        value, _, pile = heapq.heappop(pq)
        array[index] = value
        index += 1
        if len(pile) > 0:
            heapq.heappush(pq, (pile.pop(), 0, pile))
def binary_search(array, x):
    left, right = 0, len(array) - 1
    while left <= right:
        mid = (left + right) // 2
        if array[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return left
# 