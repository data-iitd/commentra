import sys

def main():
    for line in sys.stdin:
        n = int(line.strip())  # Read the size of the arrays
        a = [0] * n  # Initialize array a
        b = [0] * n  # Initialize array b
        s = -1  # Initialize the counter s to -1
        
        # Read n integers into array a
        for i in range(n):
            a[i] = int(input().strip())
            b[i] = 0  # Initialize array b to all zeros
        
        tem = 1  # Initialize tem to 1
        q = 0  # Initialize q to 0
        
        # Enter a while loop that continues until q equals n
        while q != n:
            s += 1  # Increment the counter s
            
            # If tem is 1, process elements from the start of a to the end
            if tem == 1:
                for i in range(n):
                    if a[i] <= q and b[i] == 0:
                        b[i] = 1  # Mark the element as processed
                        q += 1  # Increment the processed element counter
                tem = 0  # Toggle tem to 0
            
            # If tem is 0, process elements from the end of a to the start
            else:
                for i in range(n - 1, -1, -1):
                    if a[i] <= q and b[i] == 0:
                        b[i] = 1  # Mark the element as processed
                        q += 1  # Increment the processed element counter
                tem = 1  # Toggle tem to 1
        
        # Print the value of s
        print(s)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
