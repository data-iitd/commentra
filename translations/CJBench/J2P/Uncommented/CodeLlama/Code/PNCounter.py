
import sys
import math

class PNCounter:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        self.p_counter = [0] * n
        self.n_counter = [0] * n

    def increment(self):
        self.p_counter[self.my_id] += 1

    def decrement(self):
        self.n_counter[self.my_id] += 1

    def value(self):
        return sum(self.p_counter) - sum(self.n_counter)

    def merge(self, other):
        if self.n != other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        for i in range(self.n):
            self.p_counter[i] = max(self.p_counter[i], other.p_counter[i])
            self.n_counter[i] = max(self.n_counter[i], other.n_counter[i])

if __name__ == "__main__":
    my_id = int(sys.stdin.readline().strip())
    n = int(sys.stdin.readline().strip())
    pn_counter = PNCounter(my_id, n)
    operations = int(sys.stdin.readline().strip())
    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        if operation == "INCREMENT":
            pn_counter.increment()
        elif operation == "DECREMENT":
            pn_counter.decrement()
        else:
            print("Invalid operation:", operation)
    print("Final value of the counter:", pn_counter.value())

