import math

def main():
    n = int(input())
    for _ in range(n):
        p, q = map(int, input().split())
        l = int(math.sqrt(p * p + q * q))
        isprime = True
        
        for i in range(l):
            for j in range(l):
                x = i * i + j * j
                if x <= 1 or x >= p * p + q * q:
                    continue
                if (i * p + j * q) % x == 0 and (i * q - j * p) % x == 0:
                    isprime = False
        
        print("P" if isprime else "C")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
