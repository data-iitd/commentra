class Main:
    def find(self, array, key):
        # Check if the input array is empty and raise an exception if it is
        if len(array) == 0:
            raise ValueError("Input array must not be empty.")
        
        # Check if the input array is sorted and raise an exception if it is not
        if not self.is_sorted(array):
            raise ValueError("Input array must be sorted.")
        
        # Check if the key is None and raise an exception if it is
        if key is None:
            raise ValueError("Key must not be None.")
        
        # Initialize Fibonacci numbers for the search
        fib_minus1 = 1  # F(n-1)
        fib_minus2 = 0  # F(n-2)
        fib_number = fib_minus1 + fib_minus2  # F(n)
        
        # Get the length of the array
        n = len(array)
        
        # Find the largest Fibonacci number less than the length of the array
        while fib_number < n:
            fib_minus2 = fib_minus1
            fib_minus1 = fib_number
            fib_number = fib_minus2 + fib_minus1
        
        # Initialize offset for the current position in the array
        offset = -1
        
        # Perform Fibonacci search
        while fib_number > 1:
            # Calculate the index to compare with the key
            i = min(offset + fib_minus2, n - 1)
            
            # If the key is greater than the value at index i, move to the right
            if array[i] < key:
                fib_number = fib_minus1
                fib_minus1 = fib_minus2
                fib_minus2 = fib_number - fib_minus1
                offset = i
            # If the key is less than the value at index i, move to the left
            elif array[i] > key:
                fib_number = fib_minus2
                fib_minus1 = fib_minus1 - fib_minus2
                fib_minus2 = fib_number - fib_minus1
            # If the key is found, return the index
            else:
                return i
        
        # Check if the last element is the key
        if fib_minus1 == 1 and offset + 1 < n and array[offset + 1] == key:
            return offset + 1  # Return the index of the key
        
        # Return -1 if the key is not found in the array
        return -1

    # Method to check if the array is sorted
    def is_sorted(self, array):
        # Iterate through the array to check for sorted order
        for i in range(1, len(array)):
            # If any element is greater than the next one, return False
            if array[i - 1] > array[i]:
                return False
        # Return True if the array is sorted
        return True


if __name__ == "__main__":
    # Create a Scanner-like input method
    n = int(input())
    
    # Initialize an array of Integer with the specified size
    array = [int(input()) for _ in range(n)]
    
    # Read the key value to search for in the array
    key = int(input())
    
    # Create an instance of Main to access the find method
    searcher = Main()
    
    # Call the find method to search for the key in the array and store the result index
    index = searcher.find(array, key)
    
    # Print the index of the found key or -1 if not found
    print(index)

# <END-OF-CODE>
