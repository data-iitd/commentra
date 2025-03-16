
import heapq
class Main:
    def __init__(self):
        self.data = [] # List to store heap elements
        self.map = {} # Dictionary to quickly find element index
    def add(self, item):
        if item is None:
            raise ValueError("Cannot insert None into the heap.") # Check for None insertion
        heapq.heappush(self.data, item) # Add item to the heap
        self.map[item] = len(self.data) - 1 # Update the map with the item's index
    def size(self):
        return len(self.data) # Return the number of elements in the heap
    def isEmpty(self):
        return self.size() == 0 # Check if the heap is empty
    def remove(self):
        if self.isEmpty():
            raise ValueError("Heap is empty") # Check if heap is empty
        item = heapq.heappop(self.data) # Remove and return the root element
        del self.map[item] # Remove from map
        self.fixHeap() # Maintain heap property by moving the new root down
        return item # Return the removed element
    def get(self):
        if self.isEmpty():
            raise ValueError("Heap is empty") # Check if heap is empty
        return self.data[0] # Return the root element
    def fixHeap(self):
        i = 0
        while True:
            l = 2 * i + 1
            r = 2 * i + 2
            largest = i
            if l < len(self.data) and self.data[l] > self.data[largest]:
                largest = l
            if r < len(self.data) and self.data[r] > self.data[largest]:
                largest = r
            if largest!= i:
                self.data[i], self.data[largest] = self.data[largest], self.data[i]
                self.map[self.data[i]] = i
                self.map[self.data[largest]] = largest
                i = largest
            else:
                break
    def main():
        operations = int(input())
        heap = Main()
        for _ in range(operations):
            choice = int(input())
            if choice == 1:
                element = int(input())
                heap.add(element)
                print("Added:", element) # Print added element
            elif choice == 2:
                try:
                    print("Removed:", heap.remove()) # Print removed element
                except ValueError:
                    print("Heap is empty.")
            elif choice == 3:
                try:
                    print("Max element:", heap.get()) # Print max element
                except ValueError:
                    print("Heap is empty.")
            elif choice == 4:
                print("Heap size:", heap.size()) # Print heap size
            elif choice == 5:
                print("Heap is empty:", heap.isEmpty()) # Print if heap is empty
            else:
                print("Invalid operation.")
Main.main()
