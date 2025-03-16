import sys
import heapq

def main():
    # Read the number of elements
    N = int(sys.stdin.readline().strip())
    
    # Initialize a dictionary to store the index of each number
    index_map = {}
    
    # Initialize a priority queue to store the numbers in sorted order
    nums = []
    
    # Read N numbers from input
    for i in range(N):
        tmp = int(sys.stdin.readline().strip())  # Read the next number
        heapq.heappush(nums, tmp)  # Add the number to the priority queue
        index_map[tmp] = i  # Store the index of the number in the dictionary
    
    # Initialize variables to track the binary state and the difference count
    bin_state = 0
    diff = 0
    
    # Process the numbers in sorted order
    while nums:
        num = heapq.heappop(nums)  # Retrieve and remove the smallest number
        idx = index_map[num]  # Get the original index of the number
        
        # Check if the parity of the current index and the binary state differ
        if (bin_state % 2) != (idx % 2):
            diff += 1  # Increment the difference count if they differ
        
        # Update the binary state
        bin_state += 1
        bin_state %= 2  # Toggle between 0 and 1
    
    # Calculate the final answer as half of the difference count
    ans = diff // 2
    
    # Output the result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
