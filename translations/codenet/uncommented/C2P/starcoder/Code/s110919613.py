
#include <stdio.h>

def main():
    while True:
        an = [0] * 20
        a1 = [0] * 6
        a2 = [0] * 6
        L = 0
        an[0], L = map(int, raw_input().split())
        if L == 0:
            break
        aj = an[0]
        end = 0
        for k in range(1, 21):
            for i in range(L-1, -1, -1):
                a1[i] = aj % 10
                a2[i] = aj % 10
            for i in range(1, L):
                for j in range(1, L):
                    if a1[j-1] < a1[j]:
                        tmp = a1[j-1]
                        a1[j-1] = a1[j]
                        a1[j] = tmp
                    if a2[j-1] > a2[j]:
                        tmp = a2[j-1]
                        a2[j-1] = a2[j]
                        a2[j] = tmp
            d = 1
            max = 0
            min = 0
            for i in range(L-1, -1, -1):
                max += (a1[i] % 10) * d
                min += (a2[i] % 10) * d
            def = max - min
            for i in range(0, k):
                if def == an[i]:
                    print i, def, k-i
                    end = 1
                    break
            if end == 1:
                break
            an[k] = def
            aj = def

if __name__ == "__main__":
    main()

