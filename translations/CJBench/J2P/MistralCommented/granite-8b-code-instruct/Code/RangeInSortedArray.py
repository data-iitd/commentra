

import sys

# Function to find the indices of the first and last occurrences of a given key in a sorted array
def sorted_range(nums, key):
    range = [-1, -1] # Initialize an array to store the indices of the first and last occurrences of the key

    # Binary search algorithm to find the indices
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range, True)
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range, False)

    # Return the indices array
    return range

# Iterative implementation of binary search algorithm
def altered_bin_search_iter(nums, key, left, right, range, go_left):
    # Continue searching while the left index is less than or equal to the right index
    while left <= right:
        mid = (left + right) // 2 # Calculate the middle index

        # Check if the middle element is greater than the key
        if nums[mid] > key:
            # If so, update the right index to search in the left half of the array
            right = mid - 1
        # Check if the middle element is less than the key
        elif nums[mid] < key:
            # If so, update the left index to search in the right half of the array
            left = mid + 1
        # If the middle element is equal to the key
        else:
            # If we're searching for the leftmost occurrence, update the range indices and return
            if go_left:
                if mid == 0 or nums[mid - 1]!= key:
                    range[0] = mid
                    return
                else:
                    # If the previous element is also the key, update the right index to search in the left half
                    right = mid - 1
            # If we're searching for the rightmost occurrence, update the range indices and return
            else:
                if mid == len(nums) - 1 or nums[mid + 1]!= key:
                    range[1] = mid
                    return
                else:
                    # If the next element is also the key, update the left index to search in the right half
                    left = mid + 1

# Main method to read input and call the sorted_range method
def main():
    n = int(input()) # Read the number of elements in the array
    nums = list(map(int, input().split())) # Read the array elements and convert them to a list
    key = int(input()) # Read the key

    range = sorted_range(nums, key) # Call the sorted_range method to find the indices of the first and last occurrences

    # Print the indices of the first and last occurrences
    print(range[0], range[1])

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "