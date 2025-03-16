import math

def main():
    q = int(input())  # Read the number of queries
    
    for _ in range(q):
        n = int(input())  # Read the number n for the current query
        s = 0  # Initialize the sum variable s
        
        x = int(math.log(n, 2))  # Calculate the position of the most significant bit of n
        x += 1  # Increment x by 1
        
        s = -1 * (2 ** x) + 2 + (n * (n + 1)) // 2 - (2 ** x) 
        # Calculate s using arithmetic operations and power functions
        
        print(s)  # Print the result s for the current query

if __name__ == "__main__":
    main()

# <END-OF-CODE>
