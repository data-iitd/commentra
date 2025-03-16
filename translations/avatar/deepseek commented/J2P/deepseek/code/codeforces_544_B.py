def print_island(n, count):
    a = (n + 1) // 2
    b = n // 2
    max_count = a * a + b * b

    if count > max_count:
        print("NO")
        return

    print("YES")

    for i in range(n):
        row = ""
        for j in range(n):
            if (i + j) % 2 == 0 and count > 0:
                row += 'L'
                count -= 1
            else:
                row += 'S'
        print(row)


# Reading inputs
n = int(input())
count = int(input())

# Calling the print_island function with the inputs
print_island(n, count)
