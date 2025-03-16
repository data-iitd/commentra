
import sys

def check(e):
    if e is not None:
        print("error:", e)
        sys.exit(1)

def main():
    sage = sys.stdin.readline().strip()

    if sage == "1":
        print("Hello World")
    elif sage == "2":
        sum = 0
        for i in range(2):
            line = sys.stdin.readline().strip()
            num = int(line)
            sum += num
        print(sum)
    else:
        print("error: unknown sage")
        sys.exit(1)

if __name__ == "__main__":
    main()

