import sys

def main():
    # Read the number of elements N and the number of groups M
    N, M = map(int, sys.stdin.readline().split())
    
    # Create a list to store bitwise representations for each element
    a = [0] * N
    
    # Read M groups of integers and update the bitwise representation
    for _ in range(M):
        k = list(map(int, sys.stdin.readline().split()))[0]  # Read the number of integers in the current group
        for _ in range(k):
            s = int(sys.stdin.readline()) - 1  # Read the integer and convert to zero-based index
            # Update the bitwise representation for the element
            a[s] |= (1 << _)
    
    # Read M integers to create a bitmask p
    p = 0
    for _ in range(M):
        x = int(sys.stdin.readline())  # Read the integer
        p |= (x << _)  # Update the bitmask p
    
    # Initialize a counter for valid combinations
    ans = 0
    
    # Iterate through all possible subsets of N elements
    for s in range(1 << N):
        t = 0  # Initialize a temporary variable to store the XOR result
        for i in range(N):
            # Check if the i-th element is included in the subset
            if (s >> i) & 1:
                # XOR the current element's bitwise representation
                t ^= a[i]
        # Check if the XOR result matches the bitmask p
        if p == t:
            ans += 1  # Increment the count of valid combinations
    
    # Output the total count of valid combinations
    print(ans)

if __name__ == "__main__":
    main()
