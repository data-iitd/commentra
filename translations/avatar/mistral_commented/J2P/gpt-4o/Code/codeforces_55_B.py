import sys  # Importing the sys module for input handling

def main():  # Defining the main function
    min_value = float('inf')  # Initializing the minimum value to infinity
    arr = []  # Creating an empty list to store the input numbers

    for _ in range(4):  # Reading 4 numbers from the standard input and storing them in the list
        arr.append(int(input().strip()))  # Using input() to read and convert to int

    ops = []  # Creating a list to store the operators

    for _ in range(3):  # Reading 3 operators from the standard input and storing them in the list
        ops.append(input().strip())  # Using input() to read the operator

    util(arr, ops, 0, min_value)  # Calling the util function with the list, the list of operators, and the index of the first operator

def util(arr, ops, idx, min_value):  # Starting the util function
    if idx == 3:  # Checking if the index of the operator is equal to 3 (the last operator)
        global min_value  # Declaring min_value as global to modify it
        min_value = min(min_value, arr[0])  # Updating the minimum value with the first number in the list
        return  # Exiting the function

    for i in range(len(arr)):  # Iterating through the list to find two numbers for the current operator
        for j in range(i + 1, len(arr)):
            a = []  # Creating a new list to store the result of the current operation

            for k in range(len(arr)):  # Iterating through the list to exclude the current and previous numbers
                if k != j and k != i:
                    a.append(arr[k])  # Adding the excluded number to the new list

            if ops[idx] == "+":  # Checking if the current operator is '+'
                res = arr[i] + arr[j]  # Performing the addition operation
            else:  # Else, the current operator is '*'
                res = arr[i] * arr[j]  # Performing the multiplication operation

            a.append(res)  # Adding the result to the new list
            util(a, ops, idx + 1, min_value)  # Recursively calling the util function with the new list, the list of operators, and the index of the next operator

if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>
