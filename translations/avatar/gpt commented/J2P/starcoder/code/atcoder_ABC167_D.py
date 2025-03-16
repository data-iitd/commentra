import sys

class Main:
    # Initialize scanner for input
    def __init__(self):
        self.sc = sys.stdin
    
    # Constants for modulo and limits
    MOD = 1000000007
    MAX = 2147483647
    LMAX = 9223372036854775807
    
    # Length for the array
    len = 1000001
    
    def doIt(self):
        # Read the number of elements N and the long value K
        N = int(self.sc.readline())
        K = int(self.sc.readline())
        
        # Initialize the array A to store the input values
        A = [0] * N
        
        # Read N integers into the array A and adjust values to be zero-indexed
        for i in range(N):
            A[i] = int(self.sc.readline()) - 1
        
        # Set to track used indices and arrays to store index and position
        used = set()
        idx = [0] * N
        pos = [0] * N
        
        # Initialize variables for the cycle detection
        next = 0
        cur = 0
        
        # Detect the cycle in the array using the 'used' set
        while not used.__contains__(next):
            used.add(next)
            idx[next] = cur
            pos[cur] = next
            next = A[next]
            cur += 1
        
        # Calculate the lengths of the cycle and the position of the next element
        a = cur - idx[next]
        b = idx[next]
        
        # Calculate the answer based on the cycle length and K
        ans = (10000 * a + K - b) % a + b
        
        # If b is greater than K, set ans to K
        if b > K:
            ans = K
        
        # Output the result, adjusting for 1-based indexing
        print(pos[ans] + 1)

# Create an instance of Main and call the doIt method
Main().doIt()

