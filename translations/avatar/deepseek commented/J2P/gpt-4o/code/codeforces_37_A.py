import sys
from collections import defaultdict

def main():
    # Read the number of integers
    n = int(sys.stdin.readline().strip())
    
    # Create a defaultdict to store the frequency of each integer
    frequency_map = defaultdict(int)
    
    # Read n integers and update their counts in the frequency map
    for _ in range(n):
        val = int(sys.stdin.readline().strip())
        frequency_map[val] += 1
    
    # Initialize max to the smallest possible integer value
    max_count = float('-inf')
    
    # Iterate through the frequency map to find the maximum count
    for count in frequency_map.values():
        max_count = max(max_count, count)
    
    # Print the maximum count and the size of the frequency map
    print(f"{max_count}{len(frequency_map)}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
