
# <START-OF-CODE>

a = int(input())

for i in range(a):
    taro, hana = input().split()
    lt = len(taro)
    lh = len(hana)
    if lt > lh:
        l = lt
    else:
        l = lh
    tt = 0
    hh = 0
    if taro > hana:
        t = t + 3
    elif hana > taro:
        h = h + 3
    elif hana == taro:
        h = h + 1
        t = t + 1

print(t, h)

# 