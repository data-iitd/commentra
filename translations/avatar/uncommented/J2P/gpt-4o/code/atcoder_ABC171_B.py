import sys

class Solution:
    def solve(self, n, k, a):
        a.sort()
        ans = sum(a[:k])
        print(ans)

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    a = list(map(int, data[2:n+2]))
    
    sol = Solution()
    sol.solve(n, k, a)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
