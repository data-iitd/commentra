
import sys

class Main:
    CACHE = {}

    def fibMemo(self, n):
        if n < 0:
            raise Exception("Input n must be non-negative")
        if n in self.CACHE:
            return self.CACHE[n]

        f = 0
        if n <= 1:
            f = n
        else:
            f = self.fibMemo(n - 1) + self.fibMemo(n - 2)
            self.CACHE[n] = f
        return f

    def fibBotUp(self, n):
        if n < 0:
            raise Exception("Input n must be non-negative")
        fib = {}

        for i in range(0, n + 1):
            f = 0
            if i <= 1:
                f = i
            else:
                f = fib.get(i - 1) + fib.get(i - 2)
            fib[i] = f

        return fib.get(n)

    def fibOptimized(self, n):
        if n < 0:
            raise Exception("Input n must be non-negative")
        if n == 0:
            return 0
        prev = 0
        res = 1
        next = 0
        for i in range(2, n + 1):
            next = prev + res
            prev = res
            res = next
        return res

    def fibBinet(self, n):
        if n < 0:
            raise Exception("Input n must be non-negative")
        squareRootOf5 = 5 ** 0.5
        phi = (1 + squareRootOf5) / 2
        return int((phi ** n - (-phi) ** -n) / squareRootOf5)

    def main(self):
        n = int(sys.stdin.readline().strip())

        print("Main number using Memoization: " + str(self.fibMemo(n)))
        print("Main number using Bottom-Up: " + str(self.fibBotUp(n)))
        print("Main number using Optimized Approach: " + str(self.fibOptimized(n)))
        print("Main number using Binet's Formula: " + str(self.fibBinet(n)))

if __name__ == "__main__":
    Main().main()

