
c = input()
ans = ''
for i in c:
    if i!= 'B':
        ans += i
    else:
        ans = ans[:-1]
print(ans)

