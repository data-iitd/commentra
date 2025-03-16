
import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def main():
    n = int(input())
    left = set(range(1, n + 1))
    answer = [0] * n
    q = int(input())
    for _ in range(q):
        l, r, win = map(int, input().split())
        while left and min(left) >= l:
            curr = min(left)
            answer[curr - 1] = win
            left.remove(curr)
        answer[win - 1] = 0
        left.add(win)
    print(*answer, sep='')

if __name__ == "__main__":
    main()

