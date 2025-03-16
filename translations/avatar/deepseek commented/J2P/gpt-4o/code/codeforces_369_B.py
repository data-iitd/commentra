import sys

def get_points(n, k, l, r, s_all, sk):
    ans = [l] * n  # Initializing an array to store the result with the lower bound value 'l'
    
    # Subtracting the initial points for the first group and the remaining elements
    s_all -= sk + (n - k) * l
    sk -= k * l
    
    # Distributing the remaining points to the first group until sk is zero
    while sk > 0:
        idx = n - 1  # Starting from the last element in the array
        while sk > 0 and idx >= n - k:
            ans[idx] += 1  # Incrementing the points
            sk -= 1  # Decrementing the remaining points to distribute
            idx -= 1  # Moving to the previous element
    
    # Distributing the remaining points to the remaining elements until s_all is zero
    while s_all > 0:
        idx = 0  # Starting from the first element in the array
        while s_all > 0 and idx < n - k:
            ans[idx] += 1  # Incrementing the points
            s_all -= 1  # Decrementing the remaining points to distribute
            idx += 1  # Moving to the next element
    
    return ans  # Returning the result array

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    n = int(input_data[0])  # Reading the number of elements
    k = int(input_data[1])  # Reading the number of elements in the first group
    l = int(input_data[2])  # Reading the lower bound for the points
    r = int(input_data[3])  # Reading the upper bound for the points
    s_all = int(input_data[4])  # Reading the total sum of points
    sk = int(input_data[5])  # Reading the sum of points for the first group
    
    ans = get_points(n, k, l, r, s_all, sk)  # Calling the get_points function to compute the result
    
    print(" ".join(map(str, ans)))  # Printing the result array

# <END-OF-CODE>
