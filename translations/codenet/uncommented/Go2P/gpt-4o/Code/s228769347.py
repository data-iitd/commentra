import sys
import bisect

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    ll = list(map(int, data[1:n+1]))
    
    ll.sort()
    
    ans = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            # Find the first index where ll[k] >= ll[i] + ll[j]
            l = bisect.bisect_left(ll, ll[i] + ll[j], j + 1, n)
            ans += l - (j + 1)
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
