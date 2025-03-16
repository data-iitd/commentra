def print_matrix(matrix):
    for row in matrix:
        for elem in row:
            print(f"{elem:4}", end="")
        print()

def generate_magic_square(n):
    if n % 2 == 0:
        raise ValueError("Magic square only works with odd numbers")
    
    matrix = [[0] * n for _ in range(n)]
    num = 1
    i, j = 0, n // 2

    while num <= n * n:
        matrix[i][j] = num
        num += 1
        new_i, new_j = (i - 1) % n, (j + 1) % n
        if matrix[new_i][new_j]:
            i += 1
        else:
            i, j = new_i, new_j

    return matrix

while True:
    try:
        n = int(input("Enter the size of the square matrix: "))
        if n == 0:
            break
        matrix = generate_magic_square(n)
        print_matrix(matrix)
    except ValueError as e:
        print(e)

print("<END-OF-CODE>")