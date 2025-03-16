import heapq
import sys

def main():
    # Read the number of elements in the array
    n = int(input().strip())
    array = list(map(int, input().strip().split()))
    
    # Perform patience sort on the array
    patience_sort(array)
    
    # Print the sorted array
    print(" ".join(map(str, array)))

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

def form_piles(array):
    piles = []
    last_elements = []
    
    # Iterate through each element in the array
    for x in array:
        # Find the position to place the current element in the last_elements list
        pos = binary_search(last_elements, x)
        if pos < 0:
            pos = -pos - 1  # Get the insertion point
        
        # If the position is within the current number of piles
        if pos < len(piles):
            # Add the element to the corresponding pile
            piles[pos].append(x)
            last_elements[pos] = x  # Update the last element of the pile
        else:
            # Create a new pile for the current element
            piles.append([x])
            last_elements.append(x)  # Add the new last element
    return piles  # Return the formed piles

def binary_search(arr, x):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return -left - 1

def merge_piles(piles):
    pq = []
    
    # Add the top element of each pile to the priority queue
    for pile in piles:
        if pile:
            heapq.heappush(pq, (-pile[-1], pile))
    return pq  # Return the priority queue containing the top elements of each pile

def extract_piles(array, pq):
    index = 0  # Index to track position in the output array
    
    # While there are elements in the priority queue
    while pq:
        value, pile = heapq.heappop(pq)  # Get the smallest element
        array[index] = -value  # Place it in the sorted array
        index += 1
        
        # If the current pile still has elements, add the next top element to the queue
        if pile:
            heapq.heappush(pq, (-pile.pop(), pile))

if __name__ == "__main__":
    main()
