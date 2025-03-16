
import math

def digit(n):
    res = 0
    while n > 0:
        res += 1
        n //= 10
    return res

def run():
    n = int(input())
    min_digit = digit(n)
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i!= 0:
            continue
        a = i
        b = n // i
        min_digit = min(min_digit, max(digit(a), digit(b)))
    print(min_digit)

run()

