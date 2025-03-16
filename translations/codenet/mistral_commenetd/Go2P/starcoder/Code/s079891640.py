
s = input()

for i in range(len(s)):
    if s[i+1:] and s[i] in s[i+1:]:
        print("no")
        break
else:
    print("yes")

# 