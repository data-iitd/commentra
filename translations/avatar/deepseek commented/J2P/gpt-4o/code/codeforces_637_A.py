import sys
from collections import defaultdict

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    ara = list(map(int, data[1:n+1]))  # Initialize array to store elements
    count_map = defaultdict(int)  # Dictionary to count occurrences of each element

    # Populate the array and the map with element counts
    for v in ara:
        count_map[v] += 1  # Increment count for each element

    max_count = max(count_map.values())  # Find the maximum frequency

    mm = defaultdict(int)  # Dictionary to track occurrences as elements appear
    # Find the most frequent element
    for value in ara:
        mm[value] += 1  # Increment count for existing element
        if mm[value] == max_count:
            print(value)  # Print the most frequent element
            break  # Exit the loop after finding the most frequent element

if __name__ == "__main__":
    main()

# <END-OF-CODE>
