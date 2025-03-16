
import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.MOD = 1000000007
        self.MAX = int(1e6)
        self.LMAX = long(1e18)
        self.len = int(1e6) + 1

    def doIt(self):
        # Read the number of elements N and the value K
        N = int(self.sc.readline())
        K = long(self.sc.readline())

        # Read the array A with N elements, adjusting each element by -1 for 0-based indexing
        A = [int(x) - 1 for x in self.sc.readline().split()]

        # Set to track visited indices
        used = set()

        # Arrays to store index and position information
        idx = [0] * self.len
        pos = [0] * self.len

        # Initialize variables for cycle detection
        next = 0
        cur = 0

        # Detect the cycle in the array A
        while next not in used:
            used.add(next)
            idx[next] = cur
            pos[cur] = next
            next = A[next]
            cur += 1

        # Calculate the length of the cycle and adjust the position based on K
        a = long(cur - idx[next])
        b = long(idx[next])
        ans = (10000 * a + K - b) % a + b

        # Adjust the answer if necessary based on the cycle length
        if b > K:
            ans = K

        # Output the final position
        print(pos[ans] + 1)

if __name__ == '__main__':
    Main().doIt()

