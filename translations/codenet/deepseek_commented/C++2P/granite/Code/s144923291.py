
import sys

def main():
    h, w = map(int, input().split())
    for i in range(h):
        for j in range(w):
            t = input()
            if t == "snuke":
                print(chr(ord('A') + j) + str(i + 1))
                sys.exit()

if __name__ == "__main__":
    main()

