import sys
import heapq

def main():
    # Read the number of elements
    N = int(sys.stdin.readline().strip())
    
    # Initialize a dictionary to store value and its index
    map = {}
    
    # Initialize a priority queue to store numbers
    nums = []
    
    # Read each number, add it to the priority queue, and store its value and index in the dictionary
    for i in range(N):
        tmp = int(sys.stdin.readline().strip())
        heapq.heappush(nums, tmp)
        map[tmp] = i
    
    # Initialize variables to keep track of the current index and the count of differences
    bin = 0
    diff = 0
    
    # Loop until the priority queue is empty
    while nums:
        # Retrieve the next number and its index from the priority queue and dictionary
        num = heapq.heappop(nums)
        idx = map[num]
        
        # If the current index is not even when bin is even (or vice versa), increment the diff counter
        if (bin % 2) != (idx % 2):
            diff += 1
        
        # Update bin and take modulo 2 to keep it within 0 or 1
        bin += 1
        bin %= 2
    
    # Calculate the answer by dividing diff by 2
    ans = diff // 2
    
    # Print the result
    print(ans)

if __name__ == "__main__":
    main()
    
# <END-OF-CODE>
