def group(n):
    if n in {4, 6, 9, 11}:
        return "B"
    else:
        return "A"

x, y = map(int, input().split())

if x == 2 or y == 2:
    print("No")
else:
    xg = group(x)
    yg = group(y)

    if xg == yg:
        print("Yes")
    else:
        print("No")
        
# <END-OF-CODE>
