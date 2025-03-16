
n = int(input())
for i in range(1, n+1):
    a = i
    if a % 3 == 0:
        print(" " + str(i))
    else:
        while a:
            if a % 10 == 3:
                print(" " + str(i))
                a = 0
            a = a // 10

