

import sys

# Define a function to parse inputs from standard input for programming contests
def parse_inputs():
    inputs = []
    for line in sys.stdin:
        inputs.append(line.strip())
    return inputs

# Define a function to flush buffer and write to standard output
def flush_output(output):
    sys.stdout.write(output)
    sys.stdout.flush()

# Define a function to print a single value to standard output
def print_single_value(value):
    flush_output(str(value) + '\n')

# Define a function to print an array of integers in a single line
def print_array(array):
    flush_output(' '.join(map(str, array)))

# Define a function to log single value to standard error (contest server ignores this so you don't have to remove when finishing)
def log(name, value):
    sys.stderr.write(name + '=' + str(value) + '\n')

# Define a function to log formatted output to standard error (contest server ignores this so you don't have to remove when finishing)
def log_f(format, *args):
    sys.stderr.write(format % args + '\n')

# Define a function to calculate the minimum of two integers
def int_min(a, b):
    return min(a, b)

# Define a function to calculate the maximum of two integers
def int_max(a, b):
    return max(a, b)

# Define a function to calculate the absolute value
def abs(a):
    return abs(a)

# Define a function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    while b!= 0:
        a, b = b, a % b
    return a

# Define a function to calculate power of 2 modulo a given number
def power2mod(n, mod):
    res, x = 1, 2
    for _ in range(n):
        if n & 1 == 1:
            res = res * x % mod
        x = x * x % mod
    return res

# Define a function to calculate power of 2 with modulo magic
def power2(n):
    return power2mod(n, magic)

# Define a function to calculate the factorial of a number modulo a given number
def factorialMod(n, mod):
    res, i = 1, 1
    for i in range(1, n + 1):
        res = res * i % mod
    return res

# Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

# Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res
}

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
    return res
}

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
	return res

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
	return res
}

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
	return res
}

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
	return res
}

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):
    res := 1
    for i := 0; i < n; i++ {
        res = res * a % mod
	return res
}

// Define a function to calculate the inverse of a number
def inverseMod(a, mod):
    res := 1
	return res
}

// Define a function to calculate the inverse of a number modulo a given number
def inverseMod(a, mod):