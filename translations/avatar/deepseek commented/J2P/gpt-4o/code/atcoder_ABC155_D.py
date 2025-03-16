import sys

mod = int(1e9 + 7)  # Define constant for modulo operation.
DX = [-1, 0, 1, 0]  # Define directions for movement.
DY = [0, -1, 0, 1]

n = 0  # Declare variable for the size of the array.
k = 0  # Declare variable for the target value.
a = []  # Declare list to store the values.

def check(x):
    tot = 0  # Initialize the total count.
    
    for now in a:
        l, r = 0, n  # Initialize the boundaries for binary search.
        
        if now >= 0:  # If the current element is non-negative.
            while l < r:  # Perform binary search.
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1  # Adjust the left boundary.
                else:
                    r = c  # Adjust the right boundary.
            tot += l  # Add the result to the total.
        else:  # If the current element is negative.
            while l < r:  # Perform binary search.
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1  # Adjust the left boundary.
                else:
                    r = c  # Adjust the right boundary.
            tot += (n - l)  # Add the result to the total.
        
        if now * now < x:
            tot -= 1  # Adjust the total if necessary.
    
    return tot // 2 < k  # Return true if the count is less than k.

def main():
    global n, k, a
    n = int(sys.stdin.readline().strip())  # Read the size of the array.
    k = int(sys.stdin.readline().strip())  # Read the target value.
    a = list(map(int, sys.stdin.readline().strip().split()))  # Read the elements of the array.
    
    a.sort()  # Sort the array.
    
    INF = int(1e18) + 1  # Define a large number as infinity.
    l, r = -INF, INF  # Initialize the boundaries of the search.
    
    while l + 1 < r:  # Perform binary search.
        c = (l + r) // 2  # Calculate the middle point.
        if check(c):
            l = c  # Adjust the left boundary.
        else:
            r = c  # Adjust the right boundary.
    
    print(l)  # Print the result.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
