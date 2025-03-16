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

        for i in range(l):
            if i < lt and i < lh:
                if taro[i] > hana[i]:
                    tt += 3
                elif hana[i] > taro[i]:
                    hh += 3
                else:
                    tt += 1
                    hh += 1
            elif i < lt:
                tt += 3
            else:
                hh += 3

        t += tt
        h += hh

    print(t, h)

main()
