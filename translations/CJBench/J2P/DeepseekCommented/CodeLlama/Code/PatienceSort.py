
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
        pos = bisect_left(last_elements, x)
        if pos < len(last_elements):
            piles[pos].append(x)
            last_elements[pos] = x
        else:
            piles.append([x])
            last_elements.append(x)
    return piles

def merge_piles(piles):
    pq = []
    for pile in piles:
        pq.append(PileNode(pile.pop(), pile))
    heapify(pq)
    return pq

def extract_piles(array, pq):
    index = 0
    while len(pq) > 0:
        node = heappop(pq)
        array[index] = node.value
        index += 1
        if len(node.pile) > 0:
            heappush(pq, PileNode(node.pile.pop(), node.pile))

class PileNode:
    def __init__(self, value, pile):
        self.value = value
        self.pile = pile

    def __lt__(self, other):
        return self.value < other.value

def main():
    n = int(sys.stdin.readline())
    array = [int(x) for x in sys.stdin.readline().split()]
    patience_sort(array)
    print(" ".join(str(x) for x in array))

if __name__ == "__main__":
    main()

