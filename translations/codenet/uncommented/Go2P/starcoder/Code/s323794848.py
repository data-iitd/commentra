#!/usr/bin/env python3

import sys

class Deque:
    def __init__(self):
        self.front = []
        self.back = []

    def isEmptyFront(self):
        return len(self.front) == 0

    def isEmptyBack(self):
        return len(self.back) == 0

    def pushBack(self, v):
        self.back.append(v)

    def pushFront(self, v):
        self.front.append(v)

    def popBack(self):
        if not self.isEmptyBack():
            return self.back.pop()
        elif not self.isEmptyFront():
            return self.front.pop(0)
        else:
            return None

    def popFront(self):
        if not self.isEmptyFront():
            return self.front.pop()
        elif not self.isEmptyBack():
            return self.back.pop(0)
        else:
            return None

    def get(self, idx):
        tot = len(self.front) + len(self.back)
        if idx < tot:
            if idx < len(self.front):
                return self.front[len(self.front)-1-idx]
            else:
                return self.back[idx-len(self.front)]
        else:
            return None

def rev(s):
    r = []
    for i in range(len(s)-1, -1, -1):
        r.append(s[i])
    return ''.join(r)

def main():
    S = sys.stdin.readline().rstrip()
    Q = int(sys.stdin.readline().rstrip())
    ops = []
    for i in range(Q):
        q = int(sys.stdin.readline().rstrip())
        if q == 1:
            ops.append({'rev': True})
        else:
            f, c = sys.stdin.readline().rstrip().split()
            ops.append({'rev': False, 'front': f == '1', 'c': c})
    sum = [0] * (Q+1)
    for i in range(Q-1, 0, -1):
        if ops[i]['rev']:
            sum[i-1] = sum[i] + 1
        else:
            sum[i-1] = sum[i]
    if sum[0] % 2 == 1:
        S = rev(S)
    deq = Deque()
    for i in range(Q):
        if not ops[i]['rev']: # 反転ではない(文字列追加)
            if ops[i]['front']:
                if sum[i] % 2 == 1:
                    deq.pushBack(ops[i]['c'])
                else:
                    deq.pushFront(ops[i]['c'])
            else:
                if sum[i] % 2 == 1:
                    deq.pushFront(ops[i]['c'])
                else:
                    deq.pushBack(ops[i]['c'])
    wtr = sys.stdout
    for i in range(len(deq.front)-1, -1, -1):
        wtr.write(deq.front[i])
    wtr.write(S)
    for i in range(len(deq.back)):
        wtr.write(deq.back[i])
    wtr.write('\n')

if __name__ == '__main__':
    main()

