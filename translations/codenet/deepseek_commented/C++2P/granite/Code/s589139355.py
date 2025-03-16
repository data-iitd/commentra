
a = int(input())
taro = []
hana = []
t = 0
h = 0

for i in range(a):
    taro.append(input())
    hana.append(input())
    lt = len(taro[i])
    lh = len(hana[i])
    l = max(lt, lh)
    if taro[i] > hana[i]:
        t = t + 3
    elif hana[i] > taro[i]:
        h = h + 3
    else:
        h = h + 1
        t = t + 1

print(t, h)

