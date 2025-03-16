import decimal

def main():
    scan = decimal.Decimal
    N = scan(input())
    d = scan(input())
    x = scan(input())
    ans = decimal.Decimal("0.0")
    
    while N > 0.5:
        adnum = d + x * (N - 0.5)
        ans += adnum
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
        x = (1.0 + (2.0 / N)) * x
        N -= 1
    
    # Set the precision for the output
    decimal.getcontext().prec = 20
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
