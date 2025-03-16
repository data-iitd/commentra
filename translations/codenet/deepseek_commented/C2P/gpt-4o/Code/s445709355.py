def gc():
    return input()

def in_num():
    n = 0
    c = gc()
    while c.isdigit():
        n = 10 * n + int(c)
        c = gc()
    return n

f1 = [0] * 100
f2 = [0] * 100

def calc(n):
    k = n % 10
    while n >= 10:
        n //= 10
    f1[10 * k + n] += 1
    f2[n * 10 + k] += 1

def main():
    N = in_num()
    while N:
        calc(N)
        N -= 1

    ans = 0
    for i in range(100):
        ans += f1[i] * f2[i]
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
