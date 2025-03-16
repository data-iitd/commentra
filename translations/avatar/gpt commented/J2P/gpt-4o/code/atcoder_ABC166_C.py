# Import the necessary module
import sys

def main():
    # Read the number of elements (N) and the number of comparisons (M)
    N = int(sys.stdin.readline().strip())
    M = int(sys.stdin.readline().strip())
    
    # Initialize a list to hold the heights and a boolean list to track valid heights
    H = [0] * N
    ans = [True] * N
    
    # Read the heights
    for i in range(N):
        H[i] = int(sys.stdin.readline().strip())
    
    # Process M comparisons between pairs of heights
    for _ in range(M):
        temp1, temp2 = map(int, sys.stdin.readline().strip().split())
        
        # Compare the heights and update the ans list based on the comparison results
        if H[temp1 - 1] < H[temp2 - 1]:
            ans[temp1 - 1] = False  # temp1 is shorter, mark it as invalid
        elif H[temp1 - 1] > H[temp2 - 1]:
            ans[temp2 - 1] = False  # temp2 is shorter, mark it as invalid
        else:
            # If heights are equal, mark both as invalid
            ans[temp1 - 1] = False
            ans[temp2 - 1] = False
    
    # Count the number of valid heights
    ans2 = sum(ans)  # Count True values in ans list
    
    # Output the count of valid heights
    print(ans2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
