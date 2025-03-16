def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the integer n
    s = data[1]       # Read the string s
    
    rc = 0  # Counter for 'R' characters
    gc = 0  # Counter for 'G' characters
    bc = 0  # Counter for 'B' characters
    
    # Count the number of 'R', 'G', and 'B' characters in the string s
    for char in s:
        if char == 'R':
            rc += 1
        elif char == 'G':
            gc += 1
        else:
            bc += 1
    
    result = rc * gc * bc  # Calculate the initial product of counts
    
    # Iterate through possible pairs of indices i and k where i < k
    for i in range(1, n + 1):
        for k in range(i + 1, n + 1):
            if (i + k) % 2 == 0:  # Check if the sum of indices is even
                is_char = s[i - 1]  # Character at index i-1
                ks_char = s[k - 1]  # Character at index k-1
                js_char = s[((i + k) // 2) - 1]  # Character at the middle index
                
                # Check if the characters are all different and not equal to each other
                if is_char != ks_char and ks_char != js_char and js_char != is_char:
                    result -= 1  # Decrement the result if conditions are met
    
    print(result)  # Print the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
