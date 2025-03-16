import heapq
import sys

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
            pile = [x]
            piles.append(pile)
            last_elements.append(x)
    return piles

def binary_search(lst, x):
    left, right = 0, len(lst)
    while left < right:
        mid = (left + right) // 2
        if lst[mid] <= x:
            left = mid + 1
        else:
            right = mid
    return left

def merge_piles(piles):
    pq = []
    for pile in piles:
        if pile:
            heapq.heappush(pq, (-pile[-1], pile))
    return pq

def extract_piles(array, pq):
    index = 0
    while pq:
        _, pile = heapq.heappop(pq)
        array[index] = pile.pop(0)
        index += 1
        if pile:
            heapq.heappush(pq, (-pile[0], pile))

if __name__ == "__main__":
    n = int(input().strip())
    array = list(map(int, sys.stdin.readline().strip().split()))
    sorted_array = patience_sort(array)
    print(" ".join(map(str, sorted_array)))
