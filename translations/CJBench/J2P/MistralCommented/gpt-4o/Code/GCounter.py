class Main:
    def __init__(self, my_id, n):
        self.my_id = my_id
        self.n = n
        # Initialize a dictionary to store the counter for each process
        self.counter_map = {i: 0 for i in range(n)}

    # Increment the counter for the current process
    def increment(self):
        self.counter_map[self.my_id] += 1

    # Return the sum of all counters
    def value(self):
        return sum(self.counter_map.values())

    # Compare the counters of this process with another process
    def compare(self, other):
        for i in range(self.n):
            # If the counter for any process i is greater in this process than in the other process, return False
            if self.counter_map[i] > other.counter_map[i]:
                return False
        # If all counters are less or equal, return True
        return True

    # Merge the counters of this process with another process
    def merge(self, other):
        for i in range(self.n):
            # Update the counter for each process i with the maximum value between this process and the other process
            self.counter_map[i] = max(self.counter_map[i], other.counter_map[i])

    # Return the current state of the counters
    def get_state(self):
        return self.counter_map

# Main function to read input and run the simulation
if __name__ == "__main__":
    import sys

    # Read the total number of processes and the ID of the current process
    n = int(input())
    my_id = int(input())
    # Create a new instance of the Main class with the given parameters
    counter = Main(my_id, n)
    # Read the number of operations
    operations = int(input())
    # Iterate through all operations
    for _ in range(operations):
        operation = int(input())
        # If the operation is to increment the counter, call the increment method
        if operation == 1:
            counter.increment()
        # If the operation is to merge the counters with another process
        elif operation == 2:
            merge_id = int(input())
            other_counter = Main(merge_id, n)
            # Read the counters for the other process
            for j in range(n):
                other_counter.counter_map[j] = int(input())
            # Call the merge method with the other instance of the Main class
            counter.merge(other_counter)
        # If the operation is invalid, print an error message
        else:
            print("Invalid operation.")

    # Print the final counter value and state
    print("Final counter value:", counter.value())
    print("Final counter state:", counter.get_state())

# <END-OF-CODE>
