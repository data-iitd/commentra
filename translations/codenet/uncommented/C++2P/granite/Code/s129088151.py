
n = int(input())
T = {}
for i in range(n):
    com, str = input().split()
    if com == "insert":
        T[str] = True
    else:
        if T[str]:
            print("yes")
        else:
            print("no")

