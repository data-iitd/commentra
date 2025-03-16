

a = int(input())
b = int(input())

ret = a + b
if ret < (a - b):
    ret = a - b
if ret < (a * b):
    ret = a * b

print(ret)
