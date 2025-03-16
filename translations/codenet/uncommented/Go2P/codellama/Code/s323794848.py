
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
            ops.append(('r', None))
        else:
            f, c = sys.stdin.readline().strip().split()
            if f == '1':
                ops.append(('f', c))
            else:
                ops.append(('b', c))
    sum = [0] * (Q + 1)
    for i in range(Q - 1, -1, -1):
        if ops[i][0] == 'r':
            sum[i - 1] = sum[i] + 1
        else:
            sum[i - 1] = sum[i]
    if sum[0] % 2 == 1:
        S = rev(S)
    deq = []
    for i in range(Q):
        if ops[i][0] != 'r':
            if ops[i][0] == 'f':
                if sum[i] % 2 == 1:
                    deq.append(ops[i][1])
                else:
                    deq.insert(0, ops[i][1])
            else:
                if sum[i] % 2 == 1:
                    deq.insert(0, ops[i][1])
                else:
                    deq.append(ops[i][1])
    print(''.join(deq) + S + ''.join(reversed(deq)))


