import java.util.ArrayList; // Importing necessary libraries for the functionality of the code
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

def main():
    scanner = java.util.Scanner(System.in); // Initialize a scanner to read input from the user
    n = scanner.nextInt(); // Read the number of elements
    array = [0] * n; // Create an array to hold the integers
    for i in range(n):
        array[i] = scanner.nextInt(); // Read n integers into the array
    patienceSort(array); // Call the patienceSort method to sort the array
    for num in array:
        print(num, end=" "); // Print the sorted array
    scanner.close(); // Close the scanner

def patienceSort(array): # Define the patienceSort method to sort an array
    if len(array) == 0: # Check if the array is empty
        return array; # Return the array if it is empty
    piles = formPiles(array); # Form piles from the array
    pq = mergePiles(piles); # Merge the piles into a priority queue
    extractPiles(array, pq); # Extract the elements from the priority queue back into the array
    return array; # Return the sorted array

def formPiles(array): # Define the formPiles method to create piles
    piles = ArrayList(); # Create a list of lists to store the piles
    lastElements = ArrayList(); # Create a list to keep track of the last elements of each pile
    for x in array: # Iterate over each element in the array
        pos = Collections.binarySearch(lastElements, x); # Find the position of the element in the list of last elements
        if pos < 0:
            pos = -pos - 1; # If the element is not found, insert it at the correct position
        if pos < piles.size(): # If the element fits into an existing pile
            piles.get(pos).add(x); # Add the element to the appropriate pile
            lastElements.set(pos, x); # Update the last element of the pile
        else: # If the element starts a new pile
            newPile = ArrayList(); # Create a new pile
            newPile.add(x); # Add the element to the new pile
            piles.add(newPile); # Add the new pile to the list of piles
            lastElements.add(x); # Add the element to the list of last elements
    return piles; # Return the list of piles

def mergePiles(piles): # Define the mergePiles method to merge piles into a priority queue
    pq = PriorityQueue(); # Create a priority queue to hold the pile nodes
    for pile in piles: # Iterate over each pile
        pq.add(PileNode(pile.remove(pile.size() - 1), pile)); # Add the last element of the pile to the priority queue and remove it from the pile
    return pq; # Return the priority queue

def extractPiles(array, pq): # Define the extractPiles method to extract elements from the priority queue
    index = 0; # Initialize the index to 0
    while not pq.isEmpty(): # While there are elements in the priority queue
        node = pq.poll(); # Remove the smallest element from the priority queue
        array[index] = node.value; # Add the element to the array
        if not node.pile.isEmpty(): # If there are more elements in the pile
            pq.add(PileNode(node.pile.remove(node.pile.size() - 1), node.pile)); # Add the next smallest element from the pile to the priority queue
        index += 1;

class PileNode(Comparable): # Define the PileNode class to represent a node in the priority queue
    def __init__(self, value, pile): # Constructor for the PileNode class
        self.value = value;
        self.pile = pile;

    def compareTo(self, other): # Implement the compareTo method to compare pile nodes based on their values
        return self.value.compareTo(other.value);

if __name__ == "__main__":
    main();

