def main():
    n = int(input())
    solve(n)

def solve(n):
    result = (n // 3) * 2 + (0 if n % 3 == 0 else 1)
    print(result)

main()

