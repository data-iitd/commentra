import sys

class Main:
    def solve(self):
        # Read input values
        x = self.next_int()  # Target value
        t = self.next_int()  # Maximum number of steps
        a = self.next_int()  # Initial position of first entity
        b = self.next_int()  # Initial position of second entity
        da = self.next_int()  # Step size for first entity
        db = self.next_int()  # Step size for second entity

        ok = False  # Flag to indicate if the target can be reached

        # Iterate through possible steps for the first entity
        for i in range(t):
            first = a - (da * i)  # Calculate position of first entity
            
            # Iterate through possible steps for the second entity
            for j in range(t):
                second = b - (db * j)  # Calculate position of second entity
                
                # Check if any of the conditions to reach target x are met
                if second + first == x or second == x or first == x or x == 0:
                    ok = True  # Set flag to true if target is reachable
                    break  # Exit inner loop if target is found
            
            if ok:  # If target is found, no need to continue outer loop
                break

        # Output result based on whether the target can be reached
        if ok:
            print("YES")  # Target can be reached
        else:
            print("NO")  # Target cannot be reached

    def run(self):
        self.input = sys.stdin.read
        data = self.input().split()
        self.data_iter = iter(data)
        self.solve()

    def next_int(self):
        return int(next(self.data_iter))  # Parse the next token as an integer

if __name__ == "__main__":
    Main().run()  # Create an instance of Main and run it

# <END-OF-CODE>
