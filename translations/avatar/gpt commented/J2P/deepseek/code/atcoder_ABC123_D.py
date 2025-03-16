import sys

def main():
    # Read the sizes of the three lists from standard input
    x = list(map(int, sys.stdin.readline().split()))
    
    # Read the maximum product limit
    k = int(sys.stdin.readline())
    
    # Read the elements for each list and sort them
    a = [list(map(int, sys.stdin.readline().split())) for _ in range(3)]
    for i in range(3):
        a[i].sort(reverse=True)  # Sort the list in descending order
    
    # List to store the valid sums
    ans = []
    
    # Generate all combinations of elements from the three lists
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                # Check if the product of the indices is within the limit k
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    # Calculate the sum of the selected elements from each list
                    tmp = a[0][i] + a[1][j] + a[2][m]
                    ans.append(tmp)  # Add the sum to the answer list
    
    # Sort the list of sums in ascending order
    ans.sort()
    
    # Get the size of the answer list
    n = len(ans)
    
    # Print the largest k sums from the answer list
    for i in range(k):
        print(ans[n - i - 1])  # Print the k largest sums

if __name__ == "__main__":
    main()
