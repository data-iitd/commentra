

s = input()
max_tmp = 0
max = 0
flag = False

for i in range(len(s)):
    if s[i] in ["A", "C", "T", "G"]:
        max_tmp += 1
    else:
        flag = True

    if i == len(s)-1:
        flag = True

    if flag:
        if max < max_tmp:
            max = max_tmp
        max_tmp = 0
        flag = False

print(max)
