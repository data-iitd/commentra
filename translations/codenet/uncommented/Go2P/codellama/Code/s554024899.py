
import sys

def main():
    x = int(sys.stdin.readline().strip())
    y = int(sys.stdin.readline().strip())
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]
    for i, t in enumerate(a):
        for n in t:
            if x == n:
                xt = i
            if y == n:
                yt = i
    if xt == yt:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

