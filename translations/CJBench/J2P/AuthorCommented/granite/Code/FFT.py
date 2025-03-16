
import cmath

def fft(x, inverse=False):
    n = len(x)
    log2n = int(math.log(n, 2))
    bit_reversal(x, log2n)

    direction = -1 if inverse else 1
    wlen = cmath.exp(direction * 2j * math.pi / n)

    for len in range(2, n + 1, 2):
        w = 1
        for i in range(0, n, len):
            for j in range(0, len // 2):
                u = x[i + j]
                v = w * x[i + j + len // 2]
                x[i + j] = u + v
                x[i + j + len // 2] = u - v
            w *= wlen

    if inverse:
        for i in range(n):
            x[i] /= n

    return x

def pad_to_power_of_two(x):
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(0)

def bit_reversal(x, log2n):
    for i in range(len(x)):
        reverse = int.from_bytes(i.to_bytes(4, 'big'), 'big') >> (32 - log2n)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

if __name__ == "__main__":
    n = int(input())
    x = []
    for _ in range(n):
        real, img = map(float, input().split())
        x.append(complex(real, img))
    inverse = bool(int(input()))

    result = fft(x, inverse)
    print("Main Result:")
    for c in result:
        print(c.real, c.imag)

