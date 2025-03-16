
import sys

def main():
    str = sys.stdin.readline().split()
    st = sys.stdin.readline().split()
    a = int(st[0])
    b = int(st[1])
    u = sys.stdin.readline()
    print(u.strip() == str[0], (a - 1), b) if u.strip() == str[0] else print(a, (b - 1))

if __name__ == "__main__":
    main()

