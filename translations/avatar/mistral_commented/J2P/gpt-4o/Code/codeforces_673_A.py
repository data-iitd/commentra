# Importing the necessary module
from typing import List

def main():
    n = int(input())  # Reading the number of elements in the list from standard input

    a = []  # Creating an empty list named a

    for _ in range(n):  # Using a for loop to read and add each element to the list
        value = int(input())  # Reading an integer value from standard input
        a.append(value)  # Adding the value to the list

    result, pos, flag = 0, 0, 0  # Declaring and initializing the variables result, pos, and flag

    if a[0] > 15:  # Checking if the first element in the list is greater than 15
        result = 15  # Assigning 15 to the result variable if the condition is true
    else:
        for i in range(1, n):  # Using a for loop to compare each element with the previous one
            if a[i] - a[i - 1] > 15:  # Checking if the difference between two consecutive elements is greater than 15
                pos = i - 1  # Assigning the index of the previous element to the pos variable if the condition is true
                flag = 1  # Assigning 1 to the flag variable to indicate that the condition is true
                break  # Exiting the loop if the condition is true
        if flag == 1:  # Checking if the flag variable is equal to 1
            result = a[pos] + 15  # Assigning the sum of the previous element and 15 to the result variable
        else:
            result = a[n - 1] + 15  # Assigning the sum of the last element and 15 to the result variable if the flag variable is 0

    if result > 90:
        result = 90  # Checking if the result is greater than 90 and assigning 90 to the result variable if it is

    print(result)  # Printing the result to the standard output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
