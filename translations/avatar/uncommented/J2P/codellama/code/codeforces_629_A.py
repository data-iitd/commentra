import sys

num = int(sys.stdin.readline())
counter = 0
fine = 0
arr = []

for i in range(num):
    s = sys.stdin.readline()
    arr.append(s)

for i in range(num):
    for k in range(num):
        if arr[k][i] == 'C':
            counter += 1
    fine += (counter * (counter - 1)) // 2
    counter = 0

for i in range(num):
    for k in range(num):
        if arr[i][k] == 'C':
            counter += 1
    fine += (counter * (counter - 1)) // 2
    counter = 0

print(fine)

