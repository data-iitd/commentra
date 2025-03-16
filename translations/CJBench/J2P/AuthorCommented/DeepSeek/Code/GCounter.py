class GCounter:
    def __init__(self, my_id, n):
        self.counter_map = {i: 0 for i in range(n)}
        self.my_id = my_id
        self.n = n

    def increment(self):
        self.counter_map[self.my_id] += 1

    def value(self):
        return sum(self.counter_map.values())

    def compare(self, other):
        return all(self.counter_map[i] <= other.counter_map[i] for i in range(self.n))

    def merge(self, other):
        for i in range(self.n):
            self.counter_map[i] = max(self.counter_map[i], other.counter_map[i])

    def get_state(self):
        return self.counter_map


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    n = int(data[index])
    index += 1
    my_id = int(data[index])
    index += 1
    counter = GCounter(my_id, n)
    operations = int(data[index])
    index += 1

    for _ in range(operations):
        operation = int(data[index])
        index += 1

        if operation == 1:
            counter.increment()
        elif operation == 2:
            merge_id = int(data[index])
            index += 1
            other_counter = GCounter(merge_id, n)
            for i in range(n):
                other_counter.counter_map[i] = int(data[index])
                index += 1
            counter.merge(other_counter)
        else:
            print("Invalid operation.")

    print("Final counter value:", counter.value())
    print("Final counter state:", counter.get_state())


main()
