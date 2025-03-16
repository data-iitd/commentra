import decimal
from decimal import Decimal

def main():
    scan = input().split()
    N = Decimal(scan[0])
    d = Decimal(scan[1])
    x = Decimal(scan[2])
    ans = Decimal("0.0")
    
    while N > Decimal("0.5"):
        adnum = d + x * (N - Decimal("0.5"))
        ans += adnum
        d = (N + Decimal("1.0")) * d / N + (Decimal("5.0") * x) / (Decimal("2.0") * N)
        x = (Decimal("1.0") + (Decimal("2.0") / N)) * x
        N -= Decimal("1.0")
    
    print("{:.20f}".format(ans))

if __name__ == "__main__":
    main()
