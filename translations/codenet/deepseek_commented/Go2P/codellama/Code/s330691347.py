
import sys

def out(x):
    #print(x)

def nextInt():
    return int(sys.stdin.readline())

def nextString():
    return sys.stdin.readline().strip()

def main():
    N = nextInt()
    L = nextInt()
    s = []

    for i in range(N):
        s.append(nextString())

    out(N, L, s)
    s.sort()
    out(s)

    ans = ""
    for i in range(N):
        ans = ans + s[i]
    print(ans)

main()

