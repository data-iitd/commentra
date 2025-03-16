import sys

def main():
    # Read the number of elements to be sorted
    n = int(sys.stdin.readline())
    
    # Initialize an array to hold the integers
    array = []
    
    # Read the integers from user input and store them in the array
    for i in range(n):
        array.append(int(sys.stdin.readline()))
    
    # Sort the array using the sort method
    sort(array)
    
    # Print the sorted array
    for num in array:
        print(num, end=" ")
    
    # Close the scanner to prevent resource leaks
    sys.stdin.close()

# Generic method to sort an array of comparable items
def sort(array):
    length = len(array)
    
    # Iterate through each element in the array
    for cycleStart in range(length - 1):
        # Store the current item to be placed
        item = array[cycleStart]
        
        # Find the position where the current item should be placed
        pos = findPosition(array, cycleStart, item)
        
        # If the item is already in the correct position, continue to the next item
        if pos == cycleStart:
            continue
        
        # Place the item at the found position
        item = placeItem(array, item, pos)
        
        # Continue placing the item until it is in the correct position
        while pos != cycleStart:
            pos = findPosition(array, cycleStart, item)
            item = placeItem(array, item, pos)
    
    return array # Return the sorted array

# Method to find the position for the current item in the sorted part of the array
def findPosition(array, cycleStart, item):
    pos = cycleStart
    
    # Compare the item with the elements in the array to determine its position
    for i in range(cycleStart + 1, len(array)):
        if array[i] < item:
            pos += 1 # Increment position if the current element is less than the item
    
    return pos # Return the calculated position

# Method to place the item in the array at the specified position
def placeItem(array, item, pos):
    # Move to the next position if the item is equal to the element at the current position
    while item == array[pos]:
        pos += 1
    
    # Replace the element at the position with the item and return the replaced item
    replacedItem = array[pos]
    array[pos] = item
    return replacedItem

if __name__ == "__main__":
    main()

