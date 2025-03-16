def sorted_range(nums, key):
    range_ = [-1, -1]  # Initialize a list to store the indices of the first and last occurrences of the key

    # Binary search algorithm to find the indices
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_, True)
    altered_bin_search_iter(nums, key, 0, len(nums) - 1, range_, False)

    # Return the indices list
    return range_


def altered_bin_search_iter(nums, key, left, right, range_, go_left):
    # Continue searching while the left index is less than or equal to the right index
    while left <= right:
        mid = (left + right) // 2  # Calculate the middle index

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
                if mid == 0 or nums[mid - 1] != key:
                    range_[0] = mid
                    return
                else:
                    # If the previous element is also the key, update the right index to search in the left half
                    right = mid - 1
            # If we're searching for the rightmost occurrence, update the range indices and return
            else:
                if mid == len(nums) - 1 or nums[mid + 1] != key:
                    range_[1] = mid
                    return
                else:
                    # If the next element is also the key, update the left index to search in the right half
                    left = mid + 1


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read the number of elements in the array and initialize the array
    n = int(data[0])
    nums = list(map(int, data[1:n+1]))  # Read each element of the array

    # Read the key and call the sorted_range method to find the indices of the first and last occurrences
    key = int(data[n+1])
    range_ = sorted_range(nums, key)

    # Print the indices of the first and last occurrences
    print(range_[0], range_[1])


if __name__ == "__main__":
    main()

