import sys

def print_island(n, count):
    a = (n + 1) // 2
    b = n // 2
    max_val = a * a + b * b
    if count > max_val:
        print("NO")
        return
    print("YES")
    for i in range(n):
        s = ""
        for j in range(n):
            if (i + j) % 2 == 0 and count > 0:
                s += 'L'
                count -= 1
            else:
                s += 'S'
        print(s)

def main():
    n = int(sys.stdin.readline().strip())
    count = int(sys.stdin.readline().strip())
    print_island(n, count)

if __name__ == "__main__":
    main()
