import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main:
    # Map to hold the count for each ID
    counterMap = None
    # Unique identifier for this instance
    myId = None
    # Total number of IDs
    n = None

    # Constructor to initialize the counter with a given ID and total number of IDs
    def __init__(self, myId, n):
        self.myId = myId
        self.n = n
        self.counterMap = HashMap()
        # Initialize the counter for each ID to zero
        for i in range(n):
            self.counterMap.put(i, 0)

    # Method to increment the count for the current ID
    def increment(self):
        self.counterMap.put(self.myId, self.counterMap.get(self.myId) + 1)

    # Method to calculate the total count across all IDs
    def value(self):
        sum = 0
        # Sum up the counts from the counterMap
        for v in self.counterMap.values():
            sum += v
        return sum

    # Method to compare the counts of this instance with another instance
    def compare(self, other):
        # Check if this instance's counts are less than or equal to the other instance's counts
        for i in range(self.n):
            if self.counterMap.get(i) > other.counterMap.get(i):
                return False
        return True

    # Method to merge counts from another instance into this instance
    def merge(self, other):
        # For each ID, take the maximum count from both instances
        for i in range(self.n):
            self.counterMap.put(i, max(self.counterMap.get(i), other.counterMap.get(i)))

    # Method to get the current state of the counterMap
    def getState(self):
        return self.counterMap

    # Main method to run the program
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)
        # Read the total number of IDs
        n = scanner.nextInt()
        # Read the unique ID for this instance
        myId = scanner.nextInt()
        # Create a new counter instance
        counter = Main(myId, n)
        # Read the number of operations to perform
        operations = scanner.nextInt()
        
        # Process each operation
        for i in range(operations):
            operation = scanner.nextInt()
            # Increment the count for the current ID
            if operation == 1:
                counter.increment()
            # Merge counts from another instance
            else if operation == 2:
                mergeId = scanner.nextInt()
                otherCounter = Main(mergeId, n)
                # Read the counts for the other instance
                for j in range(n):
                    otherCounter.counterMap.put(j, scanner.nextInt())
                # Merge the other instance's counts into this instance
                counter.merge(otherCounter)
            # Handle invalid operation input
            else:
                print("Invalid operation.")
        # Output the final total count and state of the counter
        print("Final counter value: " + str(counter.value()))
        print("Final counter state: " + str(counter.getState()))

# 