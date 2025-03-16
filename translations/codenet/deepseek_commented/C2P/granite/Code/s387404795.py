
str = input().split()
p = input()

tmp = str[0]
str = tmp + str[0]

slen = len(str)
plen = len(p)

flag = 0

for i in range(slen - plen):
    if str[i:i+plen] == p:
        flag = 1
        break

if flag:
    print("Yes")
else:
    print("No")

