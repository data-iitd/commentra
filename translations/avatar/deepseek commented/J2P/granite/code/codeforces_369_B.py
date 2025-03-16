
import sys # Importing necessary modules for input handling and array operations

def getPoints(n, k, l, r, sAll, sk):
    ans = [l] * n # Initializing an array to store the result and filling it with the lower bound value 'l'
    
    # Subtracting the initial points for the first group and the remaining elements
    sAll -= sk + (n - k) * l
    sk -= k * l
    
    # Distributing the remaining points to the first group until sk is zero
    while sk > 0:
        idx = n - 1 # Starting from the last element in the array
        while sk > 0 and idx >= n - k:
            ans[idx] += 1 # Incrementing the points and moving to the previous element
            sk -= 1 # Decrementing the remaining points to distribute
    
    # Distributing the remaining points to the remaining elements until sAll is zero
    while sAll > 0:
        idx = 0 # Starting from the first element in the array
        while sAll > 0 and idx < n - k:
            ans[idx] += 1 # Incrementing the points and moving to the next element
            sAll -= 1 # Decrementing the remaining points to distribute
    
    return ans # Returning the result array

def main():
    n, k, l, r, sAll, sk = map(int, sys.stdin.readline().split()) # Reading the input values
    ans = getPoints(n, k, l, r, sAll, sk) # Calling the getPoints method to compute the result
    
    print(" ".join(map(str, ans))) # Printing the result array

if __name__ == "__main__":
    main() # Executing the main function

