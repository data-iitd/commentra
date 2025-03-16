
import sys

def main():
    n = int(input()) # Read the number of elements
    ara = list(map(int, input().split())) # Read the elements and store them in a list
    map = {} # Initialize a dictionary to count occurrences of each element

    # Populate the dictionary with element counts
    for i in range(n):
        v = ara[i]
        if v not in map:
            map[v] = 1 # Initialize count for new element
        else:
            map[v] += 1 # Increment count for existing element

    max = 0 # Initialize max to track the highest frequency
    # Find the maximum frequency in the dictionary
    for i in map.values():
        max = max(max, i)

    mm = {} # Initialize a dictionary to track occurrences as elements appear
    # Find the most frequent element
    for i in range(n):
        if ara[i] not in mm:
            mm[ara[i]] = 1 # Initialize count for new element
            if mm[ara[i]] == max:
                print(ara[i]) # Print the most frequent element
                break # Exit the loop after finding the most frequent element
        else:
            mm[ara[i]] += 1 # Increment count for existing element
            if mm[ara[i]] == max:
                print(ara[i]) # Print the most frequent element
                break # Exit the loop after finding the most frequent element

if __name__ == "__main__":
    sys.exit(main())

