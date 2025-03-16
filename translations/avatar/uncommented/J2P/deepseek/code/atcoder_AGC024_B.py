import sys
from collections import defaultdict

def main():
    N = int(input().strip())
    P = list(map(lambda x: int(x) - 1, input().strip().split()))
    position_map = defaultdict(int)
    
    for i in range(N):
        position_map[P[i]] = i
    
    nglist = []
    for i in range(N - 1):
        if position_map[i] > position_map[i + 1]:
            nglist.append(i)
    
    if not nglist:
        print(0)
        return
    
    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    for i in range(len(nglist) - 1):
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)
    
    print(ans)

if __name__ == "__main__":
    main()
