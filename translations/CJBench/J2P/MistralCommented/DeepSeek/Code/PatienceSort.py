import heapq
from typing import List, TypeVar, Iterable

T = TypeVar('T', bound=Comparable)

def main():
    # Initialize a Scanner to read input from the standard input
    scanner = Scanner(System.in)

    # Read the number of elements in the array from the standard input
    n = scanner.nextInt()

    # Allocate an array of Integer type with the given size
    array = [None] * n

    # Read each element of the array from the standard input and store it in the corresponding index
    for i in range(n):
        array[i] = scanner.nextInt()

    # Call the patienceSort method to sort the array using the Merge-Sort algorithm with patience
    patienceSort(array)

    # Print each element of the sorted array to the standard output
    for num in array:
        print(num, end=" ")

    # Close the Scanner to release the system resources
    scanner.close()

def patienceSort(array: List[T]) -> List[T]:
    # Base case: if the array is empty, return it as is
    if len(array) == 0:
        return array

    # Form piles of elements using the Merge-Sort algorithm with patience
    piles = formPiles(array)

    # Merge the piles using a PriorityQueue
    pq = mergePiles(piles)

    # Extract the sorted elements from the PriorityQueue and store them back in the array
    extractPiles(array, pq)

    # Return the sorted array as a result
    return array

def formPiles(array: List[T]) -> List[List[T]]:
    piles = []
    lastElements = []

    # Iterate through each element in the array
    for x in array:
        # Determine the position where the current element should be placed in the lastElements List
        pos = bisect.bisect_left(lastElements, x)

        # If the current element is smaller than the last element in the lastElements List,
        # it should be placed before that element in the corresponding pile
        if pos < len(piles):
            piles[pos].append(x)
            lastElements[pos] = x
        else:
            # Otherwise, create a new pile and add the current element to it
            newPile = []
            newPile.append(x)
            piles.append(newPile)
            lastElements.append(x)

    # Return the piles List as a result
    return piles

def mergePiles(piles: Iterable[List[T]]) -> List[T]:
    pq = []

    # Iterate through each pile in the piles Iterable
    for pile in piles:
        # Create a new PileNode with the last element of the current pile and the pile itself
        # Add the new PileNode to the PriorityQueue
        heapq.heappush(pq, (-pile[-1], pile))

    # Return the PriorityQueue of PileNodes as a result
    return pq

def extractPiles(array: List[T], pq: List[T]):
    index = 0

    # Iterate through each PileNode in the PriorityQueue until it is empty
    while pq:
        # Dequeue the current PileNode from the PriorityQueue
        _, node = heapq.heappop(pq)

        # Store the value of the current PileNode (the last element of the corresponding pile)
        # in the corresponding index of the array
        array[index] = node[-1]
        index += 1

        # If the pile of the current PileNode is not empty, add its last element to the PriorityQueue
        if node[:-1]:
            # Create a new PileNode with the last element of the updated pile and the pile itself
            # Add the new PileNode to the PriorityQueue
            heapq.heappush(pq, (-node[-2], node[:-1]))

if __name__ == "__main__":
    main()
