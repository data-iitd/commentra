def reverse_string(s):
    return s[::-1]

str1 = input()
str2 = input()

if len(str1) != len(str2):
    print("NO")
else:
    temp = reverse_string(str1)
    if temp == str2:
        print("YES")
    else:
        print("NO")
