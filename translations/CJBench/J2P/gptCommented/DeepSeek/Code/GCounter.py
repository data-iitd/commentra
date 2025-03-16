from collections import defaultdict
import sys

class Main:
    # Map to hold the count for each ID
    def __init__(self, my_id, n):
        self.counter_map = defaultdict(int)
        # Initialize the counter for each ID to zero
        for i in range(n):
            self.counter_map[i] = 0
        # Unique identifier for this instance
        self.my_id = my_id
        # Total number of IDs
        self.n = n

    # Method to increment the count for the current ID
    def increment(self):
        self.counter_map[self.my_id] += 1

    # Method to calculate the total count across all IDs
    def value(self):
        return sum(self.counter_map.values())

    # Method to compare the counts of this instance with another instance
    def compare(self, other):
        # Check if this instance's counts are less than or equal to the other instance's counts
        for i in range(self.n):
            if self.counter_map[i] > other.counter_map[i]:
                return False
        return True

    # Method to merge counts from another instance into this instance
    def merge(self, other):
        # For each ID, take the maximum count from both instances
        for i in range(self.n):
            self.counter_map[i] = max(self.counter_map[i], other.counter_map[i])

    # Method to get the current state of the counter_map
    def get_state(self):
        return dict(self.counter_map)

    # Main method to run the program
    @staticmethod
    def main():
        # Read the total number of IDs
        n = int(sys.stdin.readline().strip())
        # Read the unique ID for this instance
        my_id = int(sys.stdin.readline().strip())
        # Create a new counter instance
        counter = Main(my_id, n)
        # Read the number of operations to perform
        operations = int(sys.stdin.readline().strip())
        
        # Process each operation
        for _ in range(operations):
            operation = list(map(int, sys.stdin.readline().strip().split()))
            # Increment the count for the current ID
            if operation[0] == 1:
                counter.increment()
            # Merge counts from another instance
            elif operation[0] == 2:
                merge_id = operation[1]
                other_counter = Main(merge_id, n)
                # Read the counts for the other instance
                for j in range(n):
                    other_counter.counter_map[j] = int(sys.stdin.readline().strip())
                # Merge the other instance's counts into this instance
                counter.merge(other_counter)
            # Handle invalid operation input
            else:
                print("Invalid operation.")
        
        # Output the final total count and state of the counter
        print("Final counter value:", counter.value())
        print("Final counter state:", counter.get_state())

Main.main()
