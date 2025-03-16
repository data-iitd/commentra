import sys

def main():
    start_time = sys.time()
    n = int(input())
    div = 10**9 + 7
    A = list(map(int, input().split()))
    ans = 0
    
    for i in range(60):
        count1 = sum((a >> i) & 1 for a in A)
        a = count1 * (n - count1)
        a = (a << i) % div
        ans = (ans + a) % div
    
    print(ans)
    end_time = sys.time()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
