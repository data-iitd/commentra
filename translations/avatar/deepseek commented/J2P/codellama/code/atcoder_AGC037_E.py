import sys

def main():
    N = int(sys.stdin.readline().strip())
    K = int(sys.stdin.readline().strip())
    S = sys.stdin.readline().strip()
    firstTime = True
    step = 1

    while K > 0:
        T = S[::-1]
        revU = S + T[::-1]
        sDash = S

        for i in range(N, -1, -step):
            tmp = revU[i:i+N]
            if sDash > tmp:
                sDash = tmp
            else:
                if not firstTime:
                    break

        if firstTime:
            firstTime = False
            if 2**K > N:
                c = sDash[0]
                for i in range(N):
                    print(c, end='')
                print()
                sys.exit(0)
        else:
            step += step
        K -= 1
        S = sDash
    print(S[::-1])

if __name__ == '__main__':
    main()
