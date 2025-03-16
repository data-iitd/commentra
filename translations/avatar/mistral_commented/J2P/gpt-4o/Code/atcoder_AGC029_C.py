import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.n = 0  # Number of elements in the array 'a'
        self.a = []  # Array of integers
        self.s = defaultdict(int)  # Dictionary to store the count of each element

    def set_input(self):
        self.n = int(sys.stdin.readline().strip())  # Read the first line containing the number of elements 'n'
        self.a = list(map(int, sys.stdin.readline().strip().split()))  # Read the second line containing the elements of the array 'a'

    def solve(self):
        self.set_input()  # Call the set_input method to read the input
        ng = 0  # Initialize the lower bound of the search range
        ok = self.n  # Initialize the upper bound of the search range

        while ok - ng > 1:  # Run the while loop until the search range is narrowed down to a single element
            k = (ng + ok) // 2  # Calculate the middle index of the search range
            if self.is_possible(k):  # If the middle index 'k' is a valid solution, update the upper bound
                ok = k
            else:  # Otherwise, update the lower bound
                ng = k

        print(ok)  # Print the solution

    def is_possible(self, k):
        self.s.clear()  # Clear the dictionary 's' before processing the new condition
        current = 0  # Initialize the current index in the array 'a'

        for ai in self.a:  # Iterate through each element in the array 'a'
            if ai <= current:  # If the current element is smaller than or equal to the previous one, check if the condition 'k' is valid
                if k == 1:
                    return False  # If 'k' is 1, return false as there is no possible solution

                while self.s and max(self.s.keys()) >= ai:  # If there is an element greater than or equal to 'ai' in the dictionary, remove it
                    self.s.pop(max(self.s.keys()))

                p = ai - 1  # Calculate the previous index 'p'
                while True:  # Find the previous index 'p' with the count 'k' in the dictionary
                    if p < 0:
                        return False  # If 'p' is out of the array bounds, return false

                    sp = self.s[p] + 1  # Get the count of 'p' in the dictionary or initialize it to 1
                    self.s[p] = sp  # Update the count of 'p' in the dictionary

                    if sp == k:  # If the count of 'p' is equal to 'k', remove it and move to the previous index
                        del self.s[p]
                        p -= 1
                    else:  # Otherwise, break the loop
                        break
            current = ai  # Update the current index

        return True  # If all elements in the array 'a' are processed, return true as a valid solution is found

if __name__ == "__main__":
    m = Main()  # Create an instance of Main class
    m.solve()  # Call the solve method to find the solution

# <END-OF-CODE>
