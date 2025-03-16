import sys 

def main(): 
    # Initialize input and output streams
    inputStream = sys.stdin 
    outputStream = sys.stdout 
    
    # Create a Scanner object for reading input
    in = Scanner(inputStream) 
    
    # Create a PrintWriter object for writing output
    out = PrintWriter(outputStream) 
    
    # Create an instance of the BABC class to solve the problem
    solver = BABC() 
    
    # Call the solve method with test number, input scanner, and output writer
    solver.solve(1, in, out) 
    
    # Close the output writer
    out.close() 

class BABC: 
    def solve(self, testNumber, in, out): 
        # Read the input string and replace occurrences of "BC" with "D"
        s = in.next().replaceAll("BC", "D") 
        
        # Initialize counters for 'A' and the result
        cnt = 0 
        tmp = 0 
        
        # Iterate through the modified string to count occurrences
        for i in range(len(s)): 
            # Increment temporary counter for 'A'
            if s[i] == 'A': 
                tmp += 1 
            # Add the count of 'A's to the result when 'D' is encountered
            elif s[i] == 'D': 
                cnt += tmp 
            # Reset the temporary counter for any other character
            else: 
                tmp = 0 
        
        # Output the final count of valid pairs
        out.println(cnt) 

if __name__ == "__main__": 
    main() 

