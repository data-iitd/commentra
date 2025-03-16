
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create an instance of Main and invoke the run method
main = Main()
main.run()

class Main:
    def run(self):
        # Initialize a Scanner to read input from the console
        sc = Scanner(System.in)

        # Read the number of elements N and the number of groups M
        N = sc.nextInt()
        M = sc.nextInt()

        # Create an ArrayList to store bitwise representations for each element
        a = ArrayList()

        # Initialize the ArrayList with zeros for N elements
        for i in range(N):
            a.add(0)

        # Read M groups of integers and update the bitwise representation
        for i in range(M):
            k = sc.nextInt()  # Read the number of integers in the current group
            for j in range(k):
                s = sc.nextInt()  # Read the integer
                s -= 1  # Convert to zero-based index
                # Update the bitwise representation for the element
                a.set(s, a.get(s) | (1 << i))

        # Read M integers to create a bitmask p
        p = 0
        for i in range(M):
            x = sc.nextInt()  # Read the integer
            p |= (x << i)  # Update the bitmask p

        # Initialize a counter for valid combinations
        ans = 0

        # Iterate through all possible subsets of N elements
        for s in range(1 << N):
            t = 0  # Initialize a temporary variable to store the XOR result
            for i in range(N):
                # Check if the i-th element is included in the subset
                if ((s >> i) & 1) == 1:
                    # XOR the current element's bitwise representation
                    t ^= a.get(i)
            # Check if the XOR result matches the bitmask p
            if p == t:
                ans += 1  # Increment the count of valid combinations

        # Output the total count of valid combinations
        print(ans)

        # Close the scanner to free resources
        sc.close()

