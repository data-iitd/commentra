import sys 
import threading 

class InputReader(threading.Thread): 
    def __init__(self, stream): 
        threading.Thread.__init__(self) 
        self.stream = stream 
        self.input = "" 
        self.tokenizer = None 
        self.start() 

    def run(self): 
        while True: 
            try: 
                self.input = self.stream.readline() 
            except: 
                break 

    def n(self): 
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens(): 
            if self.input == "": 
                break 
            self.tokenizer = self.Tokenizer(self.input) 
            self.input = "" 
        if self.tokenizer != None and self.tokenizer.hasMoreTokens(): 
            return self.tokenizer.nextToken() 
        return None 

    def ni(self): 
        return int(self.n()) 

    class Tokenizer: 
        def __init__(self, input): 
            self.tokens = input.split() 
            self.index = -1 

        def hasMoreTokens(self): 
            return self.index + 1 < len(self.tokens) 

        def nextToken(self): 
            self.index += 1 
            return self.tokens[self.index] 

class Solution: 
    def solve(self, in, out): 
        # Read the number of elements (n) and the number of smallest elements to sum (k)
        n = in.ni() 
        k = in.ni() 
        
        # Initialize an array to hold the input numbers
        a = [0] * n 
        
        # Read n integers from input and store them in the array
        for i in range(n): 
            a[i] = in.ni() 
        
        # Sort the array in parallel to arrange numbers in ascending order
        a.sort() 
        
        # Initialize a variable to hold the sum of the smallest k elements
        ans = 0 
        
        # Sum the first k elements of the sorted array
        for i in range(k): 
            ans += a[i] 
        
        # Output the result (sum of the smallest k elements)
        out.println(ans) 

if __name__ == "__main__": 
    # Set up input and output streams
    inputStream = sys.stdin 
    outputStream = sys.stdout 
    
    # Create an InputReader to read input from the input stream
    in = InputReader(inputStream) 
    
    # Create a PrintWriter to write output to the output stream
    out = PrintWriter(outputStream) 
    
    # Create an instance of the Solution class to solve the problem
    sol = Solution() 
    
    # Call the solve method to process the input and produce output
    sol.solve(in, out) 
    
    # Close the PrintWriter to flush the output
    out.close() 

