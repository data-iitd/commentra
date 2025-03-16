import sys

class Input:
    def __init__(self):
        self.reader = sys.stdin

    def next_line(self):
        return self.reader.readline().strip()

    def next_int(self):
        return int(self.next_line())

    def next_int_array(self):
        return list(map(int, self.next_line().split()))

def main():
    input = Input()
    n = input.next_int()
    s = input.next_int_array()
    u = [False] * n
    m = f = 0

    for c in range(1, n - 1):
        f = 0
        for k in range((n - 1) // c + 1):
            u[k * c] = True
            if u[n - 1 - k * c]:
                break
            f += s[n - 1 - k * c] + s[k * c]
            if m < f:
                m = f
        for k in range((n - 1) // c + 1):
            u[k * c] = False

    print(m)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
