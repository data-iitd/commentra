import sys

# Class to solve the problem
class Main:
    # Method to solve the problem
    def solve(self):
        # Read input values
        x = int(self.next()) # Target value
        t = int(self.next()) # Maximum number of steps
        a = int(self.next()) # Initial position of first entity
        b = int(self.next()) # Initial position of second entity
        da = int(self.next()) # Step size for first entity
        db = int(self.next()) # Step size for second entity
        
        first = 0 # Position of first entity after i steps
        second = 0 # Position of second entity after j steps
        ok = False # Flag to indicate if the target can be reached

        # Iterate through possible steps for the first entity
        for i in range(t):
            first = a - (da * i) # Calculate position of first entity
            
            # Iterate through possible steps for the second entity
            for j in range(t):
                second = b - (db * j) # Calculate position of second entity
                
                # Check if any of the conditions to reach target x are met
                if (second + first == x or second == x or first == x or x == 0):
                    ok = True # Set flag to true if target is reachable
                    break # Exit inner loop if target is found
            if (ok):
                break # Exit outer loop if target is found
        # Output result based on whether the target can be reached
        if (ok):
            print("YES") # Target can be reached
        else:
            print("NO") # Target cannot be reached

    # Main method to run the program
    def main(self):
        self.run() # Create an instance of Main and run it

    # Method to handle the execution flow
    def run(self):
        self.br = sys.stdin # Initialize BufferedReader
        self.out = sys.stdout # Initialize PrintWriter
        self.solve() # Call the solve method to process the input
        self.br.close() # Close BufferedReader
        self.out.close() # Close PrintWriter

    # Method to read the next token from input
    def next(self):
        # Continue reading until there are tokens available
        while (self.st == None or not self.st.hasMoreTokens()):
            try:
                self.st = self.br.readLine() # Read a new line and tokenize it
            except:
                e = sys.exc_info()[0]
                print("Error: %s" % e)
                return "END_OF_FILE" # Return a placeholder if an error occurs
        return self.st.nextToken() # Return the next token

# Create an instance of Main and run it
if __name__ == "__main__":
    Main().main()

