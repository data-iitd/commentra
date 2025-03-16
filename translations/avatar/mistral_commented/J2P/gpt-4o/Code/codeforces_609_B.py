# Importing the required module for reading input
import sys

# Main function is the entry point of the Python application
def main():
    # Reading the first integer input n from the user
    n = int(input())
    
    # Reading the second integer input m from the user
    m = int(input())
    
    # Creating a list arr to store the input integers
    arr = [0] * n
    
    # Creating a list gen to store the count of each integer occurrence
    gen = [0] * 11
    
    # Reading the input integers and storing them in the arr list
    for i in range(n):
        arr[i] = int(input())
        # Incrementing the count of arr[i] in the gen list
        gen[arr[i]] += 1
    
    # Calculating the answer
    ans = 0
    for i in range(1, m + 1):
        for k in range(1, m + 1):
            # Skipping the case when i and k are equal to avoid double counting
            if i != k:
                # Multiplying the count of i and k and adding it to the answer
                ans += gen[i] * gen[k]
    
    # Printing the answer divided by 2
    print(ans // 2)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
