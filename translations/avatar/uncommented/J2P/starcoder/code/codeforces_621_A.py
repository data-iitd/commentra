
# <START-OF-CODE>
n = int(input())
list = []
for i in range(n):
    list.append(int(input()))
odd = []
sum = 0
for i in list:
    if i % 2 == 0:
        sum += i
    else:
        odd.append(i)
odd.sort()
for i in odd:
    sum += i
if len(odd) % 2!= 0:
    sum -= odd[0]
print(sum)
# 