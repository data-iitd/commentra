# Import necessary modules
from collections import defaultdict

def main():
    # Initialize scanner to read input from the standard input
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of elements in the array P from the standard input
    N = int(data[0])
    
    # Initialize an integer array P of size N
    P = [int(data[i]) - 1 for i in range(1, N + 1)]
    
    # Create an empty dictionary to store the indices of the array P corresponding to each unique element
    index_map = {}
    
    # Iterate through each element of the array P and add its index to the dictionary
    for i in range(N):
        index_map[P[i]] = i
    
    # Create an empty list to store the indices of the non-decreasing subsequences
    nglist = []
    
    # Iterate through each index i of the array P, where i < N - 1
    for i in range(N - 1):
        # If the index i corresponds to a smaller element than the next index, add its index to the list
        if index_map[i] > index_map[i + 1]:
            nglist.append(i)
    
    # If there are no non-decreasing subsequences, print 0 and exit the program
    if not nglist:
        print(0)
        return
    
    # Calculate the answer by finding the minimum length of a non-decreasing subsequence
    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    
    # Iterate through each pair of consecutive indices in the list nglist and update the answer if necessary
    for i in range(len(nglist) - 1):
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)
    
    # Print the answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
