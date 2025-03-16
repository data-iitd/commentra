import sys
from collections import defaultdict

def main():
    n = int(sys.stdin.readline().strip())  # Reading the number of elements in the array
    ara = list(map(int, sys.stdin.readline().strip().split()))  # Reading the elements of the array
    frequency_map = defaultdict(int)  # Creating a default dictionary to store the frequency of each integer

    # Updating the frequency in the dictionary
    for v in ara:
        frequency_map[v] += 1

    # Finding the maximum frequency
    max_frequency = max(frequency_map.values())

    # Finding the element(s) with the maximum frequency
    seen = set()  # To keep track of seen elements
    for v in ara:
        if frequency_map[v] == max_frequency and v not in seen:
            print(v)  # Print the element with maximum frequency
            seen.add(v)  # Mark this element as seen

if __name__ == "__main__":
    main()

# <END-OF-CODE>
