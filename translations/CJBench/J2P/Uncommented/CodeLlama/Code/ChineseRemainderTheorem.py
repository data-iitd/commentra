
import sys

def solve_crt(remainders, moduli):
    product = 1
    result = 0
    for mod in moduli:
        product *= mod
    for i in range(len(moduli)):
        partial_product = product // moduli[i]
        inverse = mod_inverse(partial_product, moduli[i])
        result += remainders[i] * partial_product * inverse
    result = result % product
    if result < 0:
        result += product
    return result

def mod_inverse(a, m):
    m0 = m
    x0 = 0
    x1 = 1
    if m == 1:
        return 0
    while a > 1:
        q = a // m
        t = m
        m = a % m
        a = t
        t = x0
        x0 = x1 - q * x0
        x1 = t
    if x1 < 0:
        x1 += m0
    return x1

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    remainders = []
    moduli = []
    for i in range(n):
        remainder = int(sys.stdin.readline())
        modulus = int(sys.stdin.readline())
        remainders.append(remainder)
        moduli.append(modulus)
    solution = solve_crt(remainders, moduli)
    print("Smallest positive solution:", solution)

