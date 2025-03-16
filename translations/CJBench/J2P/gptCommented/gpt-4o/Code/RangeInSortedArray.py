class Main:
    @staticmethod
    def sorted_range(nums, key):
        # Initialize the range list to hold the starting and ending indices
        range_indices = [-1, -1]
        
        # Perform binary search to find the leftmost index of the key
        Main.altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_indices, True)
        
        # Perform binary search to find the rightmost index of the key
        Main.altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_indices, False)
        
        # Return the range of indices found
        return range_indices

    @staticmethod
    def altered_bin_search_iter(nums, key, left, right, range_indices, go_left):
        # Continue searching while the left index is less than or equal to the right index
        while left <= right:
            # Calculate the middle index
            mid = (left + right) // 2
            
            # If the middle element is greater than the key, search in the left half
            if nums[mid] > key:
                right = mid - 1
            # If the middle element is less than the key, search in the right half
            elif nums[mid] < key:
                left = mid + 1
            # If the middle element is equal to the key
            else:
                # If searching for the leftmost index
                if go_left:
                    # Check if it's the first occurrence of the key
                    if mid == 0 or nums[mid - 1] != key:
                        range_indices[0] = mid  # Set the starting index
                        return  # Exit the method
                    else:
                        right = mid - 1  # Continue searching in the left half
                # If searching for the rightmost index
                else:
                    # Check if it's the last occurrence of the key
                    if mid == len(nums) - 1 or nums[mid + 1] != key:
                        range_indices[1] = mid  # Set the ending index
                        return  # Exit the method
                    else:
                        left = mid + 1  # Continue searching in the right half

# Main execution
if __name__ == "__main__":
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize the array to hold the numbers
    nums = list(map(int, input().split()))
    
    # Read the key to search for
    key = int(input())
    
    # Get the range of indices for the key
    range_indices = Main.sorted_range(nums, key)
    
    # Print the starting and ending indices of the key
    print(range_indices[0], range_indices[1])

# <END-OF-CODE>
