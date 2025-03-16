import sys

def get_points(n, k, l, r, s_all, s_k):
    ans = [l] * n
    s_all -= s_k + (n - k) * l
    s_k -= k * l
    
    while s_k > 0:
        idx = n - 1
        while s_k > 0 and idx >= n - k:
            ans[idx] += 1
            idx -= 1
            s_k -= 1
    
    while s_all > 0:
        idx = 0
        while s_all > 0 and idx < n - k:
            ans[idx] += 1
            idx += 1
            s_all -= 1
    
    return ans

def main():
    data = sys.stdin.readline().strip().split()
    n = int(data[0])
    k = int(data[1])
    l = int(data[2])
    r = int(data[3])
    s_all = int(data[4])
    s_k = int(data[5])
    
    ans = get_points(n, k, l, r, s_all, s_k)
    
    print(" ".join(map(str, ans)))

if __name__ == "__main__":
    main()
