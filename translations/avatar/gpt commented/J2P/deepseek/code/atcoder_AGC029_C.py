import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.n = 0
        self.a = []
        self.s = defaultdict(int)

    def set(self):
        # Read input values and initialize variables
        self.n = int(input().strip())  # Read the number of elements
        # Read the array elements and convert them to an integer array
        self.a = list(map(int, input().strip().split()))

    def solve(self):
        # Main logic to find the maximum k using binary search
        self.set()  # Initialize input values
        ng = 0  # Lower bound for binary search
        ok = self.n  # Upper bound for binary search

        # Perform binary search to find the maximum k
        while ok - ng > 1:
            k = (ng + ok) // 2  # Calculate mid-point
            # Check if it is possible to achieve the current k
            if self.isPossible(k):
                ok = k  # If possible, adjust upper bound
            else:
                ng = k  # If not possible, adjust lower bound

        # Output the result
        print(ok)

    def isPossible(self, k):
        # Check if it is possible to achieve the given k
        self.s.clear()  # Clear the defaultdict for new calculations
        current = 0  # Initialize current value

        # Iterate through each element in the array
        for ai in self.a:
            # If the current element is less than or equal to the current value
            if ai <= current:
                # If k is 1, return False as we cannot have duplicates
                if k == 1:
                    return False

                # Remove elements from defaultdict that are greater than or equal to ai
                while self.s and max(self.s) >= ai:
                    del self.s[max(self.s)]  # Remove the maximum entry

                p = ai - 1  # Start checking from the previous number
                while True:
                    # If p is less than 0, return False
                    if p < 0:
                        return False

                    # Get the count of p from defaultdict and increment it
                    sp = self.s[p] + 1
                    self.s[p] = sp  # Update the defaultdict with the new count

                    # If the count reaches k, remove p from defaultdict and decrement p
                    if sp == k:
                        del self.s[p]
                        p -= 1
                    else:
                        break  # Exit the loop if count is less than k
            current = ai  # Update current to the current element

        return True  # Return True if the condition is satisfied

# Create an instance of Main and invoke the solve method
m = Main()
m.solve()
