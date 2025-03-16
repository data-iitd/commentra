
c = input()
ans = ""
for i in range(len(c)):
    if c[i]!= 'B':
        ans += c[i]
    else:
        ans = ans[:-1]
print(ans)

