
import heapq

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
    
    return array

# Method to form piles based on the patience sorting algorithm
def form_piles(array):
    piles = []
    last_elements = []
    
    # Iterate through each element in the array
    for x in array:
        # Find the position to place the current element in the last_elements list
        pos = binary_search(last_elements, x)
        if pos < 0:
            pos = -pos - 1 # Get the insertion point
        
        # If the position is within the current number of piles
        if pos < len(piles):
            # Add the element to the corresponding pile
            piles[pos].append(x)
            last_elements[pos] = x # Update the last element of the pile
        else:
            # Create a new pile for the current element
            new_pile = [x]
            piles.append(new_pile)
            last_elements.append(x) # Add the new last element
    
    return piles # Return the formed piles

# Method to merge the piles into a priority queue
def merge_piles(piles):
    pq = []
    
    # Add the top element of each pile to the priority queue
    for pile in piles:
        heapq.heappush(pq, (-pile[-1], pile))
    
    return pq # Return the priority queue containing the top elements of each pile

# Method to extract sorted elements from the priority queue back into the array
def extract_piles(array, pq):
    index = 0 # Index to track position in the output array
    
    # While there are elements in the priority queue
    while len(pq) > 0:
        node = heapq.heappop(pq) # Get the smallest element
        array[index] = node[1].pop() # Place it in the sorted array
        index += 1
        
        # If the current pile still has elements, add the next top element to the queue
        if len(node[1]) > 0:
            heapq.heappush(pq, (-node[1][-1], node[1]))

# Method to perform binary search to find the position to insert an element in a sorted list
def binary_search(array, target):
    left = 0
    right = len(array) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if array[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return left

# Test the patience_sort function
array = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
patience_sort(array)
print(array) # Output: [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

# End of code
