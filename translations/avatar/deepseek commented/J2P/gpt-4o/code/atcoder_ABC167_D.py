class Main:
    def __init__(self):
        self.MOD = 1000000007
        self.MAX = float('inf')
        self.LMAX = float('inf')
        self.len = int(1e6) + 1

    def do_it(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        
        # Read the number of elements N and the value K
        N = int(data[0])
        K = int(data[1])
        
        # Read the array A with N elements, adjusting each element by -1 for 0-based indexing
        A = [int(data[i + 2]) - 1 for i in range(N)]
        
        # Set to track visited indices
        used = set()
        
        # Arrays to store index and position information
        idx = [0] * N
        pos = [0] * N
        
        # Initialize variables for cycle detection
        next_index = 0
        cur = 0
        
        # Detect the cycle in the array A
        while next_index not in used:
            used.add(next_index)
            idx[next_index] = cur
            pos[cur] = next_index
            next_index = A[next_index]
            cur += 1
        
        # Calculate the length of the cycle and adjust the position based on K
        a = cur - idx[next_index]
        b = idx[next_index]
        ans = (10000 * a + K - b) % a + b
        
        # Adjust the answer if necessary based on the cycle length
        if b > K:
            ans = K
        
        # Output the final position
        print(pos[ans] + 1)

if __name__ == "__main__":
    Main().do_it()
# <END-OF-CODE>
