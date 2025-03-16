class Main:
    def find(self, array, key):
        # Check if the array is empty
        if len(array) == 0:
            raise ValueError("Input array must not be empty.")

        # Check if the array is sorted
        if not self.is_sorted(array):
            raise ValueError("Input array must be sorted.")

        # Check if the key is None
        if key is None:
            raise ValueError("Key must not be null.")

        # Initialize variables for Fibonacci sequence calculation
        fib_minus1 = 1
        fib_minus2 = 0
        fib_number = fib_minus1 + fib_minus2

        # Get the length of the array
        n = len(array)

        # Use Fibonacci sequence to find the optimal search interval
        while fib_number < n:
            fib_minus2 = fib_minus1
            fib_minus1 = fib_number
            fib_number = fib_minus1 + fib_minus2

        # Initialize an offset variable to keep track of the current position in the array
        offset = -1

        # Use Fibonacci sequence to find the position of the key in the array
        while fib_number > 1:
            i = min(offset + fib_minus2, n - 1)

            # Compare the current element with the key and adjust the search interval accordingly
            if array[i] < key:
                fib_number = fib_minus1
                fib_minus1 = fib_minus2
                fib_minus2 = fib_number - fib_minus1
                offset = i
            elif array[i] > key:
                fib_number = fib_minus2
                fib_minus1 = fib_minus1 - fib_minus2
                fib_minus2 = fib_number - fib_minus1

        # Check if the key is located at the last position of the search interval
        if fib_minus1 == 1 and offset + 1 < n and array[offset + 1] == key:
            return offset + 1

        # Return -1 if the key is not found in the array
        return -1

    # Helper method to check if an array is sorted or not
    def is_sorted(self, array):
        # Iterate through the array to check if it is sorted
        for i in range(1, len(array)):
            # Compare adjacent elements and return False if they are not in the correct order
            if array[i - 1] > array[i]:
                return False

        # Return True if the array is sorted
        return True


if __name__ == "__main__":
    # Initialize a list to read input from the user
    n = int(input("Enter the size of the array: "))

    # Allocate memory for an array of Integer type with the given size
    array = []

    # Read the elements of the array from the user input
    print("Enter the elements of the array:")
    for _ in range(n):
        array.append(int(input()))

    # Read the key to be searched from the user input
    key = int(input("Enter the key to be searched: "))

    # Create an instance of the Main class to call the find() method
    searcher = Main()

    # Call the find() method to search for the key in the array
    index = searcher.find(array, key)

    # Print the index of the key in the array
    print(index)

# <END-OF-CODE>
