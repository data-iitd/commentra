n = int(input())
a = int(input())
b = int(input())

list1 = []
list2 = []

for _ in range(a):
    list1.append(int(input()))

for _ in range(b):
    list2.append(int(input()))

for i in range(n):
    if (i + 1) in list1:
        print(1, end=" ")
    else:
        print(2, end=" ")

# <END-OF-CODE>
