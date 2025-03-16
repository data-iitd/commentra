from collections import defaultdict
import sys

class PN_Counter:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        self.p_counter = defaultdict(int)
        self.n_counter = defaultdict(int)
        for i in range(n):
            self.p_counter[i] = 0
            self.n_counter[i] = 0

    def increment(self):
        self.p_counter[self.my_id] += 1

    def decrement(self):
        self.n_counter[self.my_id] += 1

    def value(self):
        sum_p = sum(self.p_counter.values())
        sum_n = sum(self.n_counter.values())
        return sum_p - sum_n

    def merge(self, other):
        if self.n != other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        for i in range(self.n):
            self.p_counter[i] = max(self.p_counter[i], other.p_counter[i])
            self.n_counter[i] = max(self.n_counter[i], other.n_counter[i])

if __name__ == "__main__":
    my_id = int(sys.stdin.readline().strip())
    total_nodes = int(sys.stdin.readline().strip())
    pn_counter = PN_Counter(my_id, total_nodes)
    operations = int(sys.stdin.readline().strip())
    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        if operation.upper() == "INCREMENT":
            pn_counter.increment()
        elif operation.upper() == "DECREMENT":
            pn_counter.decrement()
        else:
            print(f"Invalid operation: {operation}")
    print(f"Final value of the counter: {pn_counter.value()}")

