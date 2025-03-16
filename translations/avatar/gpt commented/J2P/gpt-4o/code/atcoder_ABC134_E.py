from collections import defaultdict

def main():
    # Read the number of integers to process
    n = int(input())
    
    # Initialize a dictionary to store integers and their counts
    count_map = defaultdict(int)
    
    # Process each integer input
    for _ in range(n):
        num = int(input())
        
        # Check if there is no lower key in the map
        lower_key = max((key for key in count_map if key < num), default=None)
        
        if lower_key is None:
            # If no lower key exists, increment the count for the current number
            count_map[num] += 1
        else:
            # If there is a lower key, get that key and its count
            val = count_map[lower_key]
            
            # If the count of the lower key is 1, remove it from the map
            if val == 1:
                del count_map[lower_key]
            else:
                # Otherwise, decrement the count of the lower key
                count_map[lower_key] -= 1
            
            # Increment the count for the current number
            count_map[num] += 1
    
    # Initialize a variable to hold the final answer
    ans = sum(count_map.values())
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
