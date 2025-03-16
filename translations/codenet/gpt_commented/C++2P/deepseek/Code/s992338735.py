def main():
    while True:
        N = int(input())
        if N <= 0:
            break
        
        M = -1
        m = 1001
        addup = 0
        
        for _ in range(N):
            S = int(input())
            addup += S
            
            if S > M:
                M = S
            
            if S < m:
                m = S
        
        average = (addup - M - m) // (N - 2)
        print(average)

main()
