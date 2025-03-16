
import sys  # Importing the sys module for user input

def main():  # Main function to start the program
    x = int(input("Enter the first integer value: "))  # Reading the first integer value from user input
    y = int(input("Enter the second integer value: "))  # Reading the second integer value from user input
    a = int(input("Enter the third integer value: "))  # Reading the third integer value from user input
    b = int(input("Enter the fourth integer value: "))  # Reading the fourth integer value from user input

    j = 2
    i = 0
    x1 = 0
    y1 = 0
    c = 0
    ans = True

    c = max(x, y)  # Finding the maximum value between x and y

    if c > b:  # Checking if the maximum value is greater than b
        print("0")  # If true, printing 0 and setting ans to false
        ans = False

    while c % min(x, y)!= 0 and ans:  # Loop to find the greatest common divisor (GCD)
        if x > y:  # If x is greater than y
            c = x * j  # Multiplying x by j and updating c
            j += 1  # Incrementing j
        else:
            c = y * j  # Multiplying y by j and updating c
            j += 1  # Incrementing j

        if c > b:  # Checking if the current value of c is greater than b
            print("0")  # If true, printing 0 and setting ans to false
            ans = False
            break  # Exiting the loop

    if ans:  # If the GCD has been found
        count = 0  # Initializing a counter variable
        i = a  # Starting the loop from a

        for i in range(a, b + 1):  # Loop to find the number of times c divides i
            if i % c == 0:
                break  # If i is divisible by c, breaking the loop

        if i!= b + 1:  # Checking if the last number in the range is divisible by c
            print(((b - i) // c) + 1)  # Printing the result
        else:
            print("0")  # If the last number is not divisible by c, printing 0

if __name__ == "__main__":  # Executing the main function
    main()

