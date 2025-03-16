import sys

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

def form_piles(array):
    piles = []
    last_elements = []
    
    # Iterate through each element in the array
    for x in array:
        # Find the position to place the current element in the last_elements list
        pos = last_elements.index(x) if x in last_elements else len(last_elements)
        
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

def merge_piles(piles):
    pq = []
    
    # Add the top element of each pile to the priority queue
    for pile in piles:
        pq.append((pile.pop(), pile))
    
    return pq # Return the priority queue containing the top elements of each pile

def extract_piles(array, pq):
    index = 0 # Index to track position in the output array
    
    # While there are elements in the priority queue
    while len(pq) > 0:
        node = pq.pop(0) # Get the smallest element
        array[index] = node[0] # Place it in the sorted array
        index += 1
        
        # If the current pile still has elements, add the next top element to the queue
        if len(node[1]) > 0:
            pq.append((node[1].pop(), node[1]))

def main():
    # Create a scanner to read input from the console
    scanner = sys.stdin
    
    # Read the number of elements in the array
    n = int(scanner.readline())
    array = []
    
    # Read the elements of the array from the input
    for _ in range(n):
        array.append(int(scanner.readline()))
    
    # Perform patience sort on the array
    patience_sort(array)
    
    # Print the sorted array
    for num in array:
        print(num, end=' ')

if __name__ == '__main__':
    main()

