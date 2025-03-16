s = input()

for i in range(len(s)):
    if s[i] in s[i+1:]:
        print("no")
        break
else:
    print("yes")

