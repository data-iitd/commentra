# Importing the necessary modules
import sys

def main():
    # Reading the first integer input 'n' from the user
    n = int(input())
    # Reading the second integer input 'k' from the user
    k = int(input())
    # Creating a list 'arr' of size 'n'
    arr = list(map(int, input().split()))

    # Initializing two integer variables 'o' and 'e' to 0
    o = 0
    e = 0

    # Counting the number of 1's and 0's in the array 'arr'
    for i in range(n):
        if arr[i] == 1:
            o += 1  # Incrementing the variable 'o' when the current element in the array is 1
        else:
            e += 1  # Incrementing the variable 'e' when the current element in the array is 0

    res = []  # Creating a list to store the output strings

    # Processing the user queries
    for i in range(k):
        l, r = map(int, input().split())  # Reading the left index 'l' and right index 'r' of the query from the user

        if (r - l + 1) % 2 == 1:  # Checking if the length of the query is odd
            res.append("0")  # If the length is odd, appending '0' to the output list
        else:  # If the length is even
            if (r - l + 1) // 2 <= o:  # Checking if half of the length is less than or equal to the number of 1's in the array
                res.append("1")  # If it is, appending '1' to the output list
            else:  # Otherwise
                res.append("0")  # Appending '0' to the output list

    print("\n".join(res))  # Printing the final output strings
    # No need to explicitly close input in Python

if __name__ == "__main__":
    main()  # Calling the main function to execute the program

# <END-OF-CODE>
