import sys
from collections import Counter

def main():
    n = int(input().strip())
    v = list(map(int, input().strip().split()))
    
    vo = [0] * 100010
    ve = [0] * 100010
    vt = [0] * 100010
    
    for i in range(n):
        vt[v[i]] += 1
        if i % 2 == 0:
            ve[v[i]] += 1
        else:
            vo[v[i]] += 1
            
    vo_sorted = sorted(vo, reverse=True)
    ve_sorted = sorted(ve, reverse=True)
    vt_sorted = sorted(vt, reverse=True)
    
    ans = 0
    if vo_sorted[0] + ve_sorted[0] == vt_sorted[0]:
        ans = min(n - vo_sorted[0] - ve_sorted[1], n - vo_sorted[1] - ve_sorted[0])
    else:
        ans = n - vo_sorted[0] - ve_sorted[0]
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
