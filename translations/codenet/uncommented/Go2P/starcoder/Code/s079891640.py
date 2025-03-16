s = input()

for i in range(len(s)):
    if s[i+1:] and s[i] in s[i+1:]:
        print("no")
        exit(0)

print("yes")

