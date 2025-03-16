import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.n = 0  # Number of elements in the array
        self.a = []  # Array to store the input integers
        self.s = defaultdict(int)  # Dictionary to keep track of counts of integers

    def set(self):
        # Read input values and initialize variables
        self.n = int(sys.stdin.readline().strip())  # Read the number of elements
        self.a = list(map(int, sys.stdin.readline().strip().split()))  # Read the array elements

    def solve(self):
        # Main logic to find the maximum k using binary search
        self.set()  # Initialize input values
        ng = 0  # Lower bound for binary search
        ok = self.n  # Upper bound for binary search

        # Perform binary search to find the maximum k
        while ok - ng > 1:
            k = (ng + ok) // 2  # Calculate mid-point
            # Check if it is possible to achieve the current k
            if self.is_possible(k):
                ok = k  # If possible, adjust upper bound
            else:
                ng = k  # If not possible, adjust lower bound

        # Output the result
        print(ok)

    def is_possible(self, k):
        # Check if it is possible to achieve the given k
        self.s.clear()  # Clear the dictionary for new calculations
        current = 0  # Initialize current value

        # Iterate through each element in the array
        for ai in self.a:
            # If the current element is less than or equal to the current value
            if ai <= current:
                # If k is 1, return false as we cannot have duplicates
                if k == 1:
                    return False

                # Remove elements from dictionary that are greater than or equal to ai
                keys_to_remove = [key for key in self.s if key >= ai]
                for key in keys_to_remove:
                    del self.s[key]  # Remove the entry

                p = ai - 1  # Start checking from the previous number
                while True:
                    # If p is less than 0, return false
                    if p < 0:
                        return False

                    # Increment the count of p in the dictionary
                    self.s[p] += 1

                    # If the count reaches k, remove p from dictionary and decrement p
                    if self.s[p] == k:
                        del self.s[p]
                        p -= 1
                    else:
                        break  # Exit the loop if count is less than k

            current = ai  # Update current to the current element
        return True  # Return true if the condition is satisfied

if __name__ == "__main__":
    m = Main()
    m.solve()

# <END-OF-CODE>
