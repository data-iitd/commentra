str1 = input()
str2 = input()

if len(str1) != len(str2):
    print("NO")
else:
    temp = str1[::-1]  # Reverse the string using slicing
    if temp == str2:
        print("YES")
    else:
        print("NO")
        
# <END-OF-CODE>
