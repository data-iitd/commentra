import math
from functools import reduce
from collections import Counter

def C(n, m):
    if n > m:
        return 0
    res = reduce(lambda x, y: x * y, range(m - n + 1, m + 1), 1) // math.factorial(n)
    return res

def main():
    n, p = map(int, input().split())
    k0 = 0
    k1 = 0
    
    for _ in range(n):
        x = int(input())
        if x % 2 == 1:
            k1 += 1
        else:
            k0 += 1
            
    ans = 2 ** k0
    
    if p == 0:
        add = sum(C(i, k1) for i in range(0, k1 + 1, 2))
        ans *= add
    else:
        add = sum(C(i, k1) for i in range(1, k1 + 1, 2))
        ans *= add
        
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
