import sys

class Fast:
    def sol(self, br, pw):
        # Read the first line of input and get the string
        s = br.readline().strip()
        
        # Initialize a cumulative array to count consecutive characters
        cum = [0] * (len(s) + 1)
        
        # Fill the cumulative array with counts of consecutive characters
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1  # Increment count if the current character is the same as the previous
            else:
                cum[i] = cum[i - 1]  # Carry forward the previous count if different
        
        # Read the number of queries from the input
        q = int(br.readline().strip())
        
        # Process each query
        for _ in range(q):
            # Read the range for the query
            l, r = map(int, br.readline().strip().split())
            r -= 1  # Adjust r to be zero-indexed
            
            # Calculate and print the result for the current query
            pw.write(f"{cum[r] - cum[l - 1]}\n")

def main():
    # Create a Fast instance to process the input
    f = Fast()
    
    # Call the solution method to handle the input and produce output
    f.sol(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
