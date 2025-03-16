import sys 
import math 

def solve(testNumber, in, out): 
    # Read the input string 
    x = in.readline() 
    s = [] 
    c = 0 # Counter for pairs of '0' and '1' 
    
    # Iterate through each character in the input string 
    for i in range(len(x)): 
        # Push the current character onto the stack 
        s.append(x[i]) 
        
        # Process the stack while there are at least two characters 
        while len(s) > 1: 
            p = s.pop() # Pop the top character 
            q = s.pop() # Pop the next character 
            
            # Check if the characters form a pair of '0' and '1' 
            if (p == '1' and q == '0') or (p == '0' and q == '1'): 
                c += 1 # Increment the counter for valid pairs 
                continue # Continue to check for more pairs 
            else: 
                # If not a valid pair, push the characters back onto the stack 
                s.append(q) 
                s.append(p) 
                break # Exit the while loop 
    # Output the result, which is twice the count of pairs found 
    out.write(str(c * 2) + '\n') 

if __name__ == '__main__': 
    # Set up input and output streams 
    inputStream = sys.stdin 
    outputStream = sys.stdout 
    in = InputReader(inputStream) 
    out = PrintWriter(outputStream) 
    
    # Create an instance of TaskB and solve the problem 
    solver = TaskB() 
    solver.solve(1, in, out) 
    
    # Close the output stream 
    out.close() 

class InputReader: 
    def __init__(self, stream): 
        # Initialize the BufferedReader and StringTokenizer 
        self.reader = BufferedReader(InputStreamReader(stream), 32768) 
        self.tokenizer = None 
    
    def next(self): 
        # Read the next token from the input 
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens(): 
            try: 
                self.tokenizer = StringTokenizer(self.reader.readLine()) 
            except IOException as e: 
                raise RuntimeException(e) 
        return self.tokenizer.nextToken() 

class PrintWriter: 
    def __init__(self, stream): 
        self.writer = BufferedWriter(OutputStreamWriter(stream)) 
    
    def write(self, string): 
        self.writer.write(string) 
    
    def close(self): 
        self.writer.close() 

class TaskB: 
    def solve(self, testNumber, in, out): 
        solve(testNumber, in, out) 

# 