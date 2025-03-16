import sys

class Pair:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

def main():
    N, K = read_int(), read_int()
    s = ten_to_n(N, K)
    print(len(s))

def ten_to_n(number, n):
    s = ""
    tmp = number
    while True:
        s = str(tmp % n) + s
        if tmp < n:
            break
        tmp //= n
    return s

def read_int():
    return int(sys.stdin.readline().strip())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
