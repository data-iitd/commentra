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
    S = input().strip()
    Q = int(input().strip())
    ops = []
    for _ in range(Q):
        q = list(map(int, input().strip().split()))
        if q[0] == 1:
            ops.append((True, None))
        else:
            f, c = q[1], q[2]
            ops.append((False, f, c))

    sum_ops = [0] * (Q + 1)
    for i in range(Q - 1, -1, -1):
        if ops[i][0]:
            sum_ops[i] = sum_ops[i+1] + 1
        else:
            sum_ops[i] = sum_ops[i+1]

    if sum_ops[0] % 2 == 1:
        S = rev(S)

    deq = Deque()
    for i in range(len(S)):
        deq.push_back(S[i])

    for i in range(Q):
        if ops[i][0]:
            deq.front, deq.back = deq.back, deq.front
        else:
            f, c = ops[i][1], ops[i][2]
            if (sum_ops[i] % 2 == 1 and f == 1) or (sum_ops[i] % 2 == 0 and f == 2):
                deq.push_front(c)
            else:
                deq.push_back(c)

    result = ""
    result += ''.join(deq.front[::-1])
    result += S
    result += ''.join(deq.back)
    print(result)

if __name__ == "__main__":
    main()
