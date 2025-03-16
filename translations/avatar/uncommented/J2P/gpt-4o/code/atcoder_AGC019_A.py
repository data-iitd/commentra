def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    Q = int(data[0])
    H = int(data[1])
    S = int(data[2])
    D = int(data[3])
    N = int(data[4])
    
    one_price = min(min(Q * 4, H * 2), S)
    
    if one_price <= D / 2:
        print(N * one_price)
    else:
        print((N // 2) * D + (N % 2) * one_price)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
