
n = int(input())
s1 = 0
s2 = 0
flag = 0
ans = ""
for i in range(n):
    x = int(input())
    y = int(input())
    temp1 = s1 + x
    temp2 = s2 + y
    if abs(temp1 - s2) <= 500:
        s1 += x
        ans += "A"
        continue
    if abs(temp2 - s1) <= 500:
        s2 += y
        ans += "G"
        continue
    flag = 1
    break
if flag == 1:
    print(-1)
else:
    print(ans)
