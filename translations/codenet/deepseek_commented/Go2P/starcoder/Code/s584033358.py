n, k = map(int, input().split())
print("YES" if k <= (n+n%2)/2 else "NO")

