
import sys

def main():
    n = int(input())
    taro = 0
    hanako = 0
    t = []
    h = []
    for i in range(n):
        t.append(input())
        h.append(input())
        if t[i] < h[i]:
            hanako += 3
        elif t[i] > h[i]:
            taro += 3
        else:
            taro += 1
            hanako += 1
    print(taro, hanako)

if __name__ == "__main__":
    main()

