import sys

INF = int(1e9) + 5  # Initializing a large constant value

def main():
    n = int(input())  # Reading the number of elements in the arrays

    a = []  # Creating a list to store the first array elements
    b = []  # Creating a list to store the second array elements

    left = INF
    right = 0  # Initializing left and right variables to store the minimum and maximum elements respectively

    # Reading the elements of the arrays and updating the minimum and maximum elements
    for i in range(n):
        a.append(int(input()))  # Reading an element from the first array and adding it to the list
        b.append(int(input()))  # Reading an element from the second array and adding it to the list
        left = min(left, a[i])  # Finding the minimum element in the first array
        right = max(right, b[i])  # Finding the maximum element in the second array

    # Checking if there is an element that has the same minimum and maximum value in both arrays
    for i in range(n):
        if left == a[i] and right == b[i]:  # Checking if the current element in both arrays has the same minimum and maximum value
            print(i + 1)  # If true, printing the index of the element (1-based index)
            return  # Exiting the program after finding the element

    # If no such element is found, printing -1
    print(-1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
