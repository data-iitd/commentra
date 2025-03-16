
import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def main():
    n = int(input())
    for _ in range(n):
        p, q = map(int, input().split())
        l = int(math.sqrt(p**2 + q**2))
        is_circle = False
        for i in range(l):
            for j in range(l):
                x = i**2 + j**2
                if x <= 1 or x >= p**2 + q**2:
                    continue
                if (i*p + j*q) % x == 0 and (i*q - j*p) % x == 0:
                    is_circle = True
                    break
            if is_circle:
                break
        print("P" if is_circle else "C")

if __name__ == "__main__":
    main()

