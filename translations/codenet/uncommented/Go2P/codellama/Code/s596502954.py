
import sys

def main():
    # read input
    a, b, c = map(int, sys.stdin.readline().split())

    # write output
    if a + b >= c:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

