# Importing the necessary module
import sys

def main():
    n = int(input())  # Reading the number of elements in the array from the standard input
    arr = list(map(int, input().split()))  # Reading the elements of the array from the standard input
    sum_arr = sum(arr)  # Calculating the sum of the array elements

    c = 0  # Initializing the counter variable to 0
    indices = []  # Creating a list to store the indices of the elements that satisfy the condition

    for i in range(n):  # Starting a for loop to check if an element satisfies the condition
        if (sum_arr - arr[i]) % (n - 1) == 0 and (sum_arr - arr[i]) // (n - 1) == arr[i]:  # Checking the condition
            c += 1  # Incrementing the counter variable if the condition is true
            indices.append(i + 1)  # Appending the index of the current element to the list (1-based index)

    print(c)  # Printing the number of elements that satisfy the condition
    print(" ".join(map(str, indices)))  # Printing the indices of the elements that satisfy the condition separated by a space

if __name__ == "__main__":
    main()

# <END-OF-CODE>
