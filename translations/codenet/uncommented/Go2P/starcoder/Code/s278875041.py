a = input()
b = a.replace("1", "0", -1)
c = b.replace("9", "1", -1)
d = c.replace("0", "9", -1)
print(d)

