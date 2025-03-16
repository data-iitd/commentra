def binPrint(x, bits):
    for i in range(bits - 1, -1, -1):
        print(1 if x & (1 << i) else 0, end='')
    print()

def main():
    a, b = map(int, input().split())  # Read two unsigned integers from standard input

    binPrint(a & b, 32)  # Print the binary AND of a and b
    binPrint(a | b, 32)  # Print the binary OR of a and b
    binPrint(a ^ b, 32)  # Print the binary XOR of a and b

if __name__ == "__main__":
    main()

