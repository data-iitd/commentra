
class Main:
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
        self.swap(0, len(self.data) - 1)
        rv = self.data.pop()
        del self.map[rv]
        self.down_heapify(0)
        return rv

    def down_heapify(self, pi):
        lci = 2 * pi + 1
        rci = 2 * pi + 2
        maxi = pi
        if lci < len(self.data) and self.is_larger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci
        if rci < len(self.data) and self.is_larger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci
        if maxi!= pi:
            self.swap(pi, maxi)
            self.down_heapify(maxi)

    def get(self):
        if self.is_empty():
            raise ValueError("Heap is empty")
        return self.data[0]

    def is_larger(self, t, o):
        return t > o

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
            print("Heap is empty:", heap.is_empty())
        else:
            print("Invalid operation.")

