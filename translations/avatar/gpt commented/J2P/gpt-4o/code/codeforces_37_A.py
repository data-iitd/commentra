import sys
from collections import defaultdict

def main():
    # Read the number of integers to be processed
    n = int(sys.stdin.readline().strip())
    
    # Initialize a defaultdict to store the frequency of each integer
    frequency_map = defaultdict(int)
    
    # Loop through the input integers and populate the frequency map
    for _ in range(n):
        val = int(sys.stdin.readline().strip())
        # Update the count of the integer in the map
        frequency_map[val] += 1
    
    # Initialize a variable to track the maximum frequency found
    max_frequency = max(frequency_map.values(), default=0)
    
    # Print the maximum frequency and the number of unique integers
    print(f"{max_frequency}{len(frequency_map)}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
