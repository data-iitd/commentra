def bin_print(x, bits):
    for i in range(bits - 1, -1, -1):
        print(1 if (x & (1 << i)) else 0, end='')
    print()

def main():
    a, b = map(int, input().split())

    bin_print(a & b, 32)
    bin_print(a | b, 32)
    bin_print(a ^ b, 32)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
