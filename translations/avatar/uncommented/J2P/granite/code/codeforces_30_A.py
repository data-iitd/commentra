
import math

class Main:
    def solve(self, sc):
        A = sc.nextInt()
        B = sc.nextInt()
        n = sc.nextInt()

        if A == 0:
            if B == 0:
                print(1)
            else:
                print("No solution")
            return

        if B % A!= 0:
            print("No solution")
            return

        B //= A
        neg = B < 0

        if neg and n % 2 == 0:
            print("No solution")
            return

        if neg:
            B = -B

        for x in range(B + 1):
            if math.pow(x, n) == B:
                print(-x if neg else x)
                return

        print("No solution")

sc = Scanner(sys.stdin)
Main().solve(sc)
