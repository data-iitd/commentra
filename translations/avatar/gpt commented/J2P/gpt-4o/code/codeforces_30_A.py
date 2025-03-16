class Main:
    def solve(self, A, B, n):
        # Check if A is zero
        if A == 0:
            # If both A and B are zero, print 1 (indeterminate case)
            if B == 0:
                print(1)
            # If A is zero and B is not, print "No solution"
            else:
                print("No solution")
            return
        
        # Check if B is not divisible by A
        if B % A != 0:
            # If B is not divisible by A, print "No solution"
            print("No solution")
            return
        
        # Divide B by A to simplify the equation
        B //= A
        
        # Determine if B is negative
        neg = B < 0
        
        # Check if B is negative and n is even
        if neg and n % 2 == 0:
            # If both conditions are true, print "No solution"
            print("No solution")
            return
        
        # If B is negative, make it positive for further calculations
        if neg:
            B = -B
        
        # Iterate through possible values of x from 0 to B
        for x in range(B + 1):
            # Check if x raised to the power of n equals B
            if x ** n == B:
                # If found, print the result considering the sign of B
                print(-x if neg else x)
                return
        
        # If no valid x is found, print "No solution"
        print("No solution")

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    A, B, n = map(int, input().strip().split())
    Main().solve(A, B, n)

# <END-OF-CODE>
