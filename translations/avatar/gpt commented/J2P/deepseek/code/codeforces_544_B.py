import sys

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

# Read input from stdin
def main():
    n, count = map(int, sys.stdin.readline().split())
    print_island(n, count)

if __name__ == "__main__":
    main()
