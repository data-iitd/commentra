import sys

class Main:
    def solve(self):
        # Reading the number of test cases (t) and other required values
        x = self.next_int()  # Target value x
        t = self.next_int()  # Number of test cases (unused in this code)
        a = self.next_int()  # Value a
        b = self.next_int()  # Value b
        da = self.next_int()  # Difference a (da)
        db = self.next_int()  # Difference b (db)

        # Flag to determine if a solution is found
        ok = False

        # Nested loop to calculate possible values of first and second
        for i in range(t):
            first = a - (da * i)  # Calculate first value
            for j in range(t):
                second = b - (db * j)  # Calculate second value
                if second + first == x or second == x or first == x or x == 0:
                    # Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                    ok = True
                    break
            if ok:
                break  # Exit the outer loop if a solution is found

        # Print the result based on the flag
        if ok:
            print("YES")
        else:
            print("NO")

    def run(self):
        self.solve()

    # Method to read the next integer from the input
    def next_int(self):
        return int(self.next())

    # Method to read the next token from the input
    def next(self):
        return sys.stdin.readline().strip()

if __name__ == "__main__":
    Main().run()

# <END-OF-CODE>
