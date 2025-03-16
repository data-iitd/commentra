def sum_of_digits(a):
    ans = 0
    while a >= 10:
        ans += a % 10
        a //= 10
    ans += a
    return ans

def main():
    n = int(input())
    if n % 2 == 0:
        n = n // 2
    else:
        n = (n + 1) // 2

    ans = sum_of_digits(1) + sum_of_digits(n - 1)

    for A in range(1, n + 1):
        if sum_of_digits(A) + sum_of_digits(n - A) < ans:
            ans = sum_of_digits(A) + sum_of_digits(n - A)

    print(ans)

if __name__ == "__main__":
    main()
