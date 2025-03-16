import sys
from collections import defaultdict

class TaskD:
    def solve(self, n, m, a):
        # Initialize data structures
        dp = defaultdict(int)  # Dictionary to store intermediate results

        # Initialize variables
        ans = 0  # Answer variable
        base = 0  # Base value for hashmap key

        # Process each element in array a
        for i in range(n):
            # Update base value
            base = (base - a[i] % m + m) % m

            # Update hashmap with current base and its count
            dp[base + a[i] % m] += 1

            # Update answer variable
            ans += dp[base]

        # Print the answer
        print(ans)

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Number of elements in array a
    m = int(data[1])  # Modulus value
    a = list(map(int, data[2:n+2]))  # Read array a

    solver = TaskD()  # Initialize TaskD solver
    solver.solve(n, m, a)  # Solve the problem and print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
