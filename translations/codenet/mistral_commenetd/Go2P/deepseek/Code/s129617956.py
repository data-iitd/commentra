import math

def main():
    n = int(input())
    rt = int(math.sqrt(n))
    minf = 100

    for i in range(1, rt + 1):
        if n % i == 0:
            b = n // i
            ndigit = 0
            while b > 0:
                b //= 10
                ndigit += 1
            minf = min(minf, ndigit)

    print(minf)

main()
