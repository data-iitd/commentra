
import array // Importing the array module for array manipulation
import math // Importing the math module for mathematical operations

def getPoints(n, k, l, r, sAll, sk):
    ans = array.array('i', [l] * n) // Initializing an integer array ans of size n to store the updated scores of all points

    # Filling the initial scores of all points with the value l
    # Arrays.fill(ans, l)

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
    n, k, l, r, sAll, sk = map(int, input().split()) # Reading input values from the user

    # Calling the getPoints() method to get the updated scores of all points
    ans = getPoints(n, k, l, r, sAll, sk)

    # Printing the updated scores of all points
    for num in ans:
        print(num, end=' ') # Printing each updated score followed by a space
    print() # Printing a newline after printing all scores

if __name__ == '__main__':
    main()

