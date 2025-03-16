import heapq

def main():
    # Read the number of elements in the array
    n = int(input())
    array = list(map(int, input().split()))
    
    # Perform patience sort on the array
    patience_sort(array)
    
    # Print the sorted array
    print(" ".join(map(str, array)))

# Method to perform patience sort on an array
def patience_sort(array):
    # Return the array as is if it is empty
    if len(array) == 0:
        return array
    
    # Form piles from the array elements
    piles = form_piles(array)
    
    # Merge the piles into a priority queue
    pq = merge_piles(piles)
    
    # Extract the sorted elements from the priority queue back into the array
    extract_piles(array, pq)

# Method to form piles based on the patience sorting algorithm
def form_piles(array):
    piles = []
    last_elements = []
    
    # Iterate through each element in the array
    for x in array:
        # Find the position to place the current element in the last_elements list
        pos = binary_search(last_elements, x)
        
        # If the position is within the current number of piles
        if pos < len(piles):
            # Add the element to the corresponding pile
            piles[pos].append(x)
            last_elements[pos] = x  # Update the last element of the pile
        else:
            # Create a new pile for the current element
            new_pile = [x]
            piles.append(new_pile)
            last_elements.append(x)  # Add the new last element
    
    return piles  # Return the formed piles

# Binary search to find the position for the current element
def binary_search(last_elements, x):
    low, high = 0, len(last_elements)
    while low < high:
        mid = (low + high) // 2
        if last_elements[mid] < x:
            low = mid + 1
        else:
            high = mid
    return low

# Method to merge the piles into a priority queue
def merge_piles(piles):
    pq = []
    
    # Add the top element of each pile to the priority queue
    for pile in piles:
        if pile:  # Ensure the pile is not empty
            heapq.heappush(pq, PileNode(pile.pop(), pile))
    
    return pq  # Return the priority queue containing the top elements of each pile

# Method to extract sorted elements from the priority queue back into the array
def extract_piles(array, pq):
    index = 0  # Index to track position in the output array
    
    # While there are elements in the priority queue
    while pq:
        node = heapq.heappop(pq)  # Get the smallest element
        array[index] = node.value  # Place it in the sorted array
        index += 1
        
        # If the current pile still has elements, add the next top element to the queue
        if node.pile:
            heapq.heappush(pq, PileNode(node.pile.pop(), node.pile))

# Class to represent a node in the priority queue, holding a value and a reference to its pile
class PileNode:
    def __init__(self, value, pile):
        self.value = value  # The value of the node
        self.pile = pile  # The remaining pile associated with this node
    
    # Compare this node with another based on the value
    def __lt__(self, other):
        return self.value < other.value

if __name__ == "__main__":
    main()

# <END-OF-CODE>
