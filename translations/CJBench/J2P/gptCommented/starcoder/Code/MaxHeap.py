import heapq

class HeapElement:
    def __init__(self, key, info):
        self.key = key
        self.info = info

    def getKey(self):
        return self.key

    def getInfo(self):
        return self.info

    def __str__(self):
        return str(self.key) + " " + str(self.info)

class Main:
    def __init__(self):
        self.maxHeap = []

    def heapifyDown(self, elementIndex):
        largest = elementIndex - 1 # Index of the current element
        leftChild = 2 * elementIndex - 1 # Index of the left child
        rightChild = 2 * elementIndex # Index of the right child

        # Check if the left child exists and is greater than the current largest
        if leftChild < len(self.maxHeap) and self.maxHeap[leftChild].getKey() > self.maxHeap[largest].getKey():
            largest = leftChild # Update largest to left child

        # Check if the right child exists and is greater than the current largest
        if rightChild < len(self.maxHeap) and self.maxHeap[rightChild].getKey() > self.maxHeap[largest].getKey():
            largest = rightChild # Update largest to right child

        # If the largest is not the current element, swap and continue heapifying down
        if largest!= elementIndex - 1:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[largest]
            self.maxHeap[largest] = temp
            self.heapifyDown(largest + 1) # Recursively heapify down

    def toggleUp(self, elementIndex):
        key = self.maxHeap[elementIndex - 1].getKey() # Get the key of the element to be moved up
        # Move the element up while it is greater than its parent
        while elementIndex > 1 and self.maxHeap[(elementIndex / 2) - 1].getKey() < key:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[(elementIndex / 2) - 1]
            self.maxHeap[(elementIndex / 2) - 1] = temp
            elementIndex /= 2 # Move to the parent's index

    def insertElement(self, element):
        if element == None:
            raise Exception("Cannot insert null element") # Validate input
        self.maxHeap.append(element) # Add the new element to the heap
        self.toggleUp(len(self.maxHeap)) # Restore heap property by moving the new element up

    def extractMax(self):
        if len(self.maxHeap) == 0:
            raise Exception("Heap is empty") # Validate heap is not empty
        max = self.maxHeap[0] # Get the maximum element
        self.maxHeap[0] = self.maxHeap[len(self.maxHeap) - 1] # Replace max with the last element
        self.maxHeap.pop() # Remove the last element
        if len(self.maxHeap) > 0:
            self.heapifyDown(1) # Restore heap property by moving down the new root
        return max # Return the extracted maximum element

    def getMax(self):
        if len(self.maxHeap) == 0:
            raise Exception("Heap is empty") # Validate heap is not empty
        return self.maxHeap[0] # Return the maximum element

    def size(self):
        return len(self.maxHeap) # Return the number of elements in the heap

    def isEmpty(self):
        return len(self.maxHeap) == 0 # Return true if the heap is empty

if __name__ == "__main__":
    scanner = Scanner(System.in) # Create a scanner for user input
    heap = Main() # Create a new instance of the heap

    # Loop to process user commands
    while scanner.hasNextLine():
        command = scanner.nextLine().trim() # Read the command
        if command.isEmpty(): break # Exit on empty command
        parts = command.split(" ") # Split command into parts
        operation = parts[0] # Get the operation type

        try:
            # Switch case to handle different heap operations
            if operation == "insert":
                key = Double.parseDouble(parts[1]) # Parse the key
                info = parts.length > 2? parts[2] : None # Optional info
                heap.insertElement(HeapElement(key, info)) # Insert the new element
                print("Inserted: " + key) # Confirm insertion
            elif operation == "extractMax":
                print("Extracted Max: " + heap.extractMax()) # Extract and display max
            elif operation == "getMax":
                print("Max Element: " + heap.getMax()) # Display max without extraction
            elif operation == "size":
                print("Size: " + heap.size()) # Display the size of the heap
            elif operation == "isEmpty":
                print("Is Empty: " + heap.isEmpty()) # Check if the heap is empty
            else:
                print("Unknown operation: " + operation) # Handle unknown commands
        except Exception as e:
            print("Error: " + e.getMessage()) # Handle exceptions
