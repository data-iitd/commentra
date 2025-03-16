
import sys

def main():
    for line in sys.stdin:
        an, L = map(int, line.split())
        if L == 0:
            break
        aj = an
        end = 0
        for k in range(1, 21):
            a1 = [int(d) for d in str(aj)]
            a2 = [int(d) for d in str(aj)]
            for i in range(L-1, 0, -1):
                a1[i-1], a1[i] = min(a1[i-1], a1[i]), max(a1[i-1], a1[i])
                a2[i-1], a2[i] = max(a2[i-1], a2[i]), min(a2[i-1], a2[i])
            d = 1
            max = 0
            min = 0
            for i in range(L-1, -1, -1):
                max += a1[i] * d
                min += a2[i] * d
                d *= 10
            def = max - min
            for i in range(k):
                if def == an[i]:
                    print(i, def, k-i)
                    end = 1
                    break
            if end == 1:
                break
            an.append(def)
            aj = def
        print("