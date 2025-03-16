import random
def calculateModularExponentiation(base, exponent, mod):
    x = 1
    y = base
    while exponent > 0:
        if exponent % 2 == 1:
            x = x * y % mod
        y = y * y % mod
        exponent /= 2
    return x % mod
def calculateJacobi(a, num):
    if num <= 0 or num % 2 == 0:
        return 0
    a = a % num
    jacobi = 1
    while a != 0:
        while a % 2 == 0:
            a /= 2
            nMod8 = num % 8
            if nMod8 == 3 or nMod8 == 5:
                jacobi = -jacobi
        temp = a
        a = num
        num = temp
        if a % 4 == 3 and num % 4 == 3:
            jacobi = -jacobi
        a = a % num
    return (num == 1) * jacobi
def solovayStrassen(num, iterations):
    if num <= 1:
        return False
    if num <= 3:
        return True
    for i in range(iterations):
        r = abs(random.randint(2, num - 1))
        a = r % (num - 1) + 1
        jacobi = (num + calculateJacobi(a, num)) % num
        mod = calculateModularExponentiation(a, (num - 1) // 2, num)
        if jacobi == 0 or mod != jacobi:
            return False
    return True


