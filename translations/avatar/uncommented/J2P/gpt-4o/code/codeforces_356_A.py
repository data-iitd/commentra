import sys
from sortedcontainers import SortedSet

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

def main():
    in_reader = FastReader()
    n = in_reader.next_int()
    left = SortedSet(range(n))
    answer = [0] * n
    q = in_reader.next_int()

    for _ in range(q):
        l = in_reader.next_int() - 1
        r = in_reader.next_int() - 1
        win = in_reader.next_int()

        while left and left[0] <= r:
            curr = left.bisect_left(l)
            if curr < len(left) and left[curr] <= r:
                curr_index = left[curr]
                answer[curr_index] = win
                left.remove(curr_index)
            else:
                break

        answer[win - 1] = 0
        left.add(win - 1)

    print(''.join(map(str, answer)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
