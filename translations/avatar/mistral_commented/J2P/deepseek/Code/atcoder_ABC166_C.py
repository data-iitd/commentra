import sys

def main():
    # Reading the number of elements in the array H and the number of queries
    N = int(input().strip())
    M = int(input().strip())

    # Reading the elements of the array H
    H = list(map(int, input().strip().split()))
    ans = [True] * N  # Creating a boolean list of size N to store the answer for each index

    # Processing each query
    for _ in range(M):
        temp1, temp2 = map(int, input().strip().split())

        # If the height of the first index is less than the second index
        if H[temp1 - 1] < H[temp2 - 1]:
            ans[temp1 - 1] = False
        # If the height of the first index is greater than the second index
        elif H[temp1 - 1] > H[temp2 - 1]:
            ans[temp2 - 1] = False
        # If the heights are equal
        else:
            ans[temp1 - 1] = False
            ans[temp2 - 1] = False

    # Counting the number of elements in the left half
    ans2 = ans.count(True)

    # Printing the final answer
    print(ans2)

if __name__ == "__main__":
    main()
