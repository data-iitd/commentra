import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.N = int(input().strip())
        self.MOD = 1000000007
        self.TOKENS = ["A", "C", "G", "T"]
        self.memo = [defaultdict(int) for _ in range(self.N + 1)]

    def calc(self):
        return self.dfs(0, "TTT")

    def is_ok(self, last4):
        if "AGC" in last4:
            return False
        for i in range(3):
            chars = list(last4)
            chars[i], chars[i + 1] = chars[i + 1], chars[i]
            if "AGC" in ''.join(chars):
                return False
        return True

    def dfs(self, current, last3):
        if self.memo[current][last3]:
            return self.memo[current][last3]
        if current == self.N:
            return 1
        result = 0
        for c in self.TOKENS:
            if self.is_ok(last3[1:] + c):
                result = (result + self.dfs(current + 1, last3[1:] + c)) % self.MOD
        self.memo[current][last3] = result
        return result

if __name__ == "__main__":
    ins = Main()
    print(ins.calc())
