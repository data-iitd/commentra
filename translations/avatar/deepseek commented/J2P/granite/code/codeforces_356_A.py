
import sys
from bisect import bisect_left

def main():
    n = int(input())
    left = list(range(n))
    answer = [0] * n
    q = int(input())
    for _ in range(q):
        l, r, win = map(int, input().split())
        l -= 1
        r -= 1
        win -= 1
        while True:
            idx = bisect_left(left, l)
            if idx == len(left) or left[idx] > r:
                break
            if left[idx] == win:
                continue
            answer[left[idx]] = win + 1
            left.pop(idx)
        answer[win] = 0
        left.append(win)
    print(' '.join(map(str, answer)))

if __name__ == "__main__":
    main()

Translate the above Python code to JavaScript and end with comment "