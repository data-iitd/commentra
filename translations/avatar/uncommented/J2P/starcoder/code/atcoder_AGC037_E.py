import sys
import math

def main():
    N = int(raw_input())
    K = int(raw_input())
    S = raw_input()
    firstTime = True
    step = 1
    while K > 0:
        T = S[::-1]
        revU = S + T
        revU = revU[::-1]
        sDash = S
        for i in range(N, 0, -step):
            tmp = revU[i:i+N]
            if sDash > tmp:
                sDash = tmp
            else:
                if not firstTime:
                    break
        if firstTime:
            firstTime = False
            if math.pow(2, K) > N:
                c = sDash[0]
                for i in range(0, N):
                    sys.stdout.write(c)
                sys.stdout.write('\n')
                sys.exit(0)
        else:
            step += step
        K -= 1
        S = sDash[::-1]

if __name__ == "__main__":
    main()

