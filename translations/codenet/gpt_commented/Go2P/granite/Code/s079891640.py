
s = input()
for i in range(len(s)):
    if s[i+1:].find(s[i])!= -1:
        print("no")
        exit(0)
print("yes")
