s = int(input())
x = 0
d = 2
a = set()
a.add(s)

while True:
    if s % 2 == 0:
        x = s // 2
        if x in a:
            print(d)
            break
        a.add(x)
    else:
        x = 3 * s + 1
        if x in a:
            print(d)
            break
        a.add(x)
    
    s = x
    d += 1

# <END-OF-CODE>
