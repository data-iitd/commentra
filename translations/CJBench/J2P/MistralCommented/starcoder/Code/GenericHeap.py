
class Main:
    # Declare a private list to store the data in the heap
    data = []
    
    # Declare a private dictionary to maintain the mapping between the data and their indices
    map = {}
    
    # Add method to insert an item into the heap
    def add(self, item):
        if item == None: # Check if the item is null
            raise Exception("Cannot insert null into the heap.") # Throw an exception if it is
        # Add the item to the data list
        self.data.append(item)
        # Add the mapping of the item to its index in the data list
        self.map[item] = len(self.data) - 1
        # Call upHeapify method to maintain the heap property after insertion
        self.upHeapify(len(self.data) - 1)
    
    # upHeapify method to maintain the heap property after insertion or deletion
    def upHeapify(self, ci):
        pi = (ci - 1) // 2 # Calculate the index of the parent node
        # Check if the current node is the root node or its parent node is larger
        if ci > 0 and self.isLarger(self.data[ci], self.data[pi]) > 0:
            # Swap the current node with its parent node if the condition is true
            self.swap(pi, ci)
            # Recursively call upHeapify method for the parent node
            self.upHeapify(pi)
    
    # Get the size of the heap
    def size(self):
        return len(self.data)
    
    # Check if the heap is empty
    def isEmpty(self):
        return self.size() == 0
    
    # Remove the maximum element from the heap
    def remove(self):
        if self.isEmpty(): # Check if the heap is empty
            raise Exception("Heap is empty") # Throw an exception if it is
        # Swap the first and last elements
        self.swap(0, self.size() - 1)
        # Remove the last element from the data list
        rv = self.data.pop()
        # Remove the mapping of the removed element from the dictionary
        del self.map[rv]
        # Call downHeapify method to maintain the heap property after deletion
        self.downHeapify(0)
        # Return the removed element
        return rv
    
    # downHeapify method to maintain the heap property after deletion
    def downHeapify(self, pi):
        lci = 2 * pi + 1 # Calculate the indices of the left and right child nodes
        rci = 2 * pi + 2
        maxi = pi # Initialize the index of the maximum node as the parent node index
        # Check if the left child node exists and is larger than the parent node
        if lci < self.size() and self.isLarger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci # Update the index of the maximum node if the condition is true
        # Check if the right child node exists and is larger than the parent node
        if rci < self.size() and self.isLarger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci # Update the index of the maximum node if the condition is true
        # Swap the parent node with the maximum node if they are not the same
        if maxi!= pi:
            self.swap(pi, maxi)
            # Recursively call downHeapify method for the maximum node
            self.downHeapify(maxi)
    
    # Get the maximum element from the heap
    def get(self):
        if self.isEmpty(): # Check if the heap is empty
            raise Exception("Heap is empty") # Throw an exception if it is
        # Return the maximum element from the data list
        return self.data[0]
    
    # Compare two elements to determine which one is larger
    def isLarger(self, t, o):
        return t.compareTo(o)
    
    # Swap two elements in the data list and in the dictionary
    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        # Swap the elements in the data list
        self.data[i] = jth
        self.data[j] = ith
        # Update the mapping of the swapped elements in the dictionary
        self.map[ith] = j
        self.map[jth] = i

# Main method to read user input and perform the required operations on the heap
if __name__ == "__main__":
    scanner = Scanner(System.in)
    heap = Main() # Create an instance of the Main class for an integer heap
    operations = scanner.nextInt() # Read the number of operations from the user
    for i in range(operations):
        choice = scanner.nextInt() # Read the choice of operation from the user
        if choice == 1:
            element = scanner.nextInt() # Read the element to be added from the user
            heap.add(element) # Add the element to the heap
            print("Added: " + str(element)) # Print a message to confirm the addition
        elif choice == 2:
            try:
                print("Removed: " + str(heap.remove())) # Remove the maximum element from the heap and print a message to confirm the removal
            except Exception as e:
                print("Heap is empty.") # Print a message if the heap is empty and an exception is thrown
        elif choice == 3:
            try:
                print("Max element: " + str(heap.get())) # Get the maximum element from the heap and print it
            except Exception as e:
                print("Heap is empty.") # Print a message if the heap is empty and an exception is thrown
        elif choice == 4:
            print("Heap size: " + str(heap.size())) # Print the size of the heap
        elif choice == 5:
            print("Heap is empty: " + str(heap.isEmpty())) # Print a message to confirm if the heap is empty or not
        else:
            print("Invalid operation.") # Print a message for an invalid choice of operation
    scanner.close() # Close the scanner after the operations are completed

