
import random


def calculate_modular_exponentiation(base, exponent, mod):
    x = 1
    y = base

    while exponent > 0:
        if exponent % 2 == 1:
            x = x * y % mod
        y = y * y % mod
        exponent /= 2

    return x % mod


def calculate_jacobi(a, num):
    if num <= 0 or num % 2 == 0:
        return 0

    a = a % num
    jacobi = 1

    while a != 0:
        while a % 2 == 0:
            a /= 2
            n_mod_8 = num % 8
            if n_mod_8 == 3 or n_mod_8 == 5:
                jacobi = -jacobi

        temp = a
        a = num
        num = temp

        if a % 4 == 3 and num % 4 == 3:
            jacobi = -jacobi

        a = a % num

    return (num == 1) * jacobi


def solovay_strassen(num, iterations):
    if num <= 1:
        return False
    if num <= 3:
        return True

    for i in range(iterations):
        r = abs(random.randint(2, num - 1))
        a = r % (num - 1) + 1

        jacobi = (num + calculate_jacobi(a, num)) % num
        mod = calculate_modular_exponentiation(a, (num - 1) // 2, num)

        if jacobi == 0 or mod != jacobi:
            return False

    return True


# END-OF-CODE
