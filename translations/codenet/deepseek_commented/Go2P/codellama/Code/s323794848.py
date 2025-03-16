
import sys

def rev(s):
    return s[::-1]

def main():
    S = sys.stdin.readline().strip()
    Q = int(sys.stdin.readline().strip())
    ops = []
    for i in range(Q):
        q = int(sys.stdin.readline().strip())
        if q == 1:
            ops.append(('r', False))
        else:
            f, c = sys.stdin.readline().strip().split()
            ops.append((c, int(f) == 1))
    sum = [0] * (Q + 1)
    for i in range(Q - 1, -1, -1):
        if ops[i][0] == 'r':
            sum[i] = sum[i + 1] + 1
        else:
            sum[i] = sum[i + 1]
    if sum[0] % 2 == 1:
        S = rev(S)
    deq = []
    for i in range(Q):
        if ops[i][0] != 'r':
            if ops[i][1]:
                if sum[i] % 2 == 1:
                    deq.append(ops[i][0])
                else:
                    deq.insert(0, ops[i][0])
            else:
                if sum[i] % 2 == 1:
                    deq.insert(0, ops[i][0])
                else:
                    deq.append(ops[i][0])
    print(''.join(deq))
    print(S)
    print(''.join(reversed(deq)))


