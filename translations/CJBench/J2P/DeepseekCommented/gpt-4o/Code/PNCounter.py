class Main:
    def __init__(self, my_id, n):
        self.p_counter = {i: 0 for i in range(n)}
        self.n_counter = {i: 0 for i in range(n)}
        self.my_id = my_id
        self.n = n

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

    @staticmethod
    def main():
        import sys
        input = sys.stdin.readline
        my_id = int(input().strip())
        total_nodes = int(input().strip())
        pn_counter = Main(my_id, total_nodes)
        operations = int(input().strip())
        for _ in range(operations):
            operation = input().strip().upper()
            if operation == "INCREMENT":
                pn_counter.increment()
            elif operation == "DECREMENT":
                pn_counter.decrement()
            else:
                print(f"Invalid operation: {operation}")
        print(f"Final value of the counter: {pn_counter.value()}")

Main.main()
