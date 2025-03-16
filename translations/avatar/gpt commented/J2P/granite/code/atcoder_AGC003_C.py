
import sys
import heapq

# Define a constant for the maximum number of elements
NUM = int(1e5 + 2)

def main():
    # Read the number of elements from input
    N = int(input())
    
    # Initialize a list to store the numbers
    nums = []
    
    # Read N numbers from input
    for _ in range(N):
        num = int(input())
        nums.append(num)
    
    # Initialize variables to track the binary state and the difference count
    bin = 0
    diff = 0
    
    # Process the numbers in sorted order
    while nums:
        num = heapq.heappop(nums) # Retrieve and remove the smallest number
        idx = nums.index(num) # Get the original index of the number
        
        # Check if the parity of the current index and the binary state differ
        if (bin % 2)!= (idx % 2):
            diff += 1 # Increment the difference count if they differ
        
        # Update the binary state
        bin += 1
        bin %= 2 # Toggle between 0 and 1
    
    # Calculate the final answer as half of the difference count
    ans = diff // 2
    
    # Output the result
    print(ans)

if __name__ == "__main__":
    main()

