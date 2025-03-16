# Importing necessary modules
import sys

def main():
    n = int(input())  # Reading the first integer from the standard input stream and assigning it to the variable 'n'

    i = 1  # Initializing the variable 'i' to 1
    k = 0  # Initializing the variable 'k' to 0
    a = [0] * 1000  # Declaring and initializing an integer list of size 1000

    while k <= n:  # Starting a while loop that runs as long as 'k' is less than or equal to 'n'
        i += k  # Incrementing the variable 'i' by the value of 'k'

        if i >= n:  # Checking if the value of 'i' is greater than or equal to 'n'
            while i >= n:
                i -= n  # If yes, then decrement 'i' by 'n' until it becomes less than 'n'

        a[i] += 1  # Incrementing the value of the 'i'-th element of the list 'a' by 1
        k += 1  # Incrementing the variable 'k' by 1

    flag = True  # Initializing the boolean variable 'flag' to true

    for i in range(n):  # Starting a for loop that runs from 0 to 'n'-1
        if a[i] == 0:  # Checking if the 'i'-th element of the list 'a' is equal to 0
            flag = False  # If yes, then set the boolean variable 'flag' to false
            break  # Exiting the for loop

    if flag:
        print("YES")  # If the boolean variable 'flag' is still true after the for loop, then print "YES"
    else:
        print("NO")  # Otherwise, print "NO"

if __name__ == "__main__":
    main()  # Calling the main function to execute the program

# <END-OF-CODE>
