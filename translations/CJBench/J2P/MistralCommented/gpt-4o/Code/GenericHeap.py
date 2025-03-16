class MaxHeap:
    def __init__(self):
        # Initialize a list to store the data in the heap
        self.data = []
        # Initialize a dictionary to maintain the mapping between the data and their indices
        self.map = {}

    def add(self, item):
        if item is None:  # Check if the item is None
            raise ValueError("Cannot insert None into the heap.")  # Raise an exception if it is
        # Add the item to the data list
        self.data.append(item)
        # Add the mapping of the item to its index in the data list
        self.map[item] = len(self.data) - 1
        # Call upHeapify method to maintain the heap property after insertion
        self.up_heapify(len(self.data) - 1)

    def up_heapify(self, ci):
        pi = (ci - 1) // 2  # Calculate the index of the parent node
        # Check if the current node is the root node or its parent node is smaller
        if ci > 0 and self.is_larger(self.data[ci], self.data[pi]) > 0:
            # Swap the current node with its parent node if the condition is true
            self.swap(pi, ci)
            # Recursively call upHeapify method for the parent node
            self.up_heapify(pi)

    def size(self):
        return len(self.data)  # Get the size of the heap

    def is_empty(self):
        return self.size() == 0  # Check if the heap is empty

    def remove(self):
        if self.is_empty():  # Check if the heap is empty
            raise Exception("Heap is empty")  # Raise an exception if it is
        # Swap the first and last elements
        self.swap(0, self.size() - 1)
        # Remove the last element from the data list
        rv = self.data.pop()
        # Remove the mapping of the removed element from the dictionary
        del self.map[rv]
        # Call downHeapify method to maintain the heap property after deletion
        self.down_heapify(0)
        # Return the removed element
        return rv

    def down_heapify(self, pi):
        lci = 2 * pi + 1  # Calculate the indices of the left and right child nodes
        rci = 2 * pi + 2
        maxi = pi  # Initialize the index of the maximum node as the parent node index
        # Check if the left child node exists and is larger than the parent node
        if lci < self.size() and self.is_larger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci  # Update the index of the maximum node if the condition is true
        # Check if the right child node exists and is larger than the parent node
        if rci < self.size() and self.is_larger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci  # Update the index of the maximum node if the condition is true
        # Swap the parent node with the maximum node if they are not the same
        if maxi != pi:
            self.swap(pi, maxi)
            # Recursively call downHeapify method for the maximum node
            self.down_heapify(maxi)

    def get(self):
        if self.is_empty():  # Check if the heap is empty
            raise Exception("Heap is empty")  # Raise an exception if it is
        # Return the maximum element from the data list
        return self.data[0]

    def is_larger(self, t, o):
        return (t > o) - (t < o)  # Compare two elements to determine which one is larger

    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        # Swap the elements in the data list
        self.data[i], self.data[j] = jth, ith
        # Update the mapping of the swapped elements in the dictionary
        self.map[ith] = j
        self.map[jth] = i

# Main method to read user input and perform the required operations on the heap
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    heap = MaxHeap()  # Create an instance of the MaxHeap class
    operations = int(data[0])  # Read the number of operations from the user
    for i in range(1, operations + 1):
        choice = int(data[i])  # Read the choice of operation from the user
        if choice == 1:
            element = int(data[i + 1])  # Read the element to be added from the user
            heap.add(element)  # Add the element to the heap
            print(f"Added: {element}")  # Print a message to confirm the addition
            i += 1
        elif choice == 2:
            try:
                print(f"Removed: {heap.remove()}")  # Remove the maximum element from the heap
            except Exception as e:
                print("Heap is empty.")  # Print a message if the heap is empty
        elif choice == 3:
            try:
                print(f"Max element: {heap.get()}")  # Get the maximum element from the heap
            except Exception as e:
                print("Heap is empty.")  # Print a message if the heap is empty
        elif choice == 4:
            print(f"Heap size: {heap.size()}")  # Print the size of the heap
        elif choice == 5:
            print(f"Heap is empty: {heap.is_empty()}")  # Print if the heap is empty
        else:
            print("Invalid operation.")  # Print a message for an invalid choice of operation

# <END-OF-CODE>
