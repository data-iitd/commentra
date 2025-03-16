import sys

def main():
    input = sys.stdin.readline
    Q = int(input())
    H = int(input())
    S = int(input())
    D = int(input())
    N = int(input())
    
    one_price = min(min(Q * 4, H * 2), S)
    if one_price <= D / 2:
        print(N * one_price)
    else:
        print((N // 2) * D + (N % 2) * one_price)

if __name__ == "__main__":
    main()
