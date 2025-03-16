import sys

def main():
    N = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().split()]
    leftl = [0] * N
    rightl = [0] * N
    que = []
    index = 0
    while index < N:
        while que and a[que[-1]] > a[index]:
            ind = que.pop()
            rightl[ind] = index - ind - 1
        que.append(index)
        index += 1
    while que:
        ind = que.pop()
        rightl[ind] = N - ind - 1
    index = N - 1
    while index >= 0:
        while que and a[que[-1]] > a[index]:
            ind = que.pop()
            leftl[ind] = ind - index - 1
        que.append(index)
        index -= 1
    while que:
        ind = que.pop()
        leftl[ind] = ind - index - 1
    ans = 0
    for i in range(N):
        ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
    print(ans)

if __name__ == "__main__":
    main()

