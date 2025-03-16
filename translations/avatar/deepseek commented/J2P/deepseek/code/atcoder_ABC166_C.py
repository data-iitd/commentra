import sys

def main():
    # Read the number of elements N and the number of comparisons M
    N, M = map(int, sys.stdin.readline().split())
    
    # Read the heights of the elements into the list H
    H = list(map(int, sys.stdin.readline().split()))
    
    # Initialize a boolean list to store the result for each element
    ans = [True] * N
    
    # Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
    for _ in range(M):
        temp1, temp2 = map(int, sys.stdin.readline().split())
        
        if H[temp1 - 1] < H[temp2 - 1]:
            ans[temp1 - 1] = False  # Update the boolean list ans based on the comparison results
        elif H[temp1 - 1] > H[temp2 - 1]:
            ans[temp2 - 1] = False  # Update the boolean list ans based on the comparison results
        else:
            ans[temp1 - 1] = False  # Update the boolean list ans based on the comparison results
            ans[temp2 - 1] = False  # Update the boolean list ans based on the comparison results
    
    # Count the number of elements in the boolean list ans that are still true
    ans2 = ans.count(True)
    
    # Print the count
    print(ans2)

if __name__ == "__main__":
    main()
