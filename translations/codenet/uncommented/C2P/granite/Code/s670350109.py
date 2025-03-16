
str1 = input()
str2 = input()
temp = ""
if len(str1)!= len(str2):
    print("NO")
else:
    for i in range(len(str1)-1, -1, -1):
        temp += str1[i]
    t = 0
    for i in range(len(temp)):
        if temp[i] == str2[i]:
            t += 1
    if len(str2) == t:
        print("YES")
    else:
        print("NO")

