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
        tot = len(self.front) + len(self.back)
        if idx < tot:
            if idx < len(self.front):
                return self.front[-idx-1]
            else:
                return self.back[idx-len(self.front)]
        return None


def rev(s):
    return s[::-1]


def main():
    S = input()
    Q = int(input())
    ops = []

    for _ in range(Q):
        q = list(map(int, input().split()))
        if q[0] == 1:
            ops.append((True, None))
        else:
            ops.append((False, q[1], q[2]))

    sum_rev = [0] * (Q + 1)
    for i in range(Q - 1, 0, -1):
        if ops[i][0]:
            sum_rev[i - 1] = sum_rev[i] + 1
        else:
            sum_rev[i - 1] = sum_rev[i]

    if sum_rev[0] % 2 == 1:
        S = rev(S)

    deq = Deque()
    for i in range(Q):
        if ops[i][0]:
            for _ in range(sum_rev[i] % 2):
                if ops[i][1] == 1:
                    deq.push_back(ops[i][2])
                else:
                    deq.push_front(ops[i][2])
        else:
            if ops[i][1] == 1:
                for _ in range(sum_rev[i] % 2):
                    deq.push_front(ops[i][2])
            else:
                for _ in range(sum_rev[i] % 2):
                    deq.push_back(ops[i][2])

    result = ""
    result += ''.join(reversed(deq.front))
    result += S
    result += ''.join(deq.back)
    print(result)


