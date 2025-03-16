s = input()
v = [0] * 26
for c in s:
    v[ord(c) - ord('a')] += 1
ans = "Yes"
for i in range(26):
    if v[i] % 2!= 0:
        ans = "No"
        break
print(ans)

