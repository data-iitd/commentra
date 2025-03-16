import sys

# Method to find all unique triplets in the array that sum up to the target
def twoPointer(nums, target):
    # Sort the input array to facilitate the two-pointer approach
    nums.sort()
    # Initialize a list to hold the resulting triplets
    result = []
    
    # Iterate through the array, considering each element as a potential first element of a triplet
    for i in range(len(nums) - 2):
        # Skip duplicate elements to avoid duplicate triplets in the result
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        # Initialize two pointers: one at the next element and one at the end of the array
        left = i + 1
        right = len(nums) - 1
        
        # Use the two-pointer technique to find pairs that complement the current element to reach the target
        while left < right:
            # Calculate the sum of the current triplet
            sum = nums[i] + nums[left] + nums[right]
            
            # Check if the sum matches the target
            if sum == target:
                # If a valid triplet is found, add it to the result list
                result.append([nums[i], nums[left], nums[right]])
                # Move both pointers inward to look for new pairs
                left += 1
                right -= 1
                
                # Skip duplicate elements on the left to avoid duplicate triplets
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                # Skip duplicate elements on the right to avoid duplicate triplets
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
            # If the sum is less than the target, move the left pointer to increase the sum
            elif sum < target:
                left += 1
            # If the sum is greater than the target, move the right pointer to decrease the sum
            else:
                right -= 1
    # Return the list of unique triplets that sum to the target
    return result

# Main method
if __name__ == "__main__":
    # Read the number of elements in the array
    n = int(input())
    nums = [int(x) for x in input().split()]
    
    # Read the target sum
    target = int(input())
    
    # Call the twoPointer method to find the triplets and store the result
    result = twoPointer(nums, target)
    
    # Check if any triplets were found and print the result
    if len(result) == 0:
        print("No triplets found.")
    else:
        for triplet in result:
            print(triplet)

