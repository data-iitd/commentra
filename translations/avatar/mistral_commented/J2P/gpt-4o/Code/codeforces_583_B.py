import sys

def main():
    for line in sys.stdin:
        n = int(line.strip())  # Reading the number of elements in the arrays
        a = [0] * n  # Creating an integer array 'a' of size 'n'
        b = [0] * n  # Creating an integer array 'b' of size 'n'
        s = -1  # Initializing the variable 's' to -1
        
        for i in range(n):  # Loop to read and initialize the arrays 'a' and 'b'
            a[i] = int(input().strip())  # Reading an integer value and storing it in the 'i'th position of array 'a'
            b[i] = 0  # Initializing all elements of array 'b' to zero
        
        tem = 1  # Initializing the variable 'tem' to 1
        q = 0  # Initializing the variable 'q' to 0
        
        while q != n:  # Main loop to find the sequence length
            s += 1  # Incrementing the variable 's'
            if tem == 1:  # If 'tem' is 1, perform the first half of the loop
                for i in range(n):
                    if a[i] <= q and b[i] == 0:  # Check conditions
                        b[i] = 1  # Set the corresponding element in array 'b' to 1
                        q += 1  # Increment 'q'
                tem = 0  # Switching the value of 'tem' to 0
            else:  # If 'tem' is 0, perform the second half of the loop
                for i in range(n - 1, -1, -1):
                    if a[i] <= q and b[i] == 0:  # Check conditions
                        b[i] = 1  # Set the corresponding element in array 'b' to 1
                        q += 1  # Increment 'q'
                tem = 1  # Switching the value of 'tem' to 1
        
        print(s)  # Printing the length of the sequence found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
