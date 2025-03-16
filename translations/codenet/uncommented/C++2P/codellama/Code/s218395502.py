
a, b, c = input().split()

if (100*int(a) + 10*int(b) + int(c)) % 4 == 0:
    print("YES")
else:
    print("NO")

