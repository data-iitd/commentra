class Deque:
    def __init__(self):
        self.front = []
        self.back = []

    def is_empty_front(self):
        return len(self.front) == 0

    def is_empty_back(self):
        return len(self.back) == 0

    def push_back(self, v):
        self.back.append(v)

    def push_front(self, v):
        self.front.append(v)

    def pop_back(self):
        if not self.is_empty_back():
            return self.back.pop()
        elif not self.is_empty_front():
            return self.front.pop(0)
        else:
            return None

    def pop_front(self):
        if not self.is_empty_front():
            return self.front.pop()
        elif not self.is_empty_back():
            return self.back.pop(0)
        else:
            return None

    def get(self, idx):
        total = len(self.front) + len(self.back)
        if idx < total:
            if idx < len(self.front):
                return self.front[len(self.front) - 1 - idx]
            else:
                return self.back[idx - len(self.front)]
        return None


class Operation:
    def __init__(self, rev=False, front=False, c=None):
        self.rev = rev
        self.front = front
        self.c = c


def rev(s):
    return s[::-1]


def main():
    S = input().strip()
    Q = int(input().strip())
    ops = []

    for _ in range(Q):
        q = list(input().strip().split())
        if q[0] == '1':
            ops.append(Operation(rev=True))
        else:
            f = int(q[1])
            c = q[2]
            ops.append(Operation(front=(f == 1), c=c))

    sum_ops = [0] * (Q + 1)
    for i in range(Q - 1, 0, -1):
        if ops[i].rev:
            sum_ops[i - 1] = sum_ops[i] + 1
        else:
            sum_ops[i - 1] = sum_ops[i]

    if sum_ops[0] % 2 == 1:
        S = rev(S)

    deq = Deque()
    for i in range(Q):
        if not ops[i].rev:  # Not a reverse operation (adding character)
            if ops[i].front:
                if sum_ops[i] % 2 == 1:
                    deq.push_back(ops[i].c)
                else:
                    deq.push_front(ops[i].c)
            else:
                if sum_ops[i] % 2 == 1:
                    deq.push_front(ops[i].c)
                else:
                    deq.push_back(ops[i].c)

    result = []
    result.extend(reversed(deq.front))
    result.extend(S)
    result.extend(deq.back)

    print(''.join(result))


if __name__ == "__main__":
    main()

# <END-OF-CODE>
