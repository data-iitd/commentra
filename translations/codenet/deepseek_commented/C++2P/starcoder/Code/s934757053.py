
A, B = map(int, input().split())
out = 1
ans = 0
while out < B:
    out -= 1
    out += A
    ans += 1
print(ans)

