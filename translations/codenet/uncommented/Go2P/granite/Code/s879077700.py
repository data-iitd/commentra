
a = input()
ans = "Good"
for i in range(3):
    if a[i] == a[i+1]:
        ans = "Bad"
print(ans)
