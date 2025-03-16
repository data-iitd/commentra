import sys

class Main:
    def __init__(self):
        self.n = 0
        self.a = []
        self.s = {}

    def set(self):
        # Read input values and initialize variables
        self.n = int(sys.stdin.readline()) # Read the number of elements
        # Read the array elements and convert them to an integer array
        self.a = list(map(int, sys.stdin.readline().split(" ")))
        self.s = {} # Initialize the TreeMap

    def solve(self):
        # Main logic to find the maximum k using binary search
        self.set() # Initialize input values
        ng = 0 # Lower bound for binary search
        ok = self.n # Upper bound for binary search

        # Perform binary search to find the maximum k
        while ok - ng > 1:
            k = (ng + ok) // 2 # Calculate mid-point
            # Check if it is possible to achieve the current k
            if self.isPossible(k):
                ok = k # If possible, adjust upper bound
            else:
                ng = k # If not possible, adjust lower bound
        # Output the result
        print(ok)

    def isPossible(self, k):
        # Check if it is possible to achieve the given k
        self.s = {} # Clear the TreeMap for new calculations
        current = 0 # Initialize current value

        # Iterate through each element in the array
        for ai in self.a:
            # If the current element is less than or equal to the current value
            if ai <= current:
                # If k is 1, return false as we cannot have duplicates
                if k == 1: return False

                # Remove elements from TreeMap that are greater than or equal to ai
                while len(self.s) > 0 and list(self.s.keys())[-1] >= ai:
                    self.s.pop(list(self.s.keys())[-1]) # Remove the last entry

                p = ai - 1 # Start checking from the previous number
                while True:
                    # If p is less than 0, return false
                    if p < 0: return False

                    # Get the count of p from TreeMap and increment it
                    sp = self.s.get(p, 0) + 1
                    self.s[p] = sp # Update the TreeMap with the new count

                    # If the count reaches k, remove p from TreeMap and decrement p
                    if sp == k:
                        self.s.pop(p)
                        p -= 1
                    else:
                        break # Exit the loop if count is less than k
            current = ai # Update current to the current element
        return True # Return true if the condition is satisfied

if __name__ == "__main__":
    m = Main()
    m.solve()

