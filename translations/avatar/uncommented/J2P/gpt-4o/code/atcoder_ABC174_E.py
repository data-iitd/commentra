import sys
import math

class Solution:
    def solve(self, n, k, logs_length):
        min_length = 1
        max_length = int(1e9) + 1000
        
        while min_length < max_length:
            mid = (min_length + max_length) // 2
            if self.nei(mid, logs_length, k):
                max_length = mid
            else:
                min_length = mid + 1
        
        print(min_length)

    def nei(self, mid, logs_length, k):
        for log in logs_length:
            k -= (log + mid - 1) // mid - 1
        return k >= 0

def main():
    input_data = sys.stdin.read().splitlines()
    n, k = map(int, input_data[0].split())
    logs_length = list(map(int, input_data[1].split()))
    
    sol = Solution()
    sol.solve(n, k, logs_length)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
