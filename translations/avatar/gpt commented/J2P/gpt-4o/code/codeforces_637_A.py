import sys
from collections import defaultdict

def main():
    # Read the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Initialize a list to store the elements
    ara = list(map(int, sys.stdin.readline().strip().split()))
    
    # Create a dictionary to count the frequency of each element
    frequency_map = defaultdict(int)
    
    # Read elements and populate the frequency map
    for v in ara:
        frequency_map[v] += 1
    
    # Find the maximum frequency among the elements
    max_frequency = max(frequency_map.values())
    
    # Create another dictionary to track the order of elements while checking frequency
    order_map = {}
    
    # Iterate through the original array to find the first element with maximum frequency
    for value in ara:
        if value not in order_map:
            order_map[value] = 1
            # Check if the current element's frequency matches the maximum frequency
            if frequency_map[value] == max_frequency:
                print(value)
                break
        else:
            order_map[value] += 1
            # Check if the current element's frequency matches the maximum frequency
            if frequency_map[value] == max_frequency:
                print(value)
                break

if __name__ == "__main__":
    main()

# <END-OF-CODE>
