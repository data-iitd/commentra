def main():
    while True:
        n, m = map(int, input().split())
        if n == 0:
            break  # Break the loop if n is 0
        
        # Initialize arrays for each iteration
        here = [0] * 100001
        dp1 = [0] * 100001
        dp2 = [0] * 100001
        
        # Flag to determine behavior based on input
        dpflg = False
        
        # Read m values and mark them in 'here'
        for _ in range(m):
            a = int(input())
            if a == 0:
                dpflg = True  # Set flag if any value is 0
            here[a] = 1
        
        # Variables to store maximum lengths of sequences
        maxi1 = 0
        maxi2 = 0
        
        # Calculate maximum length of sequences in dp1
        for i in range(1, n + 1):
            if here[i] == 1:
                dp1[i] = dp1[i - 1] + 1
            maxi1 = max(dp1[i], maxi1)
        
        # Calculate maximum length of sequences in dp2
        for i in range(1, n + 1):
            if here[i] == 1:
                dp2[i] = dp2[i - 1] + 1
            else:
                dp2[i] = dp1[i - 1] + 1
            maxi2 = max(dp2[i], maxi2)
        
        # Output the result based on the value of dpflg
        if not dpflg:
            print(maxi1)
        else:
            print(maxi2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
