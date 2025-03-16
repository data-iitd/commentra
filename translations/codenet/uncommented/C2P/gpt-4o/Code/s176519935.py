class MaxHeap:
    def __init__(self):
        self.heap = []
    
    def push(self, x):
        self.heap.append(x)
        i = len(self.heap) - 1
        while i > 0:
            p = (i - 1) // 2
            if self.heap[p] >= x:
                break
            self.heap[i] = self.heap[p]
            i = p
        self.heap[i] = x
    
    def pop(self):
        ret = self.heap[0]
        x = self.heap.pop()  # Remove the last element
        if not self.heap:  # If the heap is now empty
            return ret
        i = 0
        while i * 2 + 1 < len(self.heap):
            a = i * 2 + 1
            b = i * 2 + 2
            if b < len(self.heap) and self.heap[b] > self.heap[a]:
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
    
    max_heap = MaxHeap()
    for value in a:
        max_heap.push(value)
    
    for _ in range(m):
        tm = max_heap.pop()
        tm //= 2
        max_heap.push(tm)
    
    ans = sum(max_heap.heap)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
