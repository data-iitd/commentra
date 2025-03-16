import sys

class Pair:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

def main():
    # Read two integers N and K from standard input
    N, K = read_int(), read_int()

    # Convert N to base K and print the length of the resulting string
    s = ten_to_n(N, K)
    print(len(s))

def ten_to_n(number, n):
    s = ""
    tmp = number
    while True:
        s = i2s(tmp % n) + s
        if tmp < n:
            break
        tmp //= n
    return s

# Utility functions
def read_int():
    return int(sys.stdin.readline().strip())

def i2s(i):
    return str(i)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
