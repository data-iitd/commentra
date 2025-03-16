def generate_magic_square(n):
    if n % 2 == 0:
        return "N must be odd"

    magic_square = [[0] * n for _ in range(n)]

    num = 1
    i, j = 0, n // 2

    while num <= n**2:
        magic_square[i][j] = num
        num += 1
        newi, newj = (i - 1) % n, (j + 1) % n
        if magic_square[newi][newj]:
            i += 1
        else:
            i, j = newi, newj

    return magic_square

def print_magic_square(magic_square):
    for row in magic_square:
        for num in row:
            print(f"{num:4}", end="")
        print()

while True:
    n = int(input())
    if n == 0:
        break
    magic_square = generate_magic_square(n)
    if isinstance(magic_square, str):
        print(magic_square)
    else:
        print_magic_square(magic_square)

print("<END-OF-CODE>")