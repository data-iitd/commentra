def print_island(n, count):
    a = (n + 1) // 2
    b = n // 2
    max_count = a * a + b * b
    
    if count > max_count:
        print("NO")
        return
    
    print("YES")
    for i in range(n):
        row = []
        for j in range(n):
            if (i + j) % 2 == 0 and count > 0:
                row.append('L')
                count -= 1
            else:
                row.append('S')
        print(''.join(row))

if __name__ == "__main__":
    n = int(input())
    count = int(input())
    print_island(n, count)

# <END-OF-CODE>
