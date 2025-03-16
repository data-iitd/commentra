# Import necessary libraries
import sys

# Array to represent the segments of the digits 0-9
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
    for line in sys.stdin:
        n = int(line.strip())
        if n == -1:  # Check if it's the end of input
            break
        
        st = [0] * 7  # Initialize the state array to represent the current display state
        for _ in range(n):
            t = int(sys.stdin.readline().strip())  # Read the next digit
            ans = ['0'] * 7  # Array to store the current display state
            
            for i in range(7):
                # Calculate the current segment state and store it in the answer array
                ans[i] = '1' if st[i] ^ seg[t][i] else '0'
                # Update the state array with the current segment state
                st[i] = seg[t][i]
            
            # Output the current display state
            print(''.join(ans))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
