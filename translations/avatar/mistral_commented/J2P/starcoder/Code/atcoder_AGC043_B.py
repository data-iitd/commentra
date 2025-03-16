
import sys

class Main:
    def cal(self, s, c):
        n = len(s)
        m = n - 1
        ans = 0
        for i in range(n):
            if s[i] == c and (m & i) == i:
                ans ^= 1
        return ans

    def solve(self):
        n = int(sys.stdin.readline())
        for i in range(n):
            num = int(sys.stdin.readline())
            s = sys.stdin.readline().strip()
            sb = []
            for i in range(1, num):
                sb.append(abs(ord(s[i]) - ord(s[i - 1])))
            s = "".join(map(str, sb))
            if num == 2:
                print(s[0])
                continue
            if "1" in s:
                print(self.cal(s, '1'))
            else:
                print(self.cal(s, '2') * 2)

if __name__ == "__main__":
    obj = Main()
    obj.solve()

