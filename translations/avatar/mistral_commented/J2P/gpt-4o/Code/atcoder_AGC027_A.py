# Importing the necessary module for reading input
import sys

def main():  # Defining the main function
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings

    N = int(data[0])  # Reading the number of elements in the list
    x = int(data[1])  # Reading the target value

    sweet = []  # Creating an empty list to store the elements

    for i in range(N):  # A loop to read and add N elements to the list
        a = int(data[i + 2])  # Reading an element from the input
        sweet.append(a)  # Adding the element to the list

    sweet.sort()  # Sorting the list in ascending order

    num = 0  # Initializing a variable to keep track of the number of elements that can be subtracted from x

    for i in range(N):  # A loop to find the number of elements that can be subtracted from x
        if x - sweet[num] >= 0:  # Checking if x is greater than or equal to the current element in the list
            x -= sweet[num]  # Subtracting the current element from x
            num += 1  # Incrementing the num variable
        else:  # If x is less than the current element in the list
            break  # Exiting the loop

    if (num == N) and (x > 0):  # Checking if all elements have been subtracted from x and x is still greater than 0
        num -= 1  # Decrementing the num variable by 1

    print(num)  # Printing the number of elements that can be subtracted from x

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
