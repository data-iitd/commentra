
s = input()
flag = 0
for i in range(len(s)):
    if i % 2 == 0:
        if s[i] not in ['R', 'U', 'D']:
            flag = 1
            break
    else:
        if s[i] not in ['L', 'U', 'D']:
            flag = 1
            break
if flag == 0:
    print("Yes")
else:
    print("No")
