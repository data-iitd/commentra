import array // Importing necessary modules for array operations and input handling
import sys // Importing necessary modules for input handling

def getPoints(n, k, l, r, sAll, sk):
    ans = array.array('i', [l] * n) // Initializing an array to store the result
    sAll -= sk + (n - k) * l // Subtracting the initial points for the first group and the remaining elements
    sk -= k * l // Subtracting the initial points for the first group
    
    // Distributing the remaining points to the first group until sk is zero
    while sk > 0:
        idx = n - 1 // Starting from the last element in the array
        while sk > 0 and idx >= n - k:
            ans[idx] += 1 // Incrementing the points and moving to the previous element
            sk -= 1 // Decrementing the remaining points to distribute
            idx -= 1
    
    // Distributing the remaining points to the remaining elements until sAll is zero
    while sAll > 0:
        idx = 0 // Starting from the first element in the array
        while sAll > 0 and idx < n - k:
            ans[idx] += 1 // Incrementing the points and moving to the next element
            sAll -= 1 // Decrementing the remaining points to distribute
            idx += 1
    
    return ans // Returning the result array

def main():
    n, k, l, r, sAll, sk = map(int, sys.stdin.readline().split()) // Reading the input
    ans = getPoints(n, k, l, r, sAll, sk) // Calling the getPoints method to compute the result
    
    for num in ans: // Iterating through the result array to print each element
        print(num, end=' ') // Printing each element followed by a space
    print() // Printing a newline at the end

if __name__ == '__main__':
    main() // Calling the main method

