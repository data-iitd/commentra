s = input()

for i in range(len(s)):
    if s[i+1:].count(s[i]) > 0:
        print("no")
        exit(0)

print("yes")

