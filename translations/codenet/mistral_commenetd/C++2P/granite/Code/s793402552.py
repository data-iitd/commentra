

a, b = map(int, input().split())
bstr = str(b)
num = a * 10 ** len(bstr) + b

for i in range(1, 100101):
    if i * i == num:
        print("Yes")
        break
else:
    print("No")
