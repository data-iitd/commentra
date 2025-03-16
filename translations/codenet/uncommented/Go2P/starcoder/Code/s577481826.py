a, b = map(int, input().split())

ret = a + b
if ret < (a - b):
    ret = a - b
if ret < (a * b):
    ret = a * b

print(ret)

