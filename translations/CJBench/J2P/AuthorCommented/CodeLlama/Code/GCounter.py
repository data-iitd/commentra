
import sys

class GCounter:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        self.counter_map = {}

        for i in range(n):
            self.counter_map[i] = 0

    def increment(self):
        self.counter_map[self.my_id] += 1

    def value(self):
        sum = 0
        for v in self.counter_map.values():
            sum += v
        return sum

    def compare(self, other):
        for i in range(self.n):
            if self.counter_map[i] > other.counter_map[i]:
                return False
        return True

    def merge(self, other):
        for i in range(self.n):
            self.counter_map[i] = max(self.counter_map[i], other.counter_map[i])

    def get_state(self):
        return self.counter_map

def main():
    n = int(sys.stdin.readline())

    my_id = int(sys.stdin.readline())

    counter = GCounter(my_id, n)

    operations = int(sys.stdin.readline())

    for i in range(operations):
        operation = int(sys.stdin.readline())

        if operation == 1:
            counter.increment()
        elif operation == 2:
            merge_id = int(sys.stdin.readline())

            other_counter = GCounter(merge_id, n)
            for j in range(n):
                other_counter.counter_map[j] = int(sys.stdin.readline())
            counter.merge(other_counter)
        else:
            print("Invalid operation.")

    print("Final counter value: " + str(counter.value()))
    print("Final counter state: " + str(counter.get_state()))

if __name__ == "__main__":
    main()

