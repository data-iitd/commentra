
import sys

str = sys.stdin.readlines()

for i in range(len(str)):
    str[i] = str[i].strip()

for i in range(len(str)-1):
    for j in range(len(str[i])-1):
        if (str[i][j] == str[i][j+1] and (str[i+1][j] == str[i][j] or str[i+1][j+1] == str[i][j])) or (str[i+1][j] == str[i+1][j+1] and (str[i][j] == str[i+1][j] or str[i][j+1] == str[i+1][j])):
            print("YES")
            break
    else:
        print("NO")
        break

