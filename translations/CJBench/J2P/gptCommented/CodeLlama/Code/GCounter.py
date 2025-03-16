import sys

# Map to hold the count for each ID
counter_map = {}
# Unique identifier for this instance
my_id = int(sys.stdin.readline().strip())
# Total number of IDs
n = int(sys.stdin.readline().strip())

# Constructor to initialize the counter with a given ID and total number of IDs
def __init__(self, my_id, n):
    self.my_id = my_id
    self.n = n
    # Initialize the counter for each ID to zero
    for i in range(n):
        counter_map[i] = 0

# Method to increment the count for the current ID
def increment(self):
    counter_map[self.my_id] += 1

# Method to calculate the total count across all IDs
def value(self):
    sum = 0
    # Sum up the counts from the counterMap
    for v in counter_map.values():
        sum += v
    return sum

# Method to compare the counts of this instance with another instance
def compare(self, other):
    # Check if this instance's counts are less than or equal to the other instance's counts
    for i in range(n):
        if self.counter_map[i] > other.counter_map[i]:
            return False
    return True

# Method to merge counts from another instance into this instance
def merge(self, other):
    # For each ID, take the maximum count from both instances
    for i in range(n):
        self.counter_map[i] = max(self.counter_map[i], other.counter_map[i])

# Method to get the current state of the counterMap
def get_state(self):
    return counter_map

# Main method to run the program
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
    for i in range(operations):
        operation = int(sys.stdin.readline().strip())
        # Increment the count for the current ID
        if operation == 1:
            counter.increment()
        # Merge counts from another instance
        elif operation == 2:
            merge_id = int(sys.stdin.readline().strip())
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
    print("Final counter value: " + str(counter.value()))
    print("Final counter state: " + str(counter.get_state()))

if __name__ == "__main__":
    main()
