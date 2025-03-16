

class Main:
    def __init__(self):
        self.data = []  # Declare a private list to store the data in the heap
        self.map = {}  # Declare a private dictionary to maintain the mapping between the data and their indices

    def add(self, item):
        if item is None:  # Check if the item is None
            raise ValueError("Cannot insert None into the heap.")  # Raise a ValueError exception if it is
        self.data.append(item)  # Add the item to the data list
        self.map[item] = len(self.data) - 1  # Add the mapping of the item to its index in the data list
        self.up_heapify(len(self.data) - 1)  # Call up_heapify method to maintain the heap property after insertion

    def up_heapify(self, ci):
        pi = (ci - 1) // 2  # Calculate the index of the parent node
        if ci > 0 and self.is_larger(self.data[ci], self.data[pi]) > 0:  # Check if the current node is the root node or its parent node is larger
            self.swap(pi, ci)  # Swap the current node with its parent node if the condition is true
            self.up_heapify(pi)  # Recursively call up_heapify method for the parent node

    def size(self):
        return len(self.data)  # Return the size of the heap

    def is_empty(self):
        return self.size() == 0  # Check if the heap is empty

    def remove(self):
        if self.is_empty():  # Check if the heap is empty
            raise IndexError("Heap is empty")  # Raise an IndexError exception if it is
        self.swap(0, len(self.data) - 1)  # Swap the first and last elements
        rv = self.data.pop()  # Remove the last element from the data list
        del self.map[rv]  # Remove the mapping of the removed element from the dictionary
        self.down_heapify(0)  # Call down_heapify method to maintain the heap property after deletion
        return rv  # Return the removed element

    def down_heapify(self, pi):
        lci = 2 * pi + 1  # Calculate the indices of the left and right child nodes
        rci = 2 * pi + 2
        maxi = pi  # Initialize the index of the maximum node as the parent node index
        if lci < len(self.data) and self.is_larger(self.data[lci], self.data[maxi]) > 0:  # Check if the left child node exists and is larger than the parent node
            maxi = lci  # Update the index of the maximum node if the condition is true
        if rci < len(self.data) and self.is_larger(self.data[rci], self.data[maxi]) > 0:  # Check if the right child node exists and is larger than the parent node
            maxi = rci  # Update the index of the maximum node if the condition is true
        if maxi!= pi:  # Check if the maximum node is not the parent node
            self.swap(pi, maxi)  # Swap the parent node with the maximum node if they are not the same
            self.down_heapify(maxi)  # Recursively call down_heapify method for the maximum node

    def get(self):
        if self.is_empty():  # Check if the heap is empty
            raise IndexError("Heap is empty")  # Raise an IndexError exception if it is
        return self.data[0]  # Return the maximum element from the data list

    def is_larger(self, t, o):
        return t > o  # Compare two elements to determine which one is larger

    def swap(self, i, j):
        ith = self.data[i]  # Get the ith element from the data list
        jth = self.data[j]  # Get the jth element from the data list
        self.data[i] = jth  # Swap the elements in the data list
        self.data[j] = ith
        self.map[ith] = j  # Update the mapping of the swapped elements in the dictionary
        self.map[jth] = i

# Main method to read user input and perform the required operations on the heap
if __name__ == "__main__":
    import sys
    operations = int(input())  # Read the number of operations from the user
    heap = Main()  # Create an instance of the Main class for an integer heap
    for _ in range(operations):
        choice = int(input())  # Read the choice of operation from the user
        if choice == 1:
            element = int(input())  # Read the element to be added from the user
            heap.add(element)  # Add the element to the heap
            print(f"Added: {element}")  # Print a message to confirm the addition
        elif choice == 2:
            try:
                print(f"Removed: {heap.remove()}")  # Remove the maximum element from the heap and print a message to confirm the removal
            except IndexError:
                print("Heap is empty.")  # Print a message if the heap is empty and an exception is thrown
        elif choice == 3:
            try:
                print(f"Max element: {heap.get()}")  # Get the maximum element from the heap and print it
            except IndexError:
                print("Heap is empty.")  # Print a message if the heap is empty and an exception is thrown
        elif choice == 4:
            print(f"Heap size: {heap.size()}")  # Print the size of the heap
        elif choice == 5:
            print(f"Heap is empty: {heap.is_empty()}")  # Print a message to confirm if the heap is empty or not
        else:
            print("Invalid operation.")  # Print a message for an invalid choice of operation

