import math

def main():
    source = input()

    if len(source) > 10 or len(source) < 1:
        return -1

    max_i = int(math.pow(2, len(source) - 1))

    total_sum = 0

    for i in range(max_i):
        plus = bin(i)[2:].zfill(len(source))  # Get binary representation of i

        number = 0
        working = source

        while '1' in plus:
            idx = plus.index('1')
            total_sum += float(working[:idx + 1])
            plus = plus[idx + 1:] + '0' * (len(source) - idx - 1)  # Shift left
            working = working[idx + 1:]

        total_sum += float(working)

    print(f"{total_sum:.0f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
