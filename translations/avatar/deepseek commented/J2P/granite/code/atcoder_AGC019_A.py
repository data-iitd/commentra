
import sys

def main():
    # Reading input values
    Q, H, S, D, N = map(int, sys.stdin.read().split())

    # Calculating the minimum price for one unit
    onePrice = min(Q * 4, H * 2, S)

    # Conditional logic to determine the total cost
    if onePrice <= D // 2:
        print(N * onePrice)
    else:
        print((N // 2) * D + (N % 2) * onePrice)

if __name__ == "__main__":
    main()
