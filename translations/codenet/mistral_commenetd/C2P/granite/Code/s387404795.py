

str = input().split()
p = input()

slen = len(str[0] + str[0])
plen = len(p)

flag = 0
for i in range(slen - plen):
    if str[0][i:i+plen] == p:
        flag = 1

if flag: print("Yes")
else: print("No")

