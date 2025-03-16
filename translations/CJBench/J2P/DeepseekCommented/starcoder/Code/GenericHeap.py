import sys
class Main:
    def __init__(self):
        self.data = [] # ArrayList to store heap elements
        self.map = {} # HashMap to quickly find element index
    def add(self, item):
        if item == None:
            raise Exception("Cannot insert null into the heap.") # Check for null insertion
        self.data.append(item) # Add item to the heap
        self.map[item] = len(self.data) - 1 # Update the map with the item's index
        self.upHeapify(len(self.data) - 1) # Maintain heap property by moving the item up
    def upHeapify(self, ci):
        pi = (ci - 1) / 2 # Calculate parent index
        if ci > 0 and self.isLarger(self.data[ci], self.data[pi]) > 0: # Compare with parent
            self.swap(pi, ci) # Swap if necessary
            self.upHeapify(pi) # Recursively call upHeapify
    def size(self):
        return len(self.data) # Return the number of elements in the heap
    def isEmpty(self):
        return self.size() == 0 # Check if the heap is empty
    def remove(self):
        if self.isEmpty():
            raise Exception("Heap is empty") # Check if heap is empty
        self.swap(0, self.size() - 1) # Swap root with last element
        rv = self.data.pop() # Remove last element
        del self.map[rv] # Remove from map
        self.downHeapify(0) # Maintain heap property by moving the new root down
        return rv # Return the removed element
    def downHeapify(self, pi):
        lci = 2 * pi + 1 # Calculate left child index
        rci = 2 * pi + 2 # Calculate right child index
        maxi = pi # Assume parent is largest
        if lci < self.size() and self.isLarger(self.data[lci], self.data[maxi]) > 0: # Compare with left child
            maxi = lci # Update largest index
        if rci < self.size() and self.isLarger(self.data[rci], self.data[maxi]) > 0: # Compare with right child
            maxi = rci # Update largest index
        if maxi!= pi:
            self.swap(pi, maxi) # Swap if necessary
            self.downHeapify(maxi) # Recursively call downHeapify
    def get(self):
        if self.isEmpty():
            raise Exception("Heap is empty") # Check if heap is empty
        return self.data[0] # Return the root element
    def isLarger(self, t, o):
        return t.compareTo(o) # Compare two elements
    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        self.data[i] = jth # Swap elements in data list
        self.data[j] = ith
        self.map[ith] = j # Update map with new indices
        self.map[jth] = i
    def main(self):
        scanner = sys.stdin
        operations = int(scanner.readline())
        for i in range(operations):
            choice = int(scanner.readline())
            if choice == 1:
                element = int(scanner.readline())
                self.add(element)
                print("Added: " + str(element)) # Print added element
            elif choice == 2:
                try:
                    print("Removed: " + str(self.remove())) # Print removed element
                except Exception as e:
                    print("Heap is empty.")
            elif choice == 3:
                try:
                    print("Max element: " + str(self.get())) # Print max element
                except Exception as e:
                    print("Heap is empty.")
            elif choice == 4:
                print("Heap size: " + str(self.size())) # Print heap size
            elif choice == 5:
                print("Heap is empty: " + str(self.isEmpty())) # Print if heap is empty
            else:
                print("Invalid operation.")
        scanner.close()

