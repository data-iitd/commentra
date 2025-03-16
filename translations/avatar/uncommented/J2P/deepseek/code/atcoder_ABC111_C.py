import sys
from collections import Counter

def main():
    n = int(input().strip())
    v = list(map(int, input().strip().split()))
    
    odd_count = Counter()
    even_count = Counter()
    total_count = Counter()
    
    for i in range(n):
        total_count[v[i]] += 1
        if i % 2 == 0:
            even_count[v[i]] += 1
        else:
            odd_count[v[i]] += 1
    
    odd_count = sorted(odd_count.values(), reverse=True)
    even_count = sorted(even_count.values(), reverse=True)
    total_count = sorted(total_count.values(), reverse=True)
    
    ans = 0
    if odd_count[0] + even_count[0] == total_count[0]:
        ans = min(n - odd_count[0] - even_count[1], n - odd_count[1] - even_count[0])
    else:
        ans = n - odd_count[0] - even_count[0]
    
    print(ans)

if __name__ == "__main__":
    main()
