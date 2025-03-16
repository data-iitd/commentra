def digit(n):
    res = 0
    while n > 0:
        res += 1
        n //= 10
    return res

def run():
    n = int(input())
    min_digits = digit(n)
    i = 1
    while i * i <= n:
        if n % i != 0:
            i += 1
            continue
        a = i
        b = n // i
        min_digits = min(min_digits, max(digit(a), digit(b)))
        i += 1
    print(min_digits)

if __name__ == "__main__":
    run()

# <END-OF-CODE>
