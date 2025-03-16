from typing import List

class Main:
    # Method to find all unique triplets in the array that sum up to the target
    def two_pointer(self, nums: List[int], target: int) -> List[List[int]]:
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
            left, right = i + 1, len(nums) - 1
            
            # Use the two-pointer technique to find pairs that complement the current element to reach the target
            while left < right:
                # Calculate the sum of the current triplet
                sum_triplet = nums[i] + nums[left] + nums[right]
                
                # Check if the sum matches the target
                if sum_triplet == target:
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
                elif sum_triplet < target:
                    left += 1
                # If the sum is greater than the target, move the right pointer to decrease the sum
                else:
                    right -= 1
        
        # Return the list of unique triplets that sum to the target
        return result

if __name__ == "__main__":
    # Read the number of elements in the array
    n = int(input())
    nums = list(map(int, input().split()))
    
    # Read the target sum
    target = int(input())
    
    # Create an instance of the Main class to access the two_pointer method
    tsp = Main()
    
    # Call the two_pointer method to find the triplets and store the result
    result = tsp.two_pointer(nums, target)
    
    # Check if any triplets were found and print the result
    if not result:
        print("No triplets found.")
    else:
        for triplet in result:
            print(triplet)

# <END-OF-CODE>
