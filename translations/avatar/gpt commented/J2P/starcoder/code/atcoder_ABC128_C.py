import sys

class Main:
    def __init__(self):
        self.run()

    def run(self):
        # Read the number of elements N and the number of groups M
        N, M = map(int, input().split())

        # Create an array to store bitwise representations for each element
        a = [0] * N

        # Read M groups of integers and update the bitwise representation
        for i in range(M):
            k = int(input())
            for j in range(k):
                s = int(input())
                s -= 1
                # Update the bitwise representation for the element
                a[s] |= (1 << i)

        # Read M integers to create a bitmask p
        p = 0
        for i in range(M):
            x = int(input())
            p |= (x << i)

        # Initialize a counter for valid combinations
        ans = 0

        # Iterate through all possible subsets of N elements
        for s in range(1 << N):
            t = 0
            for i in range(N):
                # Check if the i-th element is included in the subset
                if ((s >> i) & 1) == 1:
                    # XOR the current element's bitwise representation
                    t ^= a[i]
            # Check if the XOR result matches the bitmask p
            if p == t:
                ans += 1

        # Output the total count of valid combinations
        print(ans)

# Create an instance of Main and invoke the run method
if __name__ == "__main__":
    Main()

