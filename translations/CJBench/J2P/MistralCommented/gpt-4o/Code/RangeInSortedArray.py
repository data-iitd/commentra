class Main:
    @staticmethod
    def sorted_range(nums, key):
        range_indices = [-1, -1]  # Initialize a list to store the indices of the first and last occurrences of the key

        # Binary search algorithm to find the indices
        Main.altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_indices, True)
        Main.altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_indices, False)

        # Return the indices list
        return range_indices

    @staticmethod
    def altered_bin_search_iter(nums, key, left, right, range_indices, go_left):
        # Continue searching while the left index is less than or equal to the right index
        while left <= right:
            mid = (left + right) // 2  # Calculate the middle index

            # Check if the middle element is greater than the key
            if nums[mid] > key:
                right = mid - 1  # Search in the left half of the array
            elif nums[mid] < key:
                left = mid + 1  # Search in the right half of the array
            else:
                # If the middle element is equal to the key
                if go_left:
                    if mid == 0 or nums[mid - 1] != key:
                        range_indices[0] = mid  # Update the first occurrence index
                        return
                    else:
                        right = mid - 1  # Search in the left half
                else:
                    if mid == len(nums) - 1 or nums[mid + 1] != key:
                        range_indices[1] = mid  # Update the last occurrence index
                        return
                    else:
                        left = mid + 1  # Search in the right half

if __name__ == "__main__":
    n = int(input())  # Read the number of elements in the array
    nums = list(map(int, input().split()))  # Read each element of the array
    key = int(input())  # Read the key
    range_indices = Main.sorted_range(nums, key)  # Find the indices of the first and last occurrences
    print(range_indices[0], range_indices[1])  # Print the indices

# <END-OF-CODE>
