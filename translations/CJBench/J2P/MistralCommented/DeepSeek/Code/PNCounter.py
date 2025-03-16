class PN_Counter:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        self.p_counter = {i: 0 for i in range(n)}
        self.n_counter = {i: 0 for i in range(n)}

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
            raise ValueError("Cannot merge PN_Counters with different number of nodes")

        for i in range(self.n):
            self.p_counter[i] = max(self.p_counter[i], other.p_counter[i])

        for i in range(self.n):
            self.n_counter[i] = max(self.n_counter[i], other.n_counter[i])


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    my_id = int(data[0])
    total_nodes = int(data[1])
    pn_counter = PN_Counter(my_id, total_nodes)

    operations = int(data[2])

    index = 3
    for _ in range(operations):
        operation = data[index].strip()
        index += 1

        if operation == "INCREMENT":
            pn_counter.increment()
        elif operation == "DECREMENT":
            pn_counter.decrement()
        else:
            print(f"Invalid operation: {operation}")

    print("Final value of the counter:", pn_counter.value())

