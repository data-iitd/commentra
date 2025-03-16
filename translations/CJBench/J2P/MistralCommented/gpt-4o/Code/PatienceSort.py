import sys
import bisect
from queue import PriorityQueue

def main():
    # Read the number of elements in the array from the standard input
    n = int(sys.stdin.readline().strip())

    # Read each element of the array from the standard input and store it in a list
    array = list(map(int, sys.stdin.readline().strip().split()))

    # Call the patience_sort function to sort the array
    patience_sort(array)

    # Print each element of the sorted array to the standard output
    print(" ".join(map(str, array)))

def patience_sort(array):
    # Base case: if the array is empty, return it as is
    if len(array) == 0:
        return array

    # Form piles of elements
    piles = form_piles(array)

    # Merge the piles using a PriorityQueue
    pq = merge_piles(piles)

    # Extract the sorted elements from the PriorityQueue and store them back in the array
    extract_piles(array, pq)

    return array

def form_piles(array):
    piles = []
    last_elements = []

    # Iterate through each element in the array
    for x in array:
        # Determine the position where the current element should be placed
        pos = bisect.bisect_left(last_elements, x)

        # If the current position is within the bounds of the piles list
        if pos < len(piles):
            piles[pos].append(x)
            last_elements[pos] = x
        else:
            # Otherwise, create a new pile
            new_pile = [x]
            piles.append(new_pile)
            last_elements.append(x)

    return piles

def merge_piles(piles):
    pq = PriorityQueue()

    # Iterate through each pile in the piles list
    for pile in piles:
        # Create a new PileNode with the last element of the current pile
        pq.put(PileNode(pile.pop(), pile))

    return pq

def extract_piles(array, pq):
    index = 0

    # Iterate through each PileNode in the PriorityQueue until it is empty
    while not pq.empty():
        # Dequeue the current PileNode from the PriorityQueue
        node = pq.get()

        # Store the value of the current PileNode in the corresponding index of the array
        array[index] = node.value
        index += 1

        # If the pile of the current PileNode is not empty, add its last element to the PriorityQueue
        if node.pile:
            pq.put(PileNode(node.pile.pop(), node.pile))

class PileNode:
    def __init__(self, value, pile):
        self.value = value
        self.pile = pile

    def __lt__(self, other):
        return self.value < other.value

if __name__ == "__main__":
    main()

# <END-OF-CODE>
