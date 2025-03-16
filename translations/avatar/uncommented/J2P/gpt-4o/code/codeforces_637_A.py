import sys
from collections import defaultdict

def main():
    n = int(sys.stdin.readline().strip())
    ara = list(map(int, sys.stdin.readline().strip().split()))
    
    # Count occurrences of each number
    count_map = defaultdict(int)
    for v in ara:
        count_map[v] += 1
    
    # Find the maximum occurrence
    max_count = max(count_map.values())
    
    # Find the first number with the maximum occurrence
    seen = defaultdict(int)
    for v in ara:
        seen[v] += 1
        if seen[v] == max_count:
            print(v)
            break

if __name__ == "__main__":
    main()

# <END-OF-CODE>
