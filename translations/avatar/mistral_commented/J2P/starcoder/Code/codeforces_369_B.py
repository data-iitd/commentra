
import sys

# Function to get the updated scores of all points
def getPoints(n, k, l, r, sAll, sk):
    ans = [l] * n # Initializing an array ans of size n to store the updated scores of all points

    # Filling the initial scores of all points with the value l
    for i in range(n):
        ans[i] = l

    # Calculating the remaining score after removing the given k points and segments of length l
    sAll -= sk + (n - k) * l

    # Removing the score of the given k points
    sk -= k * l

    # Finding the indices of the points to be increased in the first while loop
    idx = n - 1
    while sk > 0 and idx >= n - k:
        ans[idx] += 1 # Increasing the score of the current point by 1
        sk -= 1 # Decreasing the remaining score by 1
        idx -= 1

    # Finding the indices of the points to be increased in the second while loop
    while sAll > 0:
        idx = 0
        while sAll > 0 and idx < n - k:
            ans[idx] += 1 # Increasing the score of the current point by 1
            sAll -= 1 # Decreasing the remaining score by 1
            idx += 1

    # Returning the updated scores of all points as an array
    return ans

# Main function
def main():
    # Reading input values from the user
    n = int(input()) # Reading the number of points n
    k = int(input()) # Reading the number of points to be removed k
    l = int(input()) # Reading the length l of each segment
    r = int(input()) # Reading the radius r of each circle
    sAll = int(input()) # Reading the total score before removing points
    sk = int(input()) # Reading the score contributed by the k points to be removed

    # Calling the getPoints() method to get the updated scores of all points
    ans = getPoints(n, k, l, r, sAll, sk)

    # Printing the updated scores of all points
    for num in ans:
        print(num, end=" ") # Printing each updated score followed by a space
    print() # Printing a newline after printing all scores

# Calling the main function
if __name__ == "__main__":
    main()

