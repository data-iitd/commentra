import sys; # Importing sys module to read input

def sortedRange(nums, key):
    range = [-1, -1] # Initialize range with -1 values
    alteredBinSearchIter(nums, key, 0, len(nums) - 1, range, True) # Search for the left boundary
    alteredBinSearchIter(nums, key, 0, len(nums) - 1, range, False) # Search for the right boundary
    return range # Return the range of indices

# Helper method to perform a binary search to find the boundaries of the key
def alteredBinSearchIter(nums, key, left, right, range, goLeft):
    while left <= right: # Continue until the search space is exhausted
        mid = (left + right) // 2 # Calculate the middle index
        if nums[mid] > key:
            right = mid - 1 # Adjust the right boundary
        elif nums[mid] < key:
            left = mid + 1 # Adjust the left boundary
        else:
            if goLeft:
                if mid == 0 or nums[mid - 1]!= key: # Check if we've found the left boundary
                    range[0] = mid # Set the left boundary
                    return # Exit the method
                else:
                    right = mid - 1 # Continue searching to the left
            else:
                if mid == len(nums) - 1 or nums[mid + 1]!= key: # Check if we've found the right boundary
                    range[1] = mid # Set the right boundary
                    return # Exit the method
                else:
                    left = mid + 1 # Continue searching to the right
    return

# Main method to run the program
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip()) # Read the number of elements
    nums = [int(sys.stdin.readline().strip()) for _ in range(n)] # Create an array to store the elements
    key = int(sys.stdin.readline().strip()) # Read the key to search for
    range = sortedRange(nums, key) # Find the range of the key
    print(range[0], range[1]) # Print the range

