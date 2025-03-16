from collections import deque

def main():
    N = int(input())
    a = list(map(int, input().split()))
    leftl = [0] * N
    rightl = [0] * N
    que = deque()
    index = 0

    while index < N:
        while que and a[que[0]] > a[index]:
            ind = que.popleft()
            rightl[ind] = index - ind - 1
        que.append(index)
        index += 1

    while que:
        ind = que.popleft()
        rightl[ind] = N - ind - 1

    index = N - 1
    while index >= 0:
        while que and a[que[0]] > a[index]:
            ind = que.popleft()
            leftl[ind] = ind - index - 1
        que.append(index)
        index -= 1

    while que:
        ind = que.popleft()
        leftl[ind] = ind - index - 1

    ans = 0
    for i in range(N):
        ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
