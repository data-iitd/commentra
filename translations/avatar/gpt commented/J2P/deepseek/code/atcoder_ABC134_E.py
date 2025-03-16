import sys
from collections import defaultdict

def main():
    # Read the number of integers to process
    n = int(sys.stdin.readline().strip())
    
    # Initialize a defaultdict to store integers and their counts
    map = defaultdict(int)
    
    # Process each integer input
    for _ in range(n):
        # Read the next integer
        num = int(sys.stdin.readline().strip())
        
        # Check if there is no lower key in the map
        if num not in map:
            # If no lower key exists, increment the count for the current number
            map[num] += 1
        else:
            # If there is a lower key, get that key and its count
            keys = sorted(map.keys())
            for key in keys:
                if key < num:
                    lower_key = key
                else:
                    break
            
            # Increment the count for the current number
            map[num] += 1
            
            # If the count of the lower key is 1, remove it from the map
            if map[lower_key] == 1:
                del map[lower_key]
            else:
                # Otherwise, decrement the count of the lower key
                map[lower_key] -= 1
    
    # Initialize a variable to hold the final answer
    ans = sum(map.values())
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()
