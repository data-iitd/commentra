

n, m = map(int, input().split())
arrs = [input() for _ in range(n)]
length = []
index = 0
returnDex = -1

for i, tmp in enumerate(arrs):
    dexG = tmp.find("G")
    dexS = tmp.find("S")

    if dexG > dexS:
        returnDex = i
        break

    length.append(dexS - dexG)

set = set()

for len in length:
    set.add(len)

if returnDex == -1:
    print(returnDex)
else:
    print(len(set))
