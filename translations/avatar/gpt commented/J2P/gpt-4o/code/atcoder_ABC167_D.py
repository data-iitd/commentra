class Main:
    def __init__(self):
        # Constants for modulo and limits
        self.MOD = 1000000007
        self.MAX = float('inf')
        self.LMAX = float('inf')

        # Length for the array
        self.len = int(1e6) + 1

    def do_it(self):
        # Read the number of elements N and the long value K
        N = int(input())
        K = int(input())

        # Initialize the array A to store the input values
        A = [0] * N

        # Read N integers into the array A and adjust values to be zero-indexed
        for i in range(N):
            A[i] = int(input()) - 1

        # Set to track used indices and arrays to store index and position
        used = set()
        idx = [0] * N
        pos = [0] * N

        # Initialize variables for the cycle detection
        next_index = 0
        cur = 0

        # Detect the cycle in the array using the 'used' set
        while next_index not in used:
            used.add(next_index)
            idx[next_index] = cur
            pos[cur] = next_index
            next_index = A[next_index]
            cur += 1

        # Calculate the lengths of the cycle and the position of the next element
        a = cur - idx[next_index]
        b = idx[next_index]

        # Calculate the answer based on the cycle length and K
        ans = (10000 * a + K - b) % a + b

        # If b is greater than K, set ans to K
        if b > K:
            ans = K

        # Output the result, adjusting for 1-based indexing
        print(pos[ans] + 1)

if __name__ == "__main__":
    # Create an instance of Main and call the do_it method
    Main().do_it()

# <END-OF-CODE>
