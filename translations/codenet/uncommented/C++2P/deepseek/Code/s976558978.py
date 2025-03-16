def read_int():
    return int(input().strip())

def read_ints():
    return list(map(int, input().strip().split()))

def main():
    a, b = read_ints()
    if a < b:
        for _ in range(b):
            print(a, end='')
        print()
    else:
        for _ in range(a):
            print(b, end='')
        print()

if __name__ == "__main__":
    main()
