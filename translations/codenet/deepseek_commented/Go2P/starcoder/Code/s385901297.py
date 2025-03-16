
import sys

def main():
    ns = list(map(int, sys.stdin.readline().split()))
    ns.sort()
    if ns[0] == 1 and ns[1] == 4 and ns[2] == 7 and ns[3] == 9:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

