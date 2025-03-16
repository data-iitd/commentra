import sys
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
        pos = bisect_left(last_elements, x)
        if pos < len(piles):
            piles[pos].append(x)
            last_elements[pos] = x
        else:
            new_pile = []
            new_pile.append(x)
            piles.append(new_pile)
            last_elements.append(x)
    return piles

def merge_piles(piles):
    pq = []
    for pile in piles:
        heapq.heappush(pq, (pile.pop(), pile))
    return pq

def extract_piles(array, pq):
    index = 0
    while len(pq) > 0:
        node = heapq.heappop(pq)
        array[index] = node[0]
        if len(node[1]) > 0:
            heapq.heappush(pq, (node[1].pop(), node[1]))
        index += 1

def bisect_left(a, x, lo=0, hi=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo

def main():
    n = int(sys.stdin.readline())
    array = list(map(int, sys.stdin.readline().split()))
    patience_sort(array)
    for num in array:
        print(num, end=' ')

if __name__ == '__main__':
    main()

