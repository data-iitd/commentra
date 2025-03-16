import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

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
        self.swap(0, self.size() - 1)
        rv = self.data.pop()
        del self.map[rv]
        self.downHeapify(0)
        return rv

    def downHeapify(self, pi):
        lci = 2 * pi + 1
        rci = 2 * pi + 2
        maxi = pi
        if lci < self.size() and self.isLarger(self.data[lci], self.data[maxi]) > 0:
            maxi = lci
        if rci < self.size() and self.isLarger(self.data[rci], self.data[maxi]) > 0:
            maxi = rci
        if maxi!= pi:
            self.swap(pi, maxi)
            self.downHeapify(maxi)

    def get(self):
        if self.isEmpty():
            raise ValueError("Heap is empty")
        return self.data[0]

    def isLarger(self, t, o):
        return t.compareTo(o)

    def swap(self, i, j):
        ith = self.data[i]
        jth = self.data[j]
        self.data[i] = jth
        self.data[j] = ith
        self.map[ith] = j
        self.map[jth] = i

if __name__ == "__main__":
    scanner = Scanner(System.in)
    heap = Main()

    operations = scanner.nextInt()

    for i in range(operations):
        choice = scanner.nextInt()
        if choice == 1:
            element = scanner.nextInt()
            heap.add(element)
            print("Added: " + element)
        elif choice == 2:
            try:
                print("Removed: " + heap.remove())
            except ValueError as e:
                print("Heap is empty.")
        elif choice == 3:
            try:
                print("Max element: " + heap.get())
            except ValueError as e:
                print("Heap is empty.")
        elif choice == 4:
            print("Heap size: " + heap.size())
        elif choice == 5:
            print("Heap is empty: " + heap.isEmpty())
        else:
            print("Invalid operation.")
    scanner.close()

