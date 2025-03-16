
import sys

class Main:
    CACHE = {}
    @staticmethod
    def fibMemo(n):
        if n < 0:
            raise Exception("Input n must be non-negative")
        if n in Main.CACHE:
            return Main.CACHE[n]
        f = 0
        if n <= 1:
            f = n
        else:
            f = Main.fibMemo(n - 1) + Main.fibMemo(n - 2)
            Main.CACHE[n] = f
        return f
    @staticmethod
    def fibBotUp(n):
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
    @staticmethod
    def fibOptimized(n):
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
    @staticmethod
    def fibBinet(n):
        if n < 0:
            raise Exception("Input n must be non-negative")
        squareRootOf5 = pow(5, 0.5)
        phi = (1 + squareRootOf5) / 2
        return int((pow(phi, n) - pow(-phi, -n)) / squareRootOf5)
    @staticmethod
    def main():
        n = int(sys.stdin.readline().strip())
        print("Main number using Memoization: " + str(Main.fibMemo(n)))
        print("Main number using Bottom-Up: " + str(Main.fibBotUp(n)))
        print("Main number using Optimized Approach: " + str(Main.fibOptimized(n)))
        print("Main number using Binet's Formula: " + str(Main.fibBinet(n)))

if __name__ == "__main__":
    Main.main()

