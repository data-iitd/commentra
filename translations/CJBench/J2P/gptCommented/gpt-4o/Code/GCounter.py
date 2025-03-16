class Main:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        self.counter_map = {i: 0 for i in range(n)}  # Initialize the counter for each ID to zero

    def increment(self):
        self.counter_map[self.my_id] += 1  # Increment the count for the current ID

    def value(self):
        return sum(self.counter_map.values())  # Calculate the total count across all IDs

    def compare(self, other):
        # Compare counts with another instance
        for i in range(self.n):
            if self.counter_map[i] > other.counter_map[i]:
                return False
        return True

    def merge(self, other):
        # Merge counts from another instance
        for i in range(self.n):
            self.counter_map[i] = max(self.counter_map[i], other.counter_map[i])

    def get_state(self):
        return self.counter_map  # Get the current state of the counter_map


if __name__ == "__main__":
    n = int(input())  # Read the total number of IDs
    my_id = int(input())  # Read the unique ID for this instance
    counter = Main(my_id, n)  # Create a new counter instance
    operations = int(input())  # Read the number of operations to perform

    for _ in range(operations):
        operation = int(input())  # Read the operation type
        if operation == 1:
            counter.increment()  # Increment the count for the current ID
        elif operation == 2:
            merge_id = int(input())  # Read the ID to merge
            other_counter = Main(merge_id, n)  # Create another counter instance
            for j in range(n):
                other_counter.counter_map[j] = int(input())  # Read counts for the other instance
            counter.merge(other_counter)  # Merge the other instance's counts into this instance
        else:
            print("Invalid operation.")  # Handle invalid operation input

    # Output the final total count and state of the counter
    print("Final counter value:", counter.value())
    print("Final counter state:", counter.get_state())

# <END-OF-CODE>
