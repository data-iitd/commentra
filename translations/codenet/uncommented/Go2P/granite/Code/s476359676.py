
import sys

def main():
    n = int(input())

    ans = 0
    a_prev = 0
    for i in range(n):
        a = int(input())
        if a > i or a > a_prev + 1:
            print(-1)
            sys.exit()
        elif a == a_prev + 1:
            ans += 1
        else:
            ans += a
        a_prev = a
    print(ans)

