import sys

def main():
    # Read the integer n which represents the length of the string
    n = int(input().strip())
    
    # Read the string s which contains characters 'R', 'G', and 'B'
    s = input().strip()
    
    # Initialize counters for each color
    rc = gc = bc = 0
    
    # Count the occurrences of each character in the string
    for char in s:
        if char == 'R':
            rc += 1
        elif char == 'G':
            gc += 1
        elif char == 'B':
            bc += 1
    
    # Calculate the initial result based on the product of the counts
    result = rc * gc * bc
    
    # Iterate through all pairs of indices (i, k) to check conditions
    for i in range(1, n):
        for k in range(i + 1, n):
            # Check if the sum of indices is even
            if (i + k) % 2 == 0:
                # Get the characters at the current indices
                is_ = s[i]
                ks = s[k]
                js = s[(i + k) // 2]
                
                # Check if all three characters are different
                if is_ != ks and ks != js and js != is_:
                    result -= 1
    
    # Output the final result
    print(result)

if __name__ == "__main__":
    main()
