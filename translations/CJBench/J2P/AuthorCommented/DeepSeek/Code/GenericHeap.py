class MaxHeap:
    def __init__(self):
        self.data = []
        self.map = {}

    def add(self, item):
        if item is None:
            raise ValueError("Cannot insert None into the heap.")
        self.data.append(item)
        self.map[item] = len(self.data) - 1
        self.up_heapify(len(self.data) - 1)

    def up_heapify(self, ci):
        pi = (ci - 1) // 2
        if ci > 0 and self.is_larger(self.data[ci], self.data[pi]) > 0:
            self.swap(pi, ci)
            self.up_heapify(pi)

    def size(self):
        return len(self.data)

    def is_empty(self):
        return self.size() == 0

    def remove(self):
        if self.is_empty():
            raise ValueError("Heap is empty")
        self.swap(0, self.size() - 1)
        rv = self.data.pop()
        self.map.pop(rv)
        self.down_heapify(0)
        return rv

    def down_heapify(self, pi):
        lci = 2 * pi + 1
        rci = 2 * pi + 2
        maxi = pi
        if lci < self.size() and self.is_larger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci
        if rci < self.size() and self.is_larger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci
        if maxi != pi:
            self.swap(pi, maxi)
            self.down_heapify(maxi)

    def get(self):
        if self.is_empty():
            raise ValueError("Heap is empty")
        return self.data[0]

    def is_larger(self, t, o):
        return t - o

    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        self.data[i], self.data[j] = jth, ith
        self.map[ith] = j
        self.map[jth] = i


def main():
    heap = MaxHeap()
    import sys
    input = sys.stdin.read
    data = input().split()

    i = 0
    while i < len(data):
        choice = int(data[i])
        i += 1
        if choice == 1:
            element = int(data[i])
            i += 1
            heap.add(element)
            print(f"Added: {element}")
        elif choice == 2:
            try:
                print(f"Removed: {heap.remove()}")
            except ValueError as e:
                print("Heap is empty.")
        elif choice == 3:
            try:
                print(f"Max element: {heap.get()}")
            except ValueError as e:
                print("Heap is empty.")
        elif choice == 4:
            print(f"Heap size: {heap.size()}")
        elif choice == 5:
            print(f"Heap is empty: {heap.is_empty()}")
        else:
            print("Invalid operation.")


main()
