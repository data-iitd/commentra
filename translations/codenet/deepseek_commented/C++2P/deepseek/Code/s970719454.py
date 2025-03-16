import sys

# Declare arrays to store information
here = [0] * 100001  # To mark the presence of elements
dp1 = [0] * 100001  # Dynamic programming array 1
dp2 = [0] * 100001  # Dynamic programming array 2

# Main loop to read input values
for line in sys.stdin:
    if line.strip() == "0":
        break  # Break the loop if n is 0
    
    # Initialize arrays for each iteration
    for i in range(100001):
        here[i] = dp1[i] = dp2[i] = 0
    
    # Read n and m values and mark them in 'here'
    data = list(map(int, line.split()))
    n, m = data[0], data[1]
    
    # Flag to determine behavior based on input
    dpflg = False
    
    # Read m values and mark them in 'here'
    for i in range(m):
        a = int(sys.stdin.readline().strip())
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
