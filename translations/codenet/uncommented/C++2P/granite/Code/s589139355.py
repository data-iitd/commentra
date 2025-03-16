
a = int(input())
taro = []
hana = []
for i in range(a):
    taro.append(input())
    hana.append(input())
t = 0
h = 0
for i in range(a):
    if len(taro[i]) > len(hana[i]):
        l = len(taro[i])
    else:
        l = len(hana[i])
    if taro[i] > hana[i]:
        t += 3
    elif hana[i] > taro[i]:
        h += 3
    else:
        t += 1
        h += 1
print(t, h)
