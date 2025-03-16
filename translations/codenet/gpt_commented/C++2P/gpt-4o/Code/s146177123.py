# Import necessary libraries
import sys

# Segment representation for digits 0-9
seg = [
    [0, 1, 1, 1, 1, 1, 1],  # 0
    [0, 0, 0, 0, 1, 1, 0],  # 1
    [1, 0, 1, 1, 0, 1, 1],  # 2
    [1, 0, 0, 1, 1, 1, 1],  # 3
    [1, 1, 0, 0, 1, 1, 0],  # 4
    [1, 1, 0, 1, 1, 0, 1],  # 5
    [1, 1, 1, 1, 1, 0, 1],  # 6
    [0, 1, 0, 0, 1, 1, 1],  # 7
    [1, 1, 1, 1, 1, 1, 1],  # 8
    [1, 1, 0, 1, 1, 1, 1]   # 9
]

def main():
    # Read input until a negative number is encountered
    for line in sys.stdin:
        n = int(line.strip())
        if n < 0:
            break
        
        st = [0] * 7  # Initialize segment states to 0

        # Process each digit input
        for _ in range(n):
            t = int(sys.stdin.readline().strip())  # Read the digit
            ans = ['0'] * 7  # Initialize answer array to store segment states

            # Determine the segment states based on the input digit
            for i in range(7):
                ans[i] = '1' if st[i] ^ seg[t][i] else '0'  # Calculate the current segment state
                st[i] = seg[t][i]  # Update the current segment state
            
            print(''.join(ans))  # Output the segment states for the current digit

if __name__ == "__main__":
    main()

# <END-OF-CODE>
