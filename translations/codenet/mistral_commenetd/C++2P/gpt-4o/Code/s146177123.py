# Importing necessary libraries
import sys

# A 2D boolean array representing the segment tree
seg = [
    [0, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 1, 1, 0],
    [1, 0, 1, 1, 0, 1, 1],
    [1, 0, 0, 1, 1, 1, 1],
    [1, 1, 0, 0, 1, 1, 0],
    [1, 1, 0, 1, 1, 0, 1],
    [1, 1, 1, 1, 1, 0, 1],
    [0, 1, 0, 0, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 1],
    [1, 1, 0, 1, 1, 1, 1]
]

def main():
    st = [0] * 7  # A boolean array to store the current segment tree state

    for line in sys.stdin:
        n = int(line.strip())  # Reading the number of test cases
        if n == -1:  # End of input
            break
        
        for _ in range(n):  # Processing each test case
            t = int(sys.stdin.readline().strip())  # Reading the current test case
            ans = ['0'] * 7  # Initializing an array to store the answer as a string of 0s and 1s
            
            for i in range(7):  # Iterating through each bit position in the segment tree
                ans[i] = '1' if st[i] ^ seg[t][i] else '0'  # Updating the answer
                st[i] = seg[t][i]  # Updating the segment tree state for the current bit position
            
            print(''.join(ans))  # Printing the answer for the current test case

if __name__ == "__main__":
    main()

# <END-OF-CODE>
