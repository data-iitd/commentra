
class Main:
    def __init__(self):
        self.data = []
        self.map = {}

    def add(self, item):
        if item is None:
            raise ValueError("Cannot insert null into the heap.")
        self.data.append(item)
        self.map[item] = len(self.data) - 1
        self.upHeapify(len(self.data) - 1)

    def upHeapify(self, ci):
        pi = (ci - 1) // 2
        if ci > 0 and self.isLarger(self.data[ci], self.data[pi]) > 0:
            self.swap(pi, ci)
            self.upHeapify(pi)

    def size(self):
        return len(self.data)

    def isEmpty(self):
        return self.size() == 0

    def remove(self):
        if self.isEmpty():
            raise ValueError("Heap is empty")
        self.swap(0, len(self.data) - 1)
        rv = self.data.pop()
        del self.map[rv]
        self.downHeapify(0)
        return rv

    def downHeapify(self, pi):
        lci = 2 * pi + 1
        rci = 2 * pi + 2
        maxi = pi
        if lci < len(self.data) and self.isLarger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci
        if rci < len(self.data) and self.isLarger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci
        if maxi!= pi:
            self.swap(pi, maxi)
            self.downHeapify(maxi)

    def get(self):
        if self.isEmpty():
            raise ValueError("Heap is empty")
        return self.data[0]

    def isLarger(self, t, o):
        return 1 if t > o else -1 if t < o else 0

    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        self.data[i] = jth
        self.data[j] = ith
        self.map[ith] = j
        self.map[jth] = i

if __name__ == "__main__":
    import sys
    operations = int(input())
    heap = Main()
    for _ in range(operations):
        choice = int(input())
        if choice == 1:
            element = int(input())
            heap.add(element)
            print("Added:", element)
        elif choice == 2:
            try:
                print("Removed:", heap.remove())
            except ValueError as e:
                print("Heap is empty.")
        elif choice == 3:
            try:
                print("Max element:", heap.get())
            except ValueError as e:
                print("Heap is empty.")
        elif choice == 4:
            print("Heap size:", heap.size())
        elif choice == 5:
            print("Heap is empty:", heap.isEmpty())
        else:
            print("Invalid operation.")

