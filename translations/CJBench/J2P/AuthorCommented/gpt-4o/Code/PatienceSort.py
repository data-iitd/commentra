import heapq

class PileNode:
    def __init__(self, value, pile):
        self.value = value
        self.pile = pile

    def __lt__(self, other):
        return self.value < other.value

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
        if pos < len(piles):
            piles[pos].append(x)
            last_elements[pos] = x
        else:
            new_pile = [x]
            piles.append(new_pile)
            last_elements.append(x)

    return piles

def binary_search(last_elements, x):
    low, high = 0, len(last_elements)
    while low < high:
        mid = (low + high) // 2
        if last_elements[mid] < x:
            low = mid + 1
        else:
            high = mid
    return low

def merge_piles(piles):
    pq = []
    for pile in piles:
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

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    array = list(map(int, input("Enter the array elements: ").split()))

    sorted_array = patience_sort(array)

    print("Sorted array:", ' '.join(map(str, sorted_array)))

# <END-OF-CODE>
