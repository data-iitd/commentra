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


def reverse_string(s):
    return s[::-1]


def main():
    S = input().strip()  # Read the initial string S
    Q = int(input().strip())  # Read the number of operations Q
    ops = []

    # Read each operation and populate the ops list
    for _ in range(Q):
        q = list(input().strip().split())
        if q[0] == '1':
            ops.append(Operation(rev=True))
        else:
            f = int(q[1])
            c = q[2].encode()  # Convert character to bytes
            ops.append(Operation(front=(f == 1), c=c))

    # Prepare a sum array to track the number of reversals
    sum_reversals = [0] * (Q + 1)
    for i in range(Q - 1, 0, -1):
        if ops[i].rev:
            sum_reversals[i - 1] = sum_reversals[i] + 1
        else:
            sum_reversals[i - 1] = sum_reversals[i]

    # Reverse the string S if the total number of reversals is odd
    if sum_reversals[0] % 2 == 1:
        S = reverse_string(S)

    deq = Deque()  # Initialize a deque to manage character insertions
    for i in range(Q):
        if not ops[i].rev:  # Process only non-reverse operations
            if ops[i].front:
                if sum_reversals[i] % 2 == 1:
                    deq.push_back(ops[i].c)  # Push to back if the reversal count is odd
                else:
                    deq.push_front(ops[i].c)  # Push to front if the reversal count is even
            else:
                if sum_reversals[i] % 2 == 1:
                    deq.push_front(ops[i].c)  # Push to front if the reversal count is odd
                else:
                    deq.push_back(ops[i].c)  # Push to back if the reversal count is even

    # Prepare to write the final result
    result = []

    # Output the characters in the correct order
    result.extend(reversed(deq.front))  # Print front characters in reverse order
    result.extend(S.encode())  # Print the original string S
    result.extend(deq.back)  # Print back characters in order

    print(b''.join(result).decode())  # Print the final result as a string


if __name__ == "__main__":
    main()

# <END-OF-CODE>
