
str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")

if len(str1)!= len(str2):
    print("NO")
else:
    temp = str1[::-1]
    if temp == str2:
        print("YES")
    else:
        print("NO")

