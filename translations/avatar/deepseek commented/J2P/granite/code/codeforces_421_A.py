

n = int(input())
a = int(input())
b = int(input())

list1 = []
list2 = []

for i in range(a):
    list1.append(int(input()))

for i in range(b):
    list2.append(int(input()))

for i in range(1, n+1):
    if i in list1:
        print(1, end=" ")
    else:
        print(2, end=" ")

