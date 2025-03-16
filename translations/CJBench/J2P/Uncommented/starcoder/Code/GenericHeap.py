import heapq
class Main:
    def __init__(self):
        self.data = []
        self.map = {}
    def add(self, item):
        if item == None:
            raise Exception("Cannot insert null into the heap.")
        self.data.append(item)
        self.map[item] = len(self.data) - 1
        self.upHeapify(len(self.data) - 1)
    def upHeapify(self, ci):
        pi = (ci - 1) / 2
        if ci > 0 and self.isLarger(self.data[ci], self.data[pi]) > 0:
            self.swap(pi, ci)
            self.upHeapify(pi)
    def size(self):
        return len(self.data)
    def isEmpty(self):
        return self.size() == 0
    def remove(self):
        if self.isEmpty():
            raise Exception("Heap is empty")
        self.swap(0, self.size() - 1)
        rv = self.data.pop()
        del self.map[rv]
        self.downHeapify(0)
        return rv
    def get(self):
        if self.isEmpty():
            raise Exception("Heap is empty")
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
    def main(self):
        scanner = Scanner(System.in)
        operations = scanner.nextInt()
        for i in range(operations):
            choice = scanner.nextInt()
            if choice == 1:
                element = scanner.nextInt()
                self.add(element)
                print("Added: " + str(element))
            elif choice == 2:
                try:
                    print("Removed: " + str(self.remove()))
                except Exception as e:
                    print("Heap is empty.")
            elif choice == 3:
                try:
                    print("Max element: " + str(self.get()))
                except Exception as e:
                    print("Heap is empty.")
            elif choice == 4:
                print("Heap size: " + str(self.size()))
            elif choice == 5:
                print("Heap is empty: " + str(self.isEmpty()))
            else:
                print("Invalid operation.")
        scanner.close()

