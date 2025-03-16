import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.n = 0  # Number of elements in the array
        self.a = []  # The array itself
        self.s = defaultdict(int)  # Dictionary to keep track of counts of elements

    def set(self):
        self.n = int(sys.stdin.readline().strip())
        self.a = list(map(int, sys.stdin.readline().strip().split()))

    def solve(self):
        self.set()
        ng = 0  # Lower bound for binary search
        ok = self.n  # Upper bound for binary search
        while ok - ng > 1:
            k = (ng + ok) // 2  # Midpoint of the current search range
            if self.is_possible(k):
                ok = k  # Adjust the upper bound if k is possible
            else:
                ng = k  # Adjust the lower bound if k is not possible
        print(ok)  # Print the result of the binary search

    def is_possible(self, k):
        self.s.clear()  # Clear the dictionary for each new k
        current = 0  # Current index in the array
        for ai in self.a:
            if ai <= current:  # Check if the current element can be part of the previous subarray
                if k == 1:
                    return False  # If k is 1, it's not possible to partition
                while self.s and max(self.s) >= ai:
                    del self.s[max(self.s)]  # Remove elements from the dictionary that are greater than or equal to the current element
                p = ai - 1  # Start checking from the previous element
                while True:
                    if p < 0:
                        return False  # If p goes below 0, it's not possible to partition
                    sp = self.s[p] + 1  # Get the count of p and add 1
                    self.s[p] = sp  # Put the updated count back into the dictionary
                    if sp == k:  # If the count of p is equal to k
                        del self.s[p]  # Remove p from the dictionary
                        p -= 1  # Move to the previous element
                    else:
                        break  # Break the loop if the count is not equal to k
            current = ai  # Update the current element
        return True  # Return true if it's possible to partition the array into k subarrays

if __name__ == "__main__":
    m = Main()
    m.solve()

# <END-OF-CODE>
