

import heapq

def patience_sort(array):
    # Base case: if the array is empty, return it as is
    if len(array) == 0:
        return array

    # Form piles of elements using the Merge-Sort algorithm with patience
    piles = form_piles(array)

    # Merge the piles using a PriorityQueue
    pq = merge_piles(piles)

    # Extract the sorted elements from the PriorityQueue and store them back in the array
    extract_piles(array, pq)

    # Return the sorted array as a result
    return array

def form_piles(array):
    # Initialize a list of lists to store the piles
    piles = []

    # Initialize a list to store the last elements of the piles
    last_elements = []

    # Iterate through each element in the array
    for x in array:
        # Determine the position where the current element should be placed in the last_elements list
        pos = binary_search(last_elements, x)

        # If the current element is smaller than the last element in the last_elements list,
        # it should be placed before that element in the corresponding pile
        if pos < 0:
            pos = -pos - 1

        # If the current position is within the bounds of the piles list,
        # add the current element to the corresponding pile and update the last_elements list
        if pos < len(piles):
            piles[pos].append(x)
            last_elements[pos] = x
        else:
            # Otherwise, create a new pile and add the current element to it
            new_pile = [x]
            piles.append(new_pile)
            last_elements.append(x)

    # Return the piles list as a result
    return piles

def merge_piles(piles):
    # Initialize a PriorityQueue of PileNodes
    pq = []

    # Iterate through each pile in the piles list
    for pile in piles:
        # Create a new PileNode with the last element of the current pile and the pile itself
        # Add the new PileNode to the PriorityQueue
        heapq.heappush(pq, PileNode(pile.pop(), pile))

    # Return the PriorityQueue of PileNodes as a result
    return pq

def extract_piles(array, pq):
    # Initialize an index to store the current index in the array
    index = 0

    # Iterate through each PileNode in the PriorityQueue until it is empty
    while len(pq) > 0:
        # Dequeue the current PileNode from the PriorityQueue
        node = heapq.heappop(pq)

        # Store the value of the current PileNode (the last element of the corresponding pile)
        # in the corresponding index of the array
        array[index] = node.value
        index += 1

        # If the pile of the current PileNode is not empty, add its last element to the PriorityQueue
        if len(node.pile) > 0:
            # Create a new PileNode with the last element of the updated pile and the pile itself
            # Add the new PileNode to the PriorityQueue
            heapq.heappush(pq, PileNode(node.pile.pop(), node.pile))

# A custom class representing a pile of elements and a PileNode in the PriorityQueue
class PileNode:
    # Initialize a new PileNode with the given value and pile
    def __init__(self, value, pile):
        self.value = value
        self.pile = pile

    # Implement the __lt__ method to compare two PileNodes based on their values
    def __lt__(self, other):
        return self.value < other.value

# Translate the above Python code to C++ and end with comment "