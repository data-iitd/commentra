
s = input()

max_tmp = 0
max = 0
for i in range(len(s)):
    flag = False
    if s[i] == "A" or s[i] == "C" or s[i] == "T" or s[i] == "G":
        max_tmp += 1
    else:
        flag = True

    if i == len(s)-1:
        flag = True
    if flag == True:
        if max < max_tmp:
            max = max_tmp
        max_tmp = 0
print(max)
