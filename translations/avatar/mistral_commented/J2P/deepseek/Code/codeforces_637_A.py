import sys
from collections import defaultdict

def main():
    # Reading input from stdin
    n = int(sys.stdin.readline().strip())
    ara = list(map(int, sys.stdin.readline().strip().split()))
    
    # Creating a dictionary to store the frequency of each integer
    map = defaultdict(int)
    
    # Reading elements of the array and updating the frequency in the dictionary
    for v in ara:
        map[v] += 1
    
    # Finding the maximum frequency in the dictionary
    max_freq = max(map.values())
    
    # Finding the element(s) with the maximum frequency
    mm = defaultdict(int)
    for v in ara:
        mm[v] += 1
        if mm[v] == max_freq:
            print(v)
            break

if __name__ == "__main__":
    main()

