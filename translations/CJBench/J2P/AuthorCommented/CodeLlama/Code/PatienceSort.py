
import sys

# Input: size of the array
n = int(sys.stdin.readline())
array = list(map(int, sys.stdin.readline().split()))

# Sort the array using Patience Sort
patienceSort(array)

# Output: sorted array
for num in array:
    print(num, end=" ")

def patienceSort(array):
    if len(array) == 0:
        return array

    piles = formPiles(array)
    pq = mergePiles(piles)
    extractPiles(array, pq)

    return array

def formPiles(array):
    piles = []
    lastElements = []

    for x in array:
        pos = bisect(lastElements, x)
        if pos < len(piles):
            piles[pos].append(x)
            lastElements[pos] = x
        else:
            newPile = []
            newPile.append(x)
            piles.append(newPile)
            lastElements.append(x)

    return piles

def mergePiles(piles):
    pq = []
    for pile in piles:
        pq.append(PileNode(pile.pop(), pile))

    return pq

def extractPiles(array, pq):
    index = 0
    while len(pq) > 0:
        node = heapq.heappop(pq)
        array[index] = node.value
        if len(node.pile) > 0:
            heapq.heappush(pq, PileNode(node.pile.pop(), node.pile))
        index += 1

class PileNode:
    def __init__(self, value, pile):
        self.value = value
        self.pile = pile

    def __lt__(self, other):
        return self.value < other.value

import heapq

def bisect(a, x, lo=0, hi=None):
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo

