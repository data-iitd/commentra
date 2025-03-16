
import sys

def main():
    A, B, C = map(int, input().split())
    if B - A == C - B:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
