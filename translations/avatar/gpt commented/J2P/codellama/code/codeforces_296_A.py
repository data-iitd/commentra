import sys 

def main(): 
    # Set up input and output streams
    inputStream = sys.stdin 
    outputStream = sys.stdout 
    
    # Create an InputReader to read input from the input stream
    in = InputReader(inputStream) 
    
    # Create a PrintWriter to write output to the output stream
    out = PrintWriter(outputStream) 
    
    # Instantiate the Task class to solve the problem
    solver = Task() 
    
    # Call the solve method to process the input and produce output
    solver.solve(in, out) 
    
    # Close the PrintWriter to flush and release resources
    out.close() 

class Task: 
    def solve(self, in, out): 
        # Read the number of elements
        n = in.nextInt() 
        
        # Initialize an array to count occurrences of each index (up to 1000)
        array = [0] * 1001 
        
        # Read n integers and count their occurrences
        for i in range(n): 
            index = in.nextInt() 
            array[index] += 1 
        
        # Determine the maximum count of any index
        countMax = -1 
        for i in range(1, len(array)): 
            if countMax < array[i]: 
                countMax = array[i] 
        
        # Check if the maximum count is within allowed limits based on n being even or odd
        if n % 2 == 0: 
            # For even n, check if the maximum count is less than or equal to n/2
            if countMax <= n / 2: 
                out.println("YES") 
            else: 
                out.println("NO") 
        else: 
            # For odd n, check if the maximum count is less than or equal to n/2 + 1
            if countMax <= n / 2 + 1: 
                out.println("YES") 
            else: 
                out.println("NO") 

class InputReader: 
    def __init__(self, stream): 
        self.reader = stream 
        self.tokenizer = None 
    
    def next(self): 
        # Read a new line if the tokenizer is empty
        while self.tokenizer is None or not self.tokenizer.hasMoreElements(): 
            try: 
                self.tokenizer = StringTokenizer(self.reader.readLine()) 
            except IOException as e: 
                raise RuntimeException(e) 
        
        return self.tokenizer.nextToken() 
    
    def nextInt(self): 
        return int(self.next()) 
    
    def nextLong(self): 
        return long(self.next()) 
    
    def nextDouble(self): 
        return float(self.next()) 
    
    def nextLine(self): 
        str = "" 
        try: 
            str = self.reader.readLine() 
        except IOException as e: 
            e.printStackTrace() 
        
        return str 

class PrintWriter: 
    def __init__(self, stream): 
        self.writer = stream 
    
    def println(self, str): 
        self.writer.write(str + "\n") 

