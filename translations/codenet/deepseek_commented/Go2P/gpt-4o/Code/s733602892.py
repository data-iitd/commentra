import sys
import bisect

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    # Read the number of elements N and the maximum number of operations K
    N, K = read_ints(2)
    
    # Read the list of integers As
    As = read_ints(N)
    
    # Read the list of integers Fs
    Fs = read_ints(N)
    
    # Sort As in ascending order
    As.sort()
    
    # Sort Fs in descending order
    Fs.sort(reverse=True)
    
    # Calculate the scores by multiplying corresponding elements of As and Fs
    scores = [As[i] * Fs[i] for i in range(N)]
    
    # Sort the scores in descending order
    scores.sort(reverse=True)
    
    # Initialize the boundaries for binary search
    ok = scores[0]
    ng = -1
    
    # Perform binary search to find the maximum score
    while ok - ng > 1:
        mid = (ok + ng) // 2
        
        # Check if it's possible to achieve mid score with at most K operations
        is_ok = True
        k = K
        for i in range(N):
            if As[i] * Fs[i] > mid:
                k -= As[i] - mid // Fs[i]
            if k < 0:
                is_ok = False
                break
        
        # Adjust the search boundaries based on the result of the check
        if is_ok:
            ok = mid
        else:
            ng = mid
    
    # Print the maximum score found
    print(ok)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
