class PNCounter:
    """
    PN-Counter (Positive-Negative Counter) is a state-based CRDT (Conflict-free Replicated Data Type)
    designed for tracking counts with both increments and decrements in a distributed and concurrent environment.
    It combines two G-Counters, one for increments (P) and one for decrements (N).
    The total count is obtained by subtracting the value of the decrement counter from the increment counter.
    This implementation supports incrementing, decrementing, querying the total count,
    comparing with other PN-Counters, and merging with another PN-Counter
    to compute the element-wise maximum for both increment and decrement counters.
    (https://en.wikipedia.org/wiki/Conflict-free_replicated_data_type)
    """

    def __init__(self, my_id, n):
        """
        Constructs a PN-Counter for a cluster of n nodes.

        :param my_id: The identifier of the current node.
        :param n: The number of nodes in the cluster.
        """
        self.my_id = my_id
        self.n = n
        self.p_counter = {i: 0 for i in range(n)}
        self.n_counter = {i: 0 for i in range(n)}

    def increment(self):
        """Increments the increment counter for the current node."""
        self.p_counter[self.my_id] += 1

    def decrement(self):
        """Increments the decrement counter for the current node."""
        self.n_counter[self.my_id] += 1

    def value(self):
        """
        Gets the total value of the counter by subtracting the decrement counter from the increment counter.

        :return: The total value of the counter.
        """
        sum_p = sum(self.p_counter.values())
        sum_n = sum(self.n_counter.values())
        return sum_p - sum_n

    def merge(self, other):
        """
        Merges the state of this PN-Counter with another PN-Counter.

        :param other: The other PN-Counter to merge with.
        """
        if self.n != other.n:
            raise ValueError("Cannot merge PN-Counters with different number of nodes")
        for i in range(self.n):
            self.p_counter[i] = max(self.p_counter[i], other.p_counter[i])
            self.n_counter[i] = max(self.n_counter[i], other.n_counter[i])


if __name__ == "__main__":
    import sys

    my_id = int(input())
    total_nodes = int(input())
    pn_counter = PNCounter(my_id, total_nodes)

    operations = int(input())
    for _ in range(operations):
        operation = input().strip()
        if operation.upper() == "INCREMENT":
            pn_counter.increment()
        elif operation.upper() == "DECREMENT":
            pn_counter.decrement()
        else:
            print(f"Invalid operation: {operation}")

    print(f"Final value of the counter: {pn_counter.value()}")

# <END-OF-CODE>
