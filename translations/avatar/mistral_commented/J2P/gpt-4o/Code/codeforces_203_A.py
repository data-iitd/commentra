import sys

class Main:
    def solve(self):
        x = self.next_int()  # Read the first integer x
        t = self.next_int()  # Read the second integer t
        a = self.next_int()  # Read the third integer a
        b = self.next_int()  # Read the fourth integer b
        da = self.next_int()  # Read the fifth integer da
        db = self.next_int()  # Read the sixth integer db

        ok = False  # Initialize ok to false

        # Run a nested loop to find first and second
        for i in range(t):
            first = a - (da * i)  # Calculate first for the current i
            for j in range(t):
                second = b - (db * j)  # Calculate second for the current j

                # Check if second + first equals x or if either first or second equals x
                if second + first == x or second == x or first == x or x == 0:
                    ok = True  # Set ok to true if a match is found
                    break  # Exit the inner loop if a match is found
            if ok:  # If ok is true, break the outer loop as well
                break

        # Print YES if ok is true, otherwise print NO
        if ok:
            print("YES")
        else:
            print("NO")

    def run(self):
        self.solve()  # Call the solve method

    def next_int(self):
        return int(self.next())  # Read an integer from the standard input

    def next(self):
        return input()  # Read a line from the standard input

if __name__ == "__main__":
    Main().run()  # Create an instance of Main and call its run method

# <END-OF-CODE>
