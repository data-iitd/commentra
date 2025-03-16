
a = input()
ans = "Good"
for i in range(len(a)-1):
    if a[i] == a[i+1]:
        ans = "Bad"
print(ans)
