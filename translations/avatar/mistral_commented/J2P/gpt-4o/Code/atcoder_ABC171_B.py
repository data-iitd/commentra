import sys

class Solution:
    def solve(self, n, k, a):
        # Sort the array a
        a.sort()
        
        # Calculate the answer: sum of first k elements of sorted array a
        ans = sum(a[:k])
        
        # Print the answer
        print(ans)

def main():
    # Read input: number of elements n and the number of summands k
    n, k = map(int, sys.stdin.readline().split())
    
    # Read input array a of size n
    a = list(map(int, sys.stdin.readline().split()))
    
    # Create Solution object and call its solve method
    sol = Solution()
    sol.solve(n, k, a)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
