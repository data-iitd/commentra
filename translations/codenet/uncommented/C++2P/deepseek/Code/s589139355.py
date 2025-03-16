def main():
    a = int(input())
    t = 0
    h = 0
    for _ in range(a):
        taro, hana = input().split()
        lt = len(taro)
        lh = len(hana)
        l = max(lt, lh)
        tt = 0
        hh = 0

        for j in range(l):
            if j < lt:
                tt += ord(taro[j])
            if j < lh:
                hh += ord(hana[j])

        if tt > hh:
            t += 3
        elif hh > tt:
            h += 3
        else:
            t += 1
            h += 1

    print(t, h)

main()
