import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

def main():
    # Create a scanner to read input from the console
    scanner = java.util.Scanner(System.in);
    
    # Read the number of elements in the array
    n = scanner.nextInt();
    array = [None] * n;
    
    # Read the elements of the array from the input
    for i in range(n):
        array[i] = scanner.nextInt();
    
    # Perform patience sort on the array
    patienceSort(array);
    
    # Print the sorted array
    for num in array:
        print(num, end=" ");
    
    # Close the scanner to free resources
    scanner.close();

# Method to perform patience sort on an array
def patienceSort(array):
    # Return the array as is if it is empty
    if (len(array) == 0):
        return array;
    
    # Form piles from the array elements
    piles = formPiles(array);
    
    # Merge the piles into a priority queue
    pq = mergePiles(piles);
    
    # Extract the sorted elements from the priority queue back into the array
    extractPiles(array, pq);
    
    return array;

# Method to form piles based on the patience sorting algorithm
def formPiles(array):
    piles = ArrayList();
    lastElements = ArrayList();
    
    # Iterate through each element in the array
    for x in array:
        # Find the position to place the current element in the lastElements list
        pos = Collections.binarySearch(lastElements, x);
        if (pos < 0):
            pos = -pos - 1; # Get the insertion point
        
        # If the position is within the current number of piles
        if (pos < piles.size()):
            # Add the element to the corresponding pile
            piles.get(pos).add(x);
            lastElements.set(pos, x); # Update the last element of the pile
        else:
            # Create a new pile for the current element
            newPile = ArrayList();
            newPile.add(x);
            piles.add(newPile);
            lastElements.add(x); # Add the new last element
    return piles; # Return the formed piles

# Method to merge the piles into a priority queue
def mergePiles(piles):
    pq = PriorityQueue();
    
    # Add the top element of each pile to the priority queue
    for pile in piles:
        pq.add(PileNode(pile.remove(pile.size() - 1), pile));
    return pq; # Return the priority queue containing the top elements of each pile

# Method to extract sorted elements from the priority queue back into the array
def extractPiles(array, pq):
    index = 0; # Index to track position in the output array
    
    # While there are elements in the priority queue
    while not pq.isEmpty():
        node = pq.poll(); # Get the smallest element
        array[index++] = node.value; # Place it in the sorted array
        
        # If the current pile still has elements, add the next top element to the queue
        if (not node.pile.isEmpty()):
            pq.add(PileNode(node.pile.remove(node.pile.size() - 1), node.pile));

# Class to represent a node in the priority queue, holding a value and a reference to its pile
class PileNode(Comparable):
    def __init__(self, value, pile):
        self.value = value;
        self.pile = pile;
    
    # Compare this node with another based on the value
    def compareTo(self, other):
        return self.value.compareTo(other.value);

if __name__ == "__main__":
    main();

