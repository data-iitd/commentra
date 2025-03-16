# AtCoder.py : This file contains the main function. The program starts and ends there.

import sys
from collections import defaultdict

input = sys.stdin.read
def main():
    data = input().split()
    N = int(data[0])
    M = int(data[1])
    
    H = list(map(int, data[2:N+2]))
    G = defaultdict(list)
    
    index = N + 2
    for _ in range(M):
        u = int(data[index]) - 1
        v = int(data[index + 1]) - 1
        G[u].append(v)
        G[v].append(u)
        index += 2
    
    ans = 0
    for u in range(N):
        flag = True
        for v in G[u]:
            if H[u] <= H[v]:
                flag = False
                break
        if flag:
            ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
