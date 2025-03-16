

n = int(input("Enter the number of arrays: "))
x = int(input("Enter the sum of elements in an array that should not exceed: "))

l = []

for i in range(n):
    tmpL = int(input("Enter the length of array number {}: ".format(i+1)))
    l.append(tmpL)

tmpSum = 0
rs = 0

for i, v in enumerate(l):
    tmpSum = 0
    for j in range(v):
        tmp = int(input("Enter the value of element number {} in array number {}: ".format(j+1, i+1)))
        tmpSum += tmp
    if tmpSum > x:
        break
    rs = i + 1

print("The last array index whose sum of elements is less than or equal to {} is: {}".format(x, rs))

