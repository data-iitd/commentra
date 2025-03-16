s = raw_input()
flag = 0
for i in range(len(s)):
    if i % 2 == 0:
        if s[i] == 'R' or s[i] == 'U' or s[i] == 'D':
            pass
        else:
            flag = 1
            break
    else:
        if s[i] == 'L' or s[i] == 'U' or s[i] == 'D':
            pass
        else:
            flag = 1
            break
if flag == 0:
    print "Yes"
else:
    print "No"

