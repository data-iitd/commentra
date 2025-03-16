class MaxHeap:
    def __init__(self):
        self.heap = []

    def push(self, x):
        self.heap.append(x)
        self._bubble_up(len(self.heap) - 1)

    def pop(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        last = self.heap.pop()
        self.heap[0] = last
        self._bubble_down(0)
        return root

    def _bubble_up(self, i):
        while i > 0:
            parent = (i - 1) // 2
            if self.heap[parent] >= self.heap[i]:
                break
            self.heap[i], self.heap[parent] = self.heap[parent], self.heap[i]
            i = parent

    def _bubble_down(self, i):
        n = len(self.heap)
        while 2 * i + 1 < n:
            left_child = 2 * i + 1
            right_child = 2 * i + 2
            if right_child < n and self.heap[right_child] > self.heap[left_child]:
                left_child = right_child
            if self.heap[left_child] <= self.heap[i]:
                break
            self.heap[i], self.heap[left_child] = self.heap[left_child], self.heap[i]
            i = left_child


def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    heap = MaxHeap()
    for x in a:
        heap.push(x)
    for _ in range(m):
        tm = heap.pop()
        tm //= 2
        heap.push(tm)
    ans = sum(heap.heap)
    print(ans)


