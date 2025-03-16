
import sys

def main():
    A, B = map(int, input().split())
    mx = max(A + B, A - B, A * B)
    print(mx)

if __name__ == "__main__":
    main()

