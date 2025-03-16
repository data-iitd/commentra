#include<stdio.h>
#include<string.h>
str1 = input()
str2 = input()
temp = ""
i = len(str1)
t = i - 1
if len(str1) != len(str2):
    print("NO")
else:
    while str1[j] != '\0':
        temp += str1[t]
        j += 1
        t -= 1
    t = 0
    i = 0
    while temp[i] != '\0':
        if temp[i] == str2[i]:
            t += 1
        i += 1
    if len(str2) == t:
        print("YES")
    else:
        print("NO")

