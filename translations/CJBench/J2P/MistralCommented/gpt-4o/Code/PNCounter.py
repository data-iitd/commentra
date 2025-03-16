class PNCounter:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        
        # Initialize the hash maps with zero values for all nodes
        self.p_counter = {i: 0 for i in range(n)}
        self.n_counter = {i: 0 for i in range(n)}
    
    # Increment the positive counter for the current node
    def increment(self):
        self.p_counter[self.my_id] += 1
    
    # Increment the negative counter for the current node
    def decrement(self):
        self.n_counter[self.my_id] += 1
    
    # Calculate the difference between positive and negative counters
    def value(self):
        sum_p = sum(self.p_counter.values())
        sum_n = sum(self.n_counter.values())
        
        # Return the difference between positive and negative counters
        return sum_p - sum_n
    
    # Merge the positive and negative counters of two PN-Counters
    def merge(self, other):
        if self.n != other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        
        # Merge positive counters
        for i in range(self.n):
            self.p_counter[i] = max(self.p_counter[i], other.p_counter[i])
        
        # Merge negative counters
        for i in range(self.n):
            self.n_counter[i] = max(self.n_counter[i], other.n_counter[i])

# Main function to read input and call methods
if __name__ == "__main__":
    import sys
    
    # Read input: my ID and total number of nodes
    my_id = int(sys.stdin.readline().strip())
    total_nodes = int(sys.stdin.readline().strip())
    
    # Initialize a PN-Counter instance for the given my_id and total_nodes
    pn_counter = PNCounter(my_id, total_nodes)
    
    # Read input: number of operations
    operations = int(sys.stdin.readline().strip())
    
    # Read input: operations and call corresponding methods
    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        
        if operation.upper() == "INCREMENT":
            pn_counter.increment()  # Increment the positive counter for the current node
        elif operation.upper() == "DECREMENT":
            pn_counter.decrement()  # Increment the negative counter for the current node
        else:
            print(f"Invalid operation: {operation}")
    
    # Print the final value of the counter
    print(f"Final value of the counter: {pn_counter.value()}")

# <END-OF-CODE>
