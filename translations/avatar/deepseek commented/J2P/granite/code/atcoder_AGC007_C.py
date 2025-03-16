

import decimal

N = decimal.Decimal(input("Enter the value of N: "))
d = decimal.Decimal(input("Enter the value of d: "))
x = decimal.Decimal(input("Enter the value of x: "))

ans = decimal.Decimal(0.0)

while N > decimal.Decimal(0.5):
    adnum = decimal.Decimal(d + x * (N - decimal.Decimal(0.5)))
    ans = ans + adnum

    d = (N + decimal.Decimal(1.0)) * d / N + (decimal.Decimal(5.0) * x) / (decimal.Decimal(2.0) * N)
    x = (decimal.Decimal(1.0) + (decimal.Decimal(2.0) / N)) * x

    N = N - decimal.Decimal(1.0)

print(ans)

