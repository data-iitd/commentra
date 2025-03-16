import sys 

def main(): 
    # Set up input and output streams
    inputStream = sys.stdin 
    outputStream = sys.stdout 
    
    # Create an InputReader to read input from the input stream
    in = InputReader(inputStream) 
    
    # Create a PrintWriter to write output to the output stream
    out = PrintWriter(outputStream) 
    
    # Instantiate the solver class for the problem
    solver = CColoringColorfully() 
    
    # Solve the problem for the first test case
    solver.solve(1, in, out) 
    
    # Close the output stream
    out.close() 

class CColoringColorfully: 
    def solve(self, testNumber, in, out): 
        # Read the input string
        x = in.next() 
        
        # Create two StringBuilders to manipulate the string
        a = StringBuilder(x) 
        b = StringBuilder(x) 
        
        # Initialize counters for the number of changes made
        a1 = 0 
        a2 = 0 
        
        # First pass: modify 'a' from left to right
        for i in range(1, len(x)): 
            # Check if the current character is the same as the previous one
            if a.charAt(i) == a.charAt(i - 1): 
                # Change the character to the opposite value
                if a.charAt(i) == '1': 
                    a.setCharAt(i, '0') 
                else: 
                    a.setCharAt(i, '1') 
                
                # Increment the change counter
                a1 += 1 
        
        # Second pass: modify 'b' from right to left
        for i in range(len(x) - 1, 0, -1): 
            # Check if the current character is the same as the previous one
            if b.charAt(i) == b.charAt(i - 1): 
                # Change the previous character to the opposite value
                if b.charAt(i - 1) == '1': 
                    b.setCharAt(i - 1, '0') 
                else: 
                    b.setCharAt(i - 1, '1') 
                
                # Increment the change counter
                a2 += 1 
        
        # Output the minimum number of changes made in either pass
        out.println(min(a1, a2)) 

class InputReader: 
    def __init__(self, stream): 
        self.reader = BufferedReader(InputStreamReader(stream), 32768) 
        self.tokenizer = None 
    
    def next(self): 
        # Ensure there are tokens available to read
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens(): 
            try: 
                # Read a new line and tokenize it
                self.tokenizer = StringTokenizer(self.reader.readLine()) 
            except IOException as e: 
                raise RuntimeException(e) 
        
        # Return the next token
        return self.tokenizer.nextToken() 

class StringBuilder: 
    def __init__(self, string): 
        self.string = string 
    
    def charAt(self, index): 
        return self.string[index] 
    
    def setCharAt(self, index, char): 
        self.string = self.string[:index] + char + self.string[index + 1:] 

class PrintWriter: 
    def __init__(self, stream): 
        self.writer = BufferedWriter(OutputStreamWriter(stream)) 
    
    def println(self, string): 
        self.writer.write(string + '\n') 
    
    def close(self): 
        self.writer.close() 

if __name__ == '__main__': 
    main() 

