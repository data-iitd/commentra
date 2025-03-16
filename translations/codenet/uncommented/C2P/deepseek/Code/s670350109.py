def is_reverse_string(str1, str2):
    if len(str1) != len(str2):
        return "NO"
    
    temp = [''] * len(str1)
    for i in range(len(str1)):
        temp[i] = str1[len(str1) - 1 - i]
    
    if temp == list(str2):
        return "YES"
    else:
        return "NO"

str1 = input()
str2 = input()
result = is_reverse_string(str1, str2)
print(result)
