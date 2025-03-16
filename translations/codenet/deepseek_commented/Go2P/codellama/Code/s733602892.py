
import sys

def main():
    # Read the number of elements N and the maximum number of operations K
    N, K = map(int, sys.stdin.readline().split())
    
    # Read the list of integers As
    As = list(map(int, sys.stdin.readline().split()))
    
    # Read the list of integers Fs
    Fs = list(map(int, sys.stdin.readline().split()))
    
    # Sort As in ascending order
    As.sort()
    
    # Sort Fs in descending order
    Fs.sort(reverse=True)
    
    # Create a list to store the scores
    scores = [0] * N
    
    # Calculate the scores by multiplying corresponding elements of As and Fs
    for i in range(N):
        scores[i] = As[i] * Fs[i]
    
    # Sort the scores in descending order to prepare for binary search
    scores.sort(reverse=True)
    
    # Initialize the boundaries for binary search
    ok = scores[0]
    ng = -1
    
    # Perform binary search to find the maximum score
    while ok-ng > 1:
        mid = (ok + ng) // 2
        
        # Check if it's possible to achieve mid score with at most K operations
        isOK = True
        k = K
        for i in range(N):
            if As[i]*Fs[i] > mid:
                k -= As[i] - mid//Fs[i]
            if k < 0:
                isOK = False
                break
        
        # Adjust the search boundaries based on the result of the check
        if isOK:
            ok = mid
        else:
            ng = mid
    
    # Print the maximum score found
    print(ok)

