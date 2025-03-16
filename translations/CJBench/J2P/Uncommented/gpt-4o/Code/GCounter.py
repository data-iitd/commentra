class Main:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        self.counter_map = {i: 0 for i in range(n)}

    def increment(self):
        self.counter_map[self.my_id] += 1

    def value(self):
        return sum(self.counter_map.values())

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

if __name__ == "__main__":
    n = int(input())
    my_id = int(input())
    counter = Main(my_id, n)
    operations = int(input())
    for _ in range(operations):
        operation = int(input())
        if operation == 1:
            counter.increment()
        elif operation == 2:
            merge_id = int(input())
            other_counter = Main(merge_id, n)
            for j in range(n):
                other_counter.counter_map[j] = int(input())
            counter.merge(other_counter)
        else:
            print("Invalid operation.")
    print("Final counter value:", counter.value())
    print("Final counter state:", counter.get_state())

# <END-OF-CODE>
