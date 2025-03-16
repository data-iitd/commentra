import sys

def is_valid_input(n, a, b):
    return 1 <= n <= 10**18 and 0 <= a <= 10**18 and 0 <= b <= 10**18 and 0 < a + b <= 10**18

def calculate_k(n, a, b):
    return n // (a + b)

def remaining_part_greater_than_a(n, k, a):
    return (n - k * (a + b)) > a

def print_result(n, k, a):
    result = 0
    if remaining_part_greater_than_a(n, k, a):
        result = a * k + (n - k * (a + b)) - (n - (k * (a + b) + a))
    else:
        result = a * k + (n - k * (a + b))
    print(result)

def print_a():
    print(A)

def print_n():
    print(N)

# Reading input from stdin
n = int(sys.stdin.readline().strip())
a = int(sys.stdin.readline().strip())
b = int(sys.stdin.readline().strip())

k = 0

if is_valid_input(n, a, b):
    if a + b <= n:
        k = calculate_k(n, a, b)
        if remaining_part_greater_than_a(n, k, a):
            print_result(n, k, a)
        else:
            print_result(n, k, a)
    elif a + b > n and a <= n:
        print_a()
    else:
        print_n()

