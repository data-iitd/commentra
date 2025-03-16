class MaxHeap:
    def __init__(self):
        self.heap = []
        self.sz = 0

    def push(self, x):
        i = self.sz
        self.sz += 1
        while i > 0:
            p = (i - 1) // 2
            if self.heap[p] >= x:
                break
            self.heap[i] = self.heap[p]
            i = p
        self.heap[i] = x

    def pop(self):
        ret = self.heap[0]
        x = self.heap[self.sz - 1]
        self.sz -= 1
        i = 0
        while i * 2 + 1 < self.sz:
            a = i * 2 + 1
            b = i * 2 + 2
            if b < self.sz and self.heap[b] > self.heap[a]:
                a = b
            if self.heap[a] <= x:
                break
            self.heap[i] = self.heap[a]
            i = a
        self.heap[i] = x
        return ret

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    heap = MaxHeap()
    for i in range(n):
        heap.push(a[i])
    for i in range(m):
        tm = heap.pop()
        tm //= 2
        heap.push(tm)
    ans = sum(heap.heap[:heap.sz])
    print(ans)

# <END-OF-CODE>