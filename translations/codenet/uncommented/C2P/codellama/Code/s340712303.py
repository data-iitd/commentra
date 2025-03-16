#include<stdio.h>
#define N 2000
num1 = 0
math = [0] * (N + 1)
math[0] = 1

scanf("%d", &num1)
for i in range(num1):
    a = 0
    scanf("%d", &a)
    sum = sum + a
    for j in range(sum - a, -1, -1):
        if math[j] == 1:
            math[j + a] = 1

scanf("%d", &num2)
for i in range(num2):
    ans = 0
    scanf("%d", &ans)
    if math[ans] == 1:
        print("yes")
    else:
        print("no")

# 