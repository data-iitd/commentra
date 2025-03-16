
import sys

def main():
    x = int(input())
    t = int(input())
    a = int(input())
    b = int(input())
    da = int(input())
    db = int(input())
    ok = False
    for i in range(t):
        first = a - (da * i)
        for j in range(t):
            second = b - (db * j)
            if second + first == x or second == x or first == x or x == 0:
                ok = True
                break
    if ok:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# 