
num1 = int(input())
math = [1]*(num1+1)
sum = 0
for i in range(num1):
    a = int(input())
    sum += a
    for j in range(sum-a,0,-1):
        if math[j] == 1:
            math[j+a] = 1

num2 = int(input())
for i in range(num2):
    ans = int(input())
    if math[ans] == 1:
        print("yes")
    else:
        print("no")

