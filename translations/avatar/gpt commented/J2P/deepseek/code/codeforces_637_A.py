import sys
from collections import Counter

def main():
    # Create a Scanner object for input and PrintWriter for output
    inp = sys.stdin.readline
    out = sys.stdout.write
    
    # Read the number of elements
    n = int(inp().strip())
    
    # Initialize an array to store the elements
    ara = [0] * n
    
    # Create a map to count the frequency of each element
    map_counter = Counter()
    
    # Read elements and populate the frequency map
    for i in range(n):
        v = int(inp().strip())
        ara[i] = v
        # If the element is not in the map, add it with a count of 1
        map_counter[v] += 1
    
    # Find the maximum frequency among the elements
    max_freq = max(map_counter.values())
    
    # Create another map to track the order of elements while checking frequency
    mm = Counter()
    
    # Iterate through the original array to find the first element with maximum frequency
    for i in range(n):
        if mm[ara[i]] == 0:
            mm[ara[i]] = 1
            # Check if the current element's frequency matches the maximum frequency
            if mm[ara[i]] == max_freq:
                out(str(ara[i]) + '\n')
                break
        else:
            # Increment the count for the existing element
            mm[ara[i]] += 1
            # Check if the current element's frequency matches the maximum frequency
            if mm[ara[i]] == max_freq:
                out(str(ara[i]) + '\n')
                break

if __name__ == "__main__":
    main()
