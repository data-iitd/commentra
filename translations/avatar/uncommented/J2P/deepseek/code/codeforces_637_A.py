import sys
from collections import defaultdict

def main():
    inp = sys.stdin.readline
    n = int(inp())
    ara = list(map(int, inp().split()))
    map_ = defaultdict(int)
    
    for v in ara:
        map_[v] += 1
    
    max_freq = max(map_.values())
    mm = defaultdict(int)
    
    for i, v in enumerate(ara):
        mm[v] += 1
        if mm[v] == max_freq:
            print(v)
            break

if __name__ == "__main__":
    main()
