import sys

def main():
    # Read the size of the array from user input
    n = int(sys.stdin.readline())
    
    # Initialize an array of Integer with the specified size
    array = [0] * n
    
    # Populate the array with user input values
    for i in range(n):
        array[i] = int(sys.stdin.readline())
    
    # Read the key value to search for in the array
    key = int(sys.stdin.readline())
    
    # Create an instance of Main to access the find method
    searcher = Main()
    
    # Call the find method to search for the key in the array and store the result index
    index = searcher.find(array, key)
    
    # Print the index of the found key or -1 if not found
    print(index)

class Main:
    # Generic method to find the index of a key in a sorted array using Fibonacci search
    def find(self, array, key):
        # Check if the input array is empty and throw an exception if it is
        if len(array) == 0:
            raise ValueError("Input array must not be empty.")
        
        # Check if the input array is sorted and throw an exception if it is not
        if not self.isSorted(array):
            raise ValueError("Input array must be sorted.")
        
        # Check if the key is null and throw an exception if it is
        if key is None:
            raise ValueError("Key must not be null.")
        
        # Initialize Fibonacci numbers for the search
        fibMinus1 = 1 # F(n-1)
        fibMinus2 = 0 # F(n-2)
        fibNumber = fibMinus1 + fibMinus2 # F(n)
        
        # Get the length of the array
        n = len(array)
        
        # Find the largest Fibonacci number less than the length of the array
        while fibNumber < n:
            fibMinus2 = fibMinus1
            fibMinus1 = fibNumber
            fibNumber = fibMinus2 + fibMinus1
        
        # Initialize offset for the current position in the array
        offset = -1
        
        # Perform Fibonacci search
        while fibNumber > 1:
            # Calculate the index to compare with the key
            i = min(offset + fibMinus2, n - 1)
            
            # If the key is greater than the value at index i, move to the right
            if array[i] < key:
                fibNumber = fibMinus1
                fibMinus1 = fibMinus2
                fibMinus2 = fibNumber - fibMinus1
                offset = i
            
            # If the key is less than the value at index i, move to the left
            elif array[i] > key:
                fibNumber = fibMinus2
                fibMinus1 = fibMinus1 - fibMinus2
                fibMinus2 = fibNumber - fibMinus1
            
            # If the key is found, return the index
            else:
                return i
        
        # Check if the last element is the key
        if fibMinus1 == 1 and offset + 1 < n and array[offset + 1] == key:
            return offset + 1 # Return the index of the key
        
        # Return -1 if the key is not found in the array
        return -1
    
    # Method to check if the array is sorted
    def isSorted(self, array):
        # Iterate through the array to check for sorted order
        for i in range(1, len(array)):
            # If any element is greater than the next one, return false
            if array[i - 1] > array[i]:
                return False
        
        # Return true if the array is sorted
        return True

if __name__ == "__main__":
    main()

