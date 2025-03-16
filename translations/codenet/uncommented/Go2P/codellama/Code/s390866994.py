
import sys

def out(x):
    print(x)

def getInt():
    return int(sys.stdin.readline())

def getString():
    return sys.stdin.readline().rstrip()

# min, max, asub, absなど基本関数
def max(a, b):
    if a > b:
        return a
    return b

def min(a, b):
    if a < b:
        return a
    return b

def asub(a, b):
    if a > b:
        return a - b
    return b - a

def abs(a):
    if a >= 0:
        return a
    return -a

def main():
    N, C, K = getInt(), getInt(), getInt()
    t = [0] * N
    for i in range(N):
        t[i] = getInt()

    t.sort()
    # out(t)
    ans = 1
    cnt = 1
    end = t[0] + K
    for i in range(1, N):
        if cnt < C and t[i] <= end:
            cnt += 1
            # out(t[i])
        else:
            # out("----")
            # out(t[i])
            cnt = 1
            end = t[i] + K
            ans += 1
    out(ans)

if __name__ == "__main__":
    main()

