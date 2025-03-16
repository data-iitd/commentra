def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def upll(a):
    return a

def downll(a):
    return -a

def sortup(arr):
    arr.sort()

def sortdown(arr):
    arr.sort(reverse=True)

def modpow(a, n, mod):
    ans = 1
    while n > 0:
        if n & 1:
            ans = ans * a % mod
        a = a * a % mod
        n //= 2
    return ans

def modinv(a, mod):
    return modpow(a, mod - 2, mod)

def max(a, b):
    return b if a < b else a

def min(a, b):
    return a if a < b else b

def chmax(a, b):
    if a[0] < b:
        a[0] = b

def chmin(a, b):
    if a[0] > b:
        a[0] = b

def main():
    n = int(input())
    sum_digits = 0
    m = n
    for _ in range(9):
        sum_digits += n % 10
        n //= 10
    if m % sum_digits == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
