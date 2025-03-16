from typing import List

def mod_inverse(a: int, m: int) -> int:
    m0, x0, x1 = m, 0, 1
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

def solve_crt(remainders: List[int], moduli: List[int]) -> int:
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

def main():
    n = int(input())
    remainders = []
    moduli = []
    for _ in range(n):
        remainder, modulus = map(int, input().split())
        remainders.append(remainder)
        moduli.append(modulus)
    solution = solve_crt(remainders, moduli)
    print("Smallest positive solution:", solution)

if __name__ == "__main__":
    main()

# <END-OF-CODE>











