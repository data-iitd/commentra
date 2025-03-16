class Heap:
    def __init__(self):
        self.data = []  # List to store the heap elements
        self.map = {}   # Dictionary to store the index of each element for quick access

    def add(self, item):
        if item is None:
            raise ValueError("Cannot insert null into the heap.")
        self.data.append(item)  # Add the item to the data list
        self.map[item] = len(self.data) - 1  # Update the map with the index of the newly added item
        self.up_heapify(len(self.data) - 1)  # Restore the heap property

    def up_heapify(self, ci):
        pi = (ci - 1) // 2  # Calculate the parent's index
        if ci > 0 and self.is_larger(self.data[ci], self.data[pi]) > 0:
            self.swap(pi, ci)  # Swap if the current item is larger than its parent
            self.up_heapify(pi)  # Continue upHeapifying from the parent's index

    def size(self):
        return len(self.data)  # Get the current size of the heap

    def is_empty(self):
        return self.size() == 0  # Check if the heap is empty

    def remove(self):
        if self.is_empty():
            raise Exception("Heap is empty")
        self.swap(0, self.size() - 1)  # Swap the root with the last element
        rv = self.data.pop()  # Remove the last element (which is the maximum)
        del self.map[rv]  # Remove the element from the map
        self.down_heapify(0)  # Restore the heap property
        return rv

    def down_heapify(self, pi):
        lci = 2 * pi + 1  # Left child index
        rci = 2 * pi + 2  # Right child index
        maxi = pi  # Assume the current index is the largest
        if lci < self.size() and self.is_larger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci
        if rci < self.size() and self.is_larger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci
        if maxi != pi:
            self.swap(pi, maxi)  # Swap and continue downHeapifying
            self.down_heapify(maxi)

    def get(self):
        if self.is_empty():
            raise Exception("Heap is empty")
        return self.data[0]  # Return the root of the heap

    def is_larger(self, t, o):
        return (t > o) - (t < o)  # Compare using natural ordering

    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        self.data[i], self.data[j] = jth, ith  # Swap in the data list
        self.map[ith] = j  # Update the indices in the map
        self.map[jth] = i

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    heap = Heap()  # Create a new heap instance
    operations = int(data[0])  # Read the number of operations
    results = []
    
    for i in range(1, operations + 1):
        choice = int(data[i])  # Read the operation choice
        if choice == 1:  # Add an element to the heap
            element = int(data[i + 1])
            heap.add(element)
            results.append(f"Added: {element}")
            i += 1
        elif choice == 2:  # Remove the maximum element from the heap
            try:
                results.append(f"Removed: {heap.remove()}")
            except Exception:
                results.append("Heap is empty.")
        elif choice == 3:  # Get the maximum element from the heap
            try:
                results.append(f"Max element: {heap.get()}")
            except Exception:
                results.append("Heap is empty.")
        elif choice == 4:  # Get the size of the heap
            results.append(f"Heap size: {heap.size()}")
        elif choice == 5:  # Check if the heap is empty
            results.append(f"Heap is empty: {heap.is_empty()}")
        else:  # Handle invalid operation choices
            results.append("Invalid operation.")
    
    print("\n".join(results))  # Print all results at once

if __name__ == "__main__":
    main()

# <END-OF-CODE>
