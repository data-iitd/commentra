
import decimal

N = decimal.Decimal(input())
d = decimal.Decimal(input())
x = decimal.Decimal(input())

ans = decimal.Decimal("0.0")

while N > decimal.Decimal("0.5"):
    adnum = decimal.Decimal(d + x * (N - decimal.Decimal("0.5")))
    ans = ans + adnum
    d = (N + decimal.Decimal("1.0")) * d / N + (decimal.Decimal("5.0") * x) / (decimal.Decimal("2.0") * N)
    x = (decimal.Decimal("1.0") + (decimal.Decimal("2.0") / N)) * x
    N = N - decimal.Decimal("1.0")

print(ans)

