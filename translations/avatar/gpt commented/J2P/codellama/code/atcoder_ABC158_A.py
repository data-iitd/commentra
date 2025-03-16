import sys 

def main(): 
    # Initialize input and output streams
    inputStream = sys.stdin 
    outputStream = sys.stdout 
    
    # Create a Scanner object for reading input and a PrintWriter for output
    in = Scanner(inputStream) 
    out = PrintWriter(outputStream) 
    
    # Create an instance of the AStationAndBus class to solve the problem
    solver = AStationAndBus() 
    
    # Call the solve method with test number 1, passing the input and output objects
    solver.solve(1, in, out) 
    
    # Close the PrintWriter to flush the output
    out.close() 

class AStationAndBus: 
    def solve(self, testNumber, in, out): 
        # Read the input string
        s = in.next() 
        
        # Check if the string contains both 'A' and 'B'
        if 'A' in s and 'B' in s: 
            # If both characters are present, print "Yes"
            out.println("Yes") 
        else: 
            # If either character is missing, print "No"
            out.println("No") 

if __name__ == "__main__": 
    main() 

