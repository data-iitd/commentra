
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

    def popBack(self, v):
        r = True
        if not self.isEmptyBack():
            v[0] = self.back[-1]
            self.back = self.back[:-1]
        elif not self.isEmptyFront():
            v[0] = self.front[0]
            self.front = self.front[1:]
        else:
            r = False
        return r

    def popFront(self, v):
        r = True
        if not self.isEmptyFront():
            v[0] = self.front[-1]
            self.front = self.front[:-1]
        elif not self.isEmptyBack():
            v[0] = self.back[0]
            self.back = self.back[1:]
        else:
            r = False
        return r

    def get(self, idx):
        tot = len(self.front) + len(self.back)
        v = 0
        if idx < tot:
            if idx < len(self.front):
                v = self.front[-1-idx]
            else:
                v = self.back[idx-len(self.front)]
        return v

S = input()
Q = int(input())
ops = []
for i in range(Q):
    q = int(input())
    if q == 1:
        ops.append((True, False, 0))
    else:
        f = int(input())
        c = ord(input())
        ops.append((False, f == 1, c))

sum = [0] * (Q + 1)
for i in range(Q - 1, 0, -1):
    if ops[i][0]:
        sum[i-1] = sum[i] + 1
    else:
        sum[i-1] = sum[i]

if sum[0] % 2 == 1:
    S = S[::-1]

deq = Deque()
for i in range(Q):
    if not ops[i][0]: # Not a reversal operation (string append)
        if ops[i][1]:
            if sum[i] % 2 == 1:
                deq.pushBack(ops[i][2])
            else:
                deq.pushFront(ops[i][2])
        else:
            if sum[i] % 2 == 1:
                deq.pushFront(ops[i][2])
            else:
                deq.pushBack(ops[i][2])

ans = []
for i in range(len(deq.front) - 1, -1, -1):
    ans.append(chr(deq.front[i]))
for i in range(len(S)):
    ans.append(S[i])
for i in range(len(deq.back)):
    ans.append(chr(deq.back[i]))

print(''.join(ans))

