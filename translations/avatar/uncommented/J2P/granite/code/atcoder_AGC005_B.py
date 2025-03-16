
import sys
import queue

def main():
    N = int(input())
    a = list(map(int, input().split()))
    leftl = [0] * N
    rightl = [0] * N
    que = queue.Queue()
    index = 0
    while index < N:
        while not que.empty() and a[que.queue[0]] > a[index]:
            ind = que.get()
            rightl[ind] = index - ind - 1
        que.put(index)
        index += 1
    while not que.empty():
        ind = que.get()
        rightl[ind] = N - ind - 1
    index = N - 1
    while index >= 0:
        while not que.empty() and a[que.queue[0]] > a[index]:
            ind = que.get()
            leftl[ind] = ind - index - 1
        que.put(index)
        index -= 1
    while not que.empty():
        ind = que.get()
        leftl[ind] = ind - index - 1
    ans = 0
    for i in range(N):
        ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
    print(ans)

if __name__ == "__main__":
    main()

