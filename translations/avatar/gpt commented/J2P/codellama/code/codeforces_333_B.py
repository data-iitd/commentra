
import sys 
import math 

# FastReader for efficient input reading
class FastReader: 
    def __init__(self): 
        self.br = sys.stdin 
        self.st = None 

    def next(self): 
        while self.st == None or not self.st.hasMoreElements(): 
            try: 
                self.st = iter(self.br.readline().strip().split(" ")) 
            except: 
                self.st = iter(self.br.readline().strip().split(" ")) 
        return self.st.next() 

    def nextInt(self): 
        return int(self.next()) 

    def nextLong(self): 
        return long(self.next()) 

    def nextDouble(self): 
        return float(self.next()) 

    def nextLine(self): 
        str = "" 
        try: 
            str = self.br.readline().strip() 
        except: 
            str = self.br.readline().strip() 
        return str 

# Initialize FastReader for efficient input reading
in = FastReader() 

# PrintWriter for efficient output writing
out = sys.stdout 

def main(): 
    # Read the dimensions of the grid
    n = in.nextInt() 
    m = in.nextInt() 
    
    # Initialize sets to keep track of banned rows and columns
    bannedRows, bannedCols = set(), set() 
    
    # Read the banned rows and columns
    for i in range(m): 
        r = in.nextInt() 
        # Add to bannedRows if the row is within valid range
        if r > 1 and r < n: 
            bannedRows.add(r) 
        c = in.nextInt() 
        # Add to bannedCols if the column is within valid range
        if c > 1 and c < n: 
            bannedCols.add(c) 
    
    # Calculate the initial answer based on the grid size
    answer = (n - 2) * 2 
    # Subtract the number of banned rows and columns from the answer
    answer -= len(bannedRows) 
    answer -= len(bannedCols) 
    
    # If n is odd, check the middle row and column
    if n % 2 != 0: 
        mid = (n + 1) / 2 
        # If the middle row and column are not banned, decrement the answer
        if mid not in bannedRows and mid not in bannedCols: 
            answer -= 1 
    
    # Output the final answer
    out.write(str(answer) + "\n") 
    out.close() 

if __name__ == "__main__": 
    main() 

# 