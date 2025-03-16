class Main:
    def solve(self, A, B, n):
        # Step 2: Handling Special Case A == 0
        if A == 0:
            if B == 0:
                print(1)
            else:
                print("No solution")
            return

        # Step 3: Checking Divisibility
        if B % A != 0:
            print("No solution")
            return

        # Step 4: Normalizing B
        B //= A
        neg = B < 0
        if neg and n % 2 == 0:
            print("No solution")
            return
        if neg:
            B = -B

        # Step 5: Iterating to Find Solution
        for x in range(B + 1):
            if x ** n == B:
                print(-x if neg else x)
                return

        # Step 6: No Solution Found
        print("No solution")

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = list(map(int, input().strip().split()))
    A, B, n = data[0], data[1], data[2]
    Main().solve(A, B, n)

# <END-OF-CODE>
