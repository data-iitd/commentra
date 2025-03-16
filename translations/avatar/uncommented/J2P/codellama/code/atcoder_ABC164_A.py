import sys

scList = []
for i in range(0, 1000000000):
    try:
        scList.append(sys.stdin.readline().strip())
    except:
        break

numlist = scList[0].split(" ")
Sheep = int(numlist[0])
Wolve = int(numlist[1])

if Wolve >= Sheep:
    print("unsafe")
else:
    print("safe")

