
import sys

def main():
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    if x1 == x2:
        dif = abs(y1 - y2)
        print(str(x1 + dif) + " " + str(y1) + " " + str(x1 + dif) + " " + str(y2))
    elif y1 == y2:
        dif = abs(x1 - x2)
        print(str(x1) + " " + str(y1 + dif) + " " + str(x2) + " " + str(y2 + dif))
    elif abs(x1 - x2) == abs(y1 - y2):
        print(str(x1) + " " + str(y2) + " " + str(x2) + " " + str(y1))
    else:
        print(-1)

if __name__ == "__main__":
    main()

