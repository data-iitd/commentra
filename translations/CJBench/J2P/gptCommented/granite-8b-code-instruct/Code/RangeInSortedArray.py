
import bisect

def sorted_range(nums, key):
    # Initialize the range list to hold the starting and ending indices
    range = [-1, -1]
    
    # Perform binary search to find the leftmost index of the key
    range[0] = bisect.bisect_left(nums, key)
    
    # Perform binary search to find the rightmost index of the key
    range[1] = bisect.bisect_right(nums, key) - 1
    
    # Return the range of indices found
    return range

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize the array to hold the numbers
    nums = list(map(int, input().split()))
    
    # Read the key to search for
    key = int(input())
    
    # Get the range of indices for the key
    range = sorted_range(nums, key)
    
    # Print the starting and ending indices of the key
    print(range[0], range[1])

