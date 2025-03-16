
import sys

def main():
    # Initialize input stream
    sc = sys.stdin
    
    # Create an array to store the sizes of three lists
    x = [0] * 3
    max = 0 # Variable to track the maximum size
    
    # Read the sizes of the three lists from user input
    for i in range(3):
        x[i] = int(sc.readline())
        max = max(max, x[i]) # Update max if current size is greater
    
    # Read the maximum product limit
    k = int(sc.readline())
    
    # Initialize an array of lists to store the elements for each of the three lists
    a = [[] for _ in range(3)]
    
    # Read the elements for each list and sort them
    for i in range(3):
        for j in range(x[i]):
            a[i].append(int(sc.readline())) # Add elements to the respective list
        a[i].sort() # Sort the list after all elements are added
    
    # Close the input stream as we no longer need input
    sc.close()
    
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
                    ans.append(tmp) # Add the sum to the answer list
    
    # Sort the list of sums in ascending order
    ans.sort()
    
    # Get the size of the answer list
    n = len(ans)
    
    # Print the largest k sums from the answer list
    for i in range(k):
        print(ans[n - i - 1]) # Print the k largest sums
    
    # End of code
    print("