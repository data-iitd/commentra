
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

def main():
    # Initialize a Scanner to read input from the standard input
    scanner = Scanner(System.in);

    # Read the number of elements in the array from the standard input
    n = scanner.nextInt();

    # Allocate an array of Integer type with the given size
    array = [None] * n;

    # Read each element of the array from the standard input and store it in the corresponding index
    for i in range(n):
        array[i] = scanner.nextInt();

    # Call the patienceSort method to sort the array using the Merge-Sort algorithm with patience
    patienceSort(array);

    # Print each element of the sorted array to the standard output
    for num in array:
        print(num, end=" ");

    # Close the Scanner to release the system resources
    scanner.close();

def patienceSort(array):
    # Base case: if the array is empty, return it as is
    if len(array) == 0:
        return array;

    # Form piles of elements using the Merge-Sort algorithm with patience
    piles = formPiles(array);

    # Merge the piles using a PriorityQueue
    pq = mergePiles(piles);

    # Extract the sorted elements from the PriorityQueue and store them back in the array
    extractPiles(array, pq);

    # Return the sorted array as a result
    return array;

def formPiles(array):
    piles = ArrayList();
    lastElements = ArrayList();

    # Iterate through each element in the array
    for x in array:
        # Determine the position where the current element should be placed in the lastElements List
        pos = Collections.binarySearch(lastElements, x);

        # If the current element is smaller than the last element in the lastElements List,
        # it should be placed before that element in the corresponding pile
        if pos < 0:
            pos = -pos - 1;

        # If the current position is within the bounds of the piles List,
        # add the current element to the corresponding pile and update the lastElements List
        if pos < piles.size():
            piles.get(pos).add(x);
            lastElements.set(pos, x);
        else:
            # Otherwise, create a new pile and add the current element to it
            newPile = ArrayList();
            newPile.add(x);
            piles.add(newPile);
            lastElements.add(x);

    # Return the piles List as a result
    return piles;

def mergePiles(piles):
    pq = PriorityQueue();

    # Iterate through each pile in the piles Iterable
    for pile in piles:
        # Create a new PileNode with the last element of the current pile and the pile itself
        # Add the new PileNode to the PriorityQueue
        pq.add(PileNode(pile.remove(pile.size() - 1), pile));

    # Return the PriorityQueue of PileNodes as a result
    return pq;

def extractPiles(array, pq):
    index = 0;

    # Iterate through each PileNode in the PriorityQueue until it is empty
    while not pq.isEmpty():
        # Dequeue the current PileNode from the PriorityQueue
        node = pq.poll();

        # Store the value of the current PileNode (the last element of the corresponding pile)
        # in the corresponding index of the array
        array[index++] = node.value;

        # If the pile of the current PileNode is not empty, add its last element to the PriorityQueue
        if not node.pile.isEmpty():
            # Create a new PileNode with the last element of the updated pile and the pile itself
            # Add the new PileNode to the PriorityQueue
            pq.add(PileNode(node.pile.remove(node.pile.size() - 1), node.pile));

class PileNode(Comparable):
    # The value of the current pile (the last element)
    value;

    # The pile itself (the rest of the elements)
    pile;

    # Initialize a new PileNode with the given value and pile
    def __init__(self, value, pile):
        self.value = value;
        self.pile = pile;

    # Implement the Comparable interface to compare two PileNodes based on their values
    def compareTo(self, other):
        return self.value.compareTo(other.value);

if __name__ == "__main__":
    main();

