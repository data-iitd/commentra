import heapq

class Main:
    # List to store the heap elements
    data = []
    # Map to store the index of each element for quick access
    map = {}

    # Method to add an item to the heap
    def add(self, item):
        # Validate that the item is not null
        if item is None:
            raise Exception("Cannot insert null into the heap.")
        # Add the item to the data list
        self.data.append(item)
        # Update the map with the index of the newly added item
        self.map[item] = len(self.data) - 1
        # Restore the heap property by moving the item up the heap
        self.upHeapify(len(self.data) - 1)

    # Method to restore the heap property by moving the item at index ci up
    def upHeapify(self, ci):
        pi = (ci - 1) // 2 # Calculate the parent's index
        # If the current item is larger than its parent, swap them
        if ci > 0 and self.isLarger(self.data[ci], self.data[pi]) > 0:
            self.swap(pi, ci)
            # Continue upHeapifying from the parent's index
            self.upHeapify(pi)

    # Method to get the current size of the heap
    def size(self):
        return len(self.data)

    # Method to check if the heap is empty
    def isEmpty(self):
        return self.size() == 0

    # Method to remove and return the maximum item from the heap
    def remove(self):
        # Check if the heap is empty before removing
        if self.isEmpty():
            raise Exception("Heap is empty")
        # Swap the root with the last element
        self.swap(0, self.size() - 1)
        # Remove the last element (which is the maximum)
        rv = self.data.pop()
        # Remove the element from the map
        del self.map[rv]
        # Restore the heap property by moving the new root down
        self.downHeapify(0)
        return rv

    # Method to restore the heap property by moving the item at index pi down
    def downHeapify(self, pi):
        lci = 2 * pi + 1 # Left child index
        rci = 2 * pi + 2 # Right child index
        maxi = pi # Assume the current index is the largest
        # Check if the left child is larger than the current maximum
        if lci < self.size() and self.isLarger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci
        # Check if the right child is larger than the current maximum
        if rci < self.size() and self.isLarger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci
        # If the maximum is not the current index, swap and continue downHeapifying
        if maxi!= pi:
            self.swap(pi, maxi)
            self.downHeapify(maxi)

    # Method to get the maximum element from the heap without removing it
    def get(self):
        # Check if the heap is empty before accessing the maximum
        if self.isEmpty():
            raise Exception("Heap is empty")
        return self.data[0] # Return the root of the heap

    # Method to compare two elements
    def isLarger(self, t, o):
        return t - o # Compare using the natural ordering

    # Method to swap two elements in the heap and update their indices in the map
    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        self.data[i] = jth # Swap in the data list
        self.data[j] = ith
        # Update the indices in the map
        self.map[ith] = j
        self.map[jth] = i

# Main method to run the heap operations
if __name__ == "__main__":
    scanner = Scanner(System.in)
    heap = Main() # Create a new heap instance
    operations = scanner.nextInt() # Read the number of operations
    # Loop through the number of operations
    for i in range(operations):
        choice = scanner.nextInt() # Read the operation choice
        if choice == 1: # Add an element to the heap
            element = scanner.nextInt()
            heap.add(element)
            print("Added: " + str(element))
        elif choice == 2: # Remove the maximum element from the heap
            try:
                print("Removed: " + str(heap.remove()))
            except Exception as e:
                print("Heap is empty.")
        elif choice == 3: # Get the maximum element from the heap
            try:
                print("Max element: " + str(heap.get()))
            except Exception as e:
                print("Heap is empty.")
        elif choice == 4: # Get the size of the heap
            print("Heap size: " + str(heap.size()))
        elif choice == 5: # Check if the heap is empty
            print("Heap is empty: " + str(heap.isEmpty()))
        else: # Handle invalid operation choices
            print("Invalid operation.")
    scanner.close() # Close the scanner to free resources

