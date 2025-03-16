# Importing the necessary module
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Reading the number of elements in the array H
    M = int(data[1])  # Reading the number of queries

    H = [0] * N  # Creating an array of size N to store the heights
    ans = [True] * N  # Creating a boolean array of size N to store the answer for each index

    index = 2  # Starting index for heights in the input data
    for i in range(N):  # Reading the elements of the array H
        H[i] = int(data[index])
        index += 1

    for query in range(M):  # Processing each query
        temp1 = int(data[index]) - 1  # Reading the first index (0-based)
        temp2 = int(data[index + 1]) - 1  # Reading the second index (0-based)
        index += 2

        if H[temp1] < H[temp2]:  # If the height of the first index is less than the second index
            ans[temp1] = False  # The first index cannot be in the left half
        elif H[temp1] > H[temp2]:  # If the height of the first index is greater than the second index
            ans[temp2] = False  # The second index cannot be in the left half
        else:  # If the heights are equal
            ans[temp1] = False  # Both the first and second indices cannot be in the left half
            ans[temp2] = False

    ans2 = sum(ans)  # Counting the number of elements in the left half

    print(ans2)  # Printing the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
