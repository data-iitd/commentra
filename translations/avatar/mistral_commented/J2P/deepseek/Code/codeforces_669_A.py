def main():
    n = int(input("Enter a number: "))
    solve(n)

def solve(n):
    print((n // 3) * 2 + (0 if n % 3 == 0 else 1))

main()
