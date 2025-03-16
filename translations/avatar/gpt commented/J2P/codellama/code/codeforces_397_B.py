import sys 
import math 

def main(): 
    # Initialize scanner for input and print writer for output
    in = sys.stdin 
    out = sys.stdout 
    
    # Read the number of test cases
    t = int(in.readline()) 
    
    # Process each test case
    while t > 0: 
        # Read input values for each test case
        n, a, b = map(int, in.readline().split()) 
        
        # Check if n is less than a, if so, output "No"
        if n < a: 
            out.write("No\n") 
            t -= 1 
            continue 
        
        # If a equals b, check if n is a multiple of a
        if a == b: 
            if n % a == 0: 
                out.write("Yes\n") 
            else: 
                out.write("No\n") 
            t -= 1 
            continue 
        
        # Calculate the maximum number of a's that can fit into b
        x = b // (b - a) 
        
        # If n is greater than x * a, output "Yes"
        if n > x * a: 
            out.write("Yes\n") 
            t -= 1 
            continue 
        
        # Binary search to find the largest mid such that mid * a < n
        low = 1 
        high = x + 1 
        ans = 1 
        while low <= high: 
            mid = (low + high) // 2 
            
            # Adjust the search range based on the condition
            if mid * a < n: 
                low = mid + 1 
            else: 
                ans = mid 
                high = mid - 1 
        
        # Check the final conditions to determine output
        if n > (ans - 1) * b and n < ans * a: 
            out.write("No\n") 
        else: 
            out.write("Yes\n") 
        t -= 1 
    
    # Close the output writer
    out.close() 


