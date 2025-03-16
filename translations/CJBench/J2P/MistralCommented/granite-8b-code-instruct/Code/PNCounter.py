

class Main:
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
        return sum(self.p_counter.values()) - sum(self.n_counter.values())

    def merge(self, other):
        if self.n!= other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        for i in range(self.n):
            self.p_counter[i] = max(self.p_counter[i], other.p_counter[i])
            self.n_counter[i] = max(self.n_counter[i], other.n_counter[i])

# Read input: my ID and total number of nodes
my_id = int(input("Enter your ID: "))
total_nodes = int(input("Enter the total number of nodes: "))

# Initialize a PN-Counter instance for the given my_id and total_nodes
pn_counter = Main(my_id, total_nodes)

# Read input: number of operations
num_operations = int(input("Enter the number of operations: "))

# Read input: operations and call corresponding methods
for _ in range(num_operations):
    operation = input("Enter operation (INCREMENT/DECREMENT): ").upper()
    if operation == "INCREMENT":
        pn_counter.increment()  # Increment the positive counter for the current node
    elif operation == "DECREMENT":
        pn_counter.decrement()  # Increment the negative counter for the current node
    else:
        print(f"Invalid operation: {operation}")

# Print the final value of the counter
print(f"Final value of the counter: {pn_counter.value()}")

