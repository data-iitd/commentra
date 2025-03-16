
# <START-OF-CODE>

def main():
    while True:
        L, an = map(int, raw_input().split())
        if L == 0:
            break
        an = [an]
        for k in range(1, 21):
            aj = an[k-1]
            a1 = [int(x) for x in str(aj)]
            a2 = [int(x) for x in str(aj)]
            for i in range(L-1, -1, -1):
                a1[i], a2[i] = a1[i]%10, a2[i]%10
            for i in range(1, L):
                for j in range(1, L):
                    if a1[j-1] < a1[j]:
                        a1[j-1], a1[j] = a1[j], a1[j-1]
                    if a2[j-1] > a2[j]:
                        a2[j-1], a2[j] = a2[j], a2[j-1]
            d = 1
            max, min = 0, 0
            for i in range(L-1, -1, -1):
                max += a1[i]*d
                min += a2[i]*d
                d *= 10
            def_ = max - min
            if def_ in an:
                print an.index(def_), def_, k-an.index(def_)
                break
            an.append(def_)
            aj = def_
        else:
            print "No solution"

if __name__ == "__main__":
    main()

# 