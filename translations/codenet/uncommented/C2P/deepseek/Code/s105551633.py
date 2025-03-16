import sys

def digit(n):
    res = 0
    while n > 0:
        res += 1
        n //= 10
    return res

def run():
    n = int(sys.stdin.readline().strip())
    min_val = digit(n)
    for i in range(1, int(n**0.5) + 1):
        if n % i != 0:
            continue
        a = i
        b = n // i
        min_val = min(min_val, max(digit(a), digit(b)))
    print(min_val)

if __name__ == "__main__":
    run()
