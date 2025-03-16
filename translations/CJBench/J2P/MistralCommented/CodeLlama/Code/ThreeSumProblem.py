
import sys

# Method to find triplet with given sum using two pointers approach
def two_pointer(nums, target):
    # Sort the input array in ascending order
    nums.sort()

    # Initialize an empty list to store the result
    result = []

    # Iterate through the array from the first index to the last index - 2
    for i in range(len(nums) - 2):
        # If the current element is same as the previous element, skip it
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        # Initialize the left and right pointers
        left = i + 1
        right = len(nums) - 1

        # Two pointers approach to find the triplet with given sum
        while left < right:
            # Calculate the sum of the current triplet
            sum = nums[i] + nums[left] + nums[right]

            # If the sum is equal to the target, add the triplet to the result
            if sum == target:
                result.append([nums[i], nums[left], nums[right]])

                # Move the left pointer to the next index and the right pointer to the previous index
                left += 1
                right -= 1

                # Skip the duplicate elements
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1

            # If the sum is less than the target, move the left pointer to the next index
            elif sum < target:
                left += 1

            # If the sum is greater than the target, move the right pointer to the previous index
            else:
                right -= 1

    # Return the result
    return result

# Main method to read the input and call the twoPointer method
def main():
    # Initialize a Scanner object to read the input
    sc = sys.stdin

    # Read the size of the array and initialize the array
    n = int(sc.readline().strip())
    nums = list(map(int, sc.readline().strip().split()))

    # Read the target sum
    target = int(sc.readline().strip())

    # Create an instance of the Main class and call the twoPointer method
    result = two_pointer(nums, target)

    # Check if the result is empty and print the message accordingly
    if not result:
        print("No triplet found with the given sum.")
    else:
        # Print the result if the result is not empty
        for triplet in result:
            print(triplet)

# Close the Scanner object
sc.close()

# END-OF-CODE
