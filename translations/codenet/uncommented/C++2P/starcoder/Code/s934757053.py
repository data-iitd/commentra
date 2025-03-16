A, B = map(int, input().split())
out = 1
ans = 0
while out < B:
    out -= A
    out += A
    ans += 1
print(ans)

