import sys

class Main:
    def twoPointer(self, nums, target):
        nums.sort() # Sort the array to use the two-pointer technique
        result = [] # Initialize a list to store the triplets
        for i in range(len(nums) - 2): # Iterate over the array to select the first element of the triplet
            if i > 0 and nums[i] == nums[i - 1]: # Skip duplicate values of nums[i]
                continue
            left = i + 1
            right = len(nums) - 1
            while left < right: # Continue until the two pointers meet
                sum = nums[i] + nums[left] + nums[right] # Calculate the sum of the triplet
                if sum == target: # If the sum equals the target
                    result.append([nums[i], nums[left], nums[right]]) # Add the triplet to the result list
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]: # Skip duplicates for left pointer
                        left += 1
                    while left < right and nums[right] == nums[right + 1]: # Skip duplicates for right pointer
                        right -= 1
                elif sum < target: # If the sum is less than the target
                    left += 1 # Move the left pointer to the right
                else: # If the sum is greater than the target
                    right -= 1 # Move the right pointer to the left
        return result # Return the list of triplets

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip()) # Read the size of the array
    nums = [int(sys.stdin.readline().strip()) for _ in range(n)] # Initialize the array with the given size
    target = int(sys.stdin.readline().strip()) # Read the target value
    tsp = Main() # Create an instance of the Main class
    result = tsp.twoPointer(nums, target) # Call the twoPointer method to find the triplets
    if len(result) == 0: # Check if the result list is empty
        print("No triplets found.") # Print a message if no triplets are found
    else:
        for triplet in result: # Iterate over the result list and print each triplet
            print(triplet)

