import sys

mod = int(1e9 + 7)  # Defining a constant value for modulo arithmetic

DX = [-1, 0, 1, 0]  # Defining the four directions for BFS/DFS
DY = [0, -1, 0, 1]

n = 0  # Number of elements in the array 'a'
k = 0  # A given value
a = []  # The array to be processed

def check(x):
    tot = 0  # Initializing a variable to store the total number of elements that can be covered

    for i in range(n):  # Iterating through all the elements in the array 'a'
        now = a[i]  # Reading the current element
        l, r = 0, n  # Initializing the left and right indices for the binary search

        if now >= 0:  # If the current element is non-negative
            while l < r:  # Performing binary search to find the index 'c'
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1  # Update the left index
                else:
                    r = c  # Update the right index
            tot += l  # Adding the index 'l' to the total number of elements that can be covered
        else:  # If the current element is negative
            while l < r:  # Performing binary search to find the index 'c'
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1  # Update the left index
                else:
                    r = c  # Update the right index
            tot += (n - l)  # Adding the remaining elements to the total number of elements that can be covered

        if now * now < x:  # If the square of the current element is smaller than 'x'
            tot -= 1  # Decrement the total number of elements that can be covered

        if tot // 2 < k:  # If the total number of elements that can be covered is less than 'k'
            return True  # Return true

    return False  # Otherwise, return false

def main():
    global n, k, a
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Reading the number of elements in the array 'a'
    k = int(data[1])  # Reading the given value 'k'
    a = list(map(int, data[2:n+2]))  # Reading the elements of the array 'a'

    a.sort()  # Sorting the elements of the array 'a' in ascending order

    INF = int(1e18) + 1  # Defining a large constant value for the upper bound of the binary search range
    l, r = -INF, INF  # Initializing the binary search range

    while l + 1 < r:  # Performing binary search to find the answer
        c = (l + r) // 2
        if check(c):
            l = c  # If the condition is satisfied, update the lower bound
        else:
            r = c  # Otherwise, update the upper bound

    print(l)  # Printing the answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
