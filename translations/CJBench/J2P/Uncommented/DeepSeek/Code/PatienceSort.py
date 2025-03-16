def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    array = [int(x) for x in data[1:n+1]]
    patience_sort(array)
    print(" ".join(map(str, array)))

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

def binary_search(arr, x):
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] <= x:
            left = mid + 1
        else:
            right = mid
    return left

def merge_piles(piles):
    import heapq
    pq = []
    for pile in piles:
        if pile:
            heapq.heappush(pq, PileNode(pile.pop(), pile))
    return pq

def extract_piles(array, pq):
    index = 0
    while pq:
        node = heapq.heappop(pq)
        array[index] = node.value
        index += 1
        if node.pile:
            heapq.heappush(pq, PileNode(node.pile.pop(), node.pile))

class PileNode:
    def __init__(self, value, pile):
        self.value = value
        self.pile = pile

    def __lt__(self, other):
        return self.value < other.value

if __name__ == "__main__":
    main()
