import sys

def main():
    # Read the number of elements
    n = int(input())
    # Initialize array to store elements
    ara = [0] * n
    # Initialize HashMap to count occurrences of each element
    map = {}
    # Populate the array and the map with element counts
    for i in range(n):
        v = int(input())
        ara[i] = v
        if v not in map:
            map[v] = 1
        else:
            map[v] += 1
    # Initialize max to track the highest frequency
    max = 0
    # Find the maximum frequency in the map
    for i in map.values():
        max = max if max > i else i
    # Initialize HashMap to track occurrences as elements appear
    mm = {}
    # Find the most frequent element
    for i in range(n):
        if ara[i] not in mm:
            mm[ara[i]] = 1
            if mm[ara[i]] == max:
                print(ara[i])
                break
        else:
            mm[ara[i]] += 1
            if mm[ara[i]] == max:
                print(ara[i])
                break

if __name__ == "__main__":
    main()

# 