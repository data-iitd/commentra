def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Reading input values
    Q = int(data[0])
    H = int(data[1])
    S = int(data[2])
    D = int(data[3])
    N = int(data[4])
    
    # Calculating the minimum price for one unit
    one_price = min(Q * 4, H * 2, S)
    
    # Conditional logic to determine the total cost
    if one_price <= D / 2:
        print(N * one_price)
    else:
        print((N // 2) * D + (N % 2) * one_price)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
