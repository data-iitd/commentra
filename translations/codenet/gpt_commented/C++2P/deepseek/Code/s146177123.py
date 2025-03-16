# Segment representation for digits 0-9
seg = [
    [0, 1, 1, 1, 1, 1, 1], # 0
    [0, 0, 0, 0, 1, 1, 0], # 1
    [1, 0, 1, 1, 0, 1, 1], # 2
    [1, 0, 0, 1, 1, 1, 1], # 3
    [1, 1, 0, 0, 1, 1, 0], # 4
    [1, 1, 0, 1, 1, 0, 1], # 5
    [1, 1, 1, 1, 1, 0, 1], # 6
    [0, 1, 0, 0, 1, 1, 1], # 7
    [1, 1, 1, 1, 1, 1, 1], # 8
    [1, 1, 0, 1, 1, 1, 1]  # 9
]

while True:
    n = int(input())
    if n < 0:
        break
    
    st = [0] * 7  # Array to store the state of segments
    
    # Process each digit input
    for _ in range(n):
        t = int(input())
        ans = ['0'] * 7  # Initialize answer array to store segment states
        
        # Determine the segment states based on the input digit
        for i in range(7):
            # Calculate the current segment state and store it in ans
            ans[i] = '1' if st[i] ^ seg[t][i] else '0'
            st[i] = seg[t][i]  # Update the current segment state
        
        print(''.join(ans))  # Output the segment states for the current digit

