import sys
from collections import defaultdict
import heapq

# Define a constant for the maximum number of elements
NUM = int(1e5 + 2)

def main():
    # Create a Scanner object for input
    # In Python, we use sys.stdin for input
    # Read the number of elements
    N = int(sys.stdin.readline().strip())
    
    # Initialize a defaultdict to store the index of each number
    map_ = defaultdict(int)
    
    # Initialize a list to store the numbers in sorted order
    nums = []
    
    # Read N numbers from input
    for i in range(N):
        tmp = int(sys.stdin.readline().strip())  # Read the next number
        heapq.heappush(nums, tmp)  # Add the number to the priority queue
        map_[tmp] = i  # Store the index of the number in the defaultdict
    
    # Initialize variables to track the binary state and the difference count
    bin_ = 0
    diff = 0
    
    # Process the numbers in sorted order
    while nums:
        num = heapq.heappop(nums)  # Retrieve and remove the smallest number
        idx = map_[num]  # Get the original index of the number
        
        # Check if the parity of the current index and the binary state differ
        if (bin_ % 2) != (idx % 2):
            diff += 1  # Increment the difference count if they differ
        
        # Update the binary state
        bin_ += 1
        bin_ %= 2  # Toggle between 0 and 1
    
    # Calculate the final answer as half of the difference count
    ans = diff // 2
    
    # Output the result
    print(ans)

if __name__ == "__main__":
    main()
