import sys
import io

class Main:
    def __init__(self, input_stream=sys.stdin, output_stream=sys.stdout):
        self.input_stream = input_stream
        self.output_stream = output_stream
        self.br = io.TextIOWrapper(input_stream, encoding='utf-8')
        self.out = io.TextIOWrapper(output_stream, encoding='utf-8')
        self.st = None

    def solve(self):
        # Read input values
        x = int(self.next())  # Target value
        t = int(self.next())  # Maximum number of steps
        a = int(self.next())  # Initial position of first entity
        b = int(self.next())  # Initial position of second entity
        da = int(self.next())  # Step size for first entity
        db = int(self.next())  # Step size for second entity
        
        first = None  # Position of first entity after i steps
        second = None  # Position of second entity after j steps
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
        
        # Output result based on whether the target can be reached
        if ok:
            self.out.write("YES\n")  # Target can be reached
        else:
            self.out.write("NO\n")  # Target cannot be reached

    def run(self):
        try:
            self.solve()  # Call the solve method to process the input
        finally:
            self.br.close()  # Close BufferedReader
            self.out.close()  # Close PrintWriter

    def next(self):
        # Continue reading until there are tokens available
        while self.st is None or not self.st.has_more_tokens():
            line = self.br.readline()
            if not line:
                return "END_OF_FILE"  # Return a placeholder if an error occurs
            self.st = io.StringIO(line).read().split()
        return self.st.pop(0)  # Return the next token

# Create an instance of Main and run it
if __name__ == "__main__":
    Main().run()
