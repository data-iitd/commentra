
n = int(input())
m = int(input())
arrs = []
for i in range(n):
    arrs.append(input())
length = []
index = 0
returnDex = 0
for tmp in arrs:
    dexG = tmp.find("G")
    dexS = tmp.find("S")
    if dexG > dexS:
        returnDex = -1
    length.append(dexS - dexG)
set = set(length)
if returnDex == -1:
    print(returnDex)
else:
    print(len(set))
