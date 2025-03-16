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


def reverse(s):
    return s[::-1]


def main():
    S = input().strip()
    Q = int(input().strip())
    ops = []

    for _ in range(Q):
        query = list(input().strip().split())
        if query[0] == '1':
            ops.append({'rev': True, 'front': False, 'c': None})
        else:
            f = int(query[1])
            c = query[2]
            ops.append({'rev': False, 'front': f == 1, 'c': c})

    sum_ops = [0] * (Q + 1)
    for i in range(Q - 1, 0, -1):
        if ops[i]['rev']:
            sum_ops[i - 1] = sum_ops[i] + 1
        else:
            sum_ops[i - 1] = sum_ops[i]

    if sum_ops[0] % 2 == 1:
        S = reverse(S)

    deq = Deque()
    for i in range(Q):
        if not ops[i]['rev']:  # Not a reversal operation (string append)
            if ops[i]['front']:
                if sum_ops[i] % 2 == 1:
                    deq.push_back(ops[i]['c'])
                else:
                    deq.push_front(ops[i]['c'])
            else:
                if sum_ops[i] % 2 == 1:
                    deq.push_front(ops[i]['c'])
                else:
                    deq.push_back(ops[i]['c'])

    result = []
    result.extend(reversed(deq.front))
    result.extend(S)
    result.extend(deq.back)

    print(''.join(result))


if __name__ == "__main__":
    main()

# <END-OF-CODE>
