# Import the math library for pow() function
import math

# Main function
def main():
    n = int(input())  # Read an integer value from the standard input and assign it to variable n

    for i in range(1, n + 1):  # Start a for loop that iterates from 1 to n
        x = i  # Assign the value of i to variable x
        s = str(x)  # Convert integer x to string s

        if x % 3 == 0 or x % 10 == 3:  # Check if x is divisible by 3 or its last digit is 3
            print(i, end=' ')  # If true, print i followed by a space
            continue  # Skip the rest of the loop body and move to the next iteration
        else:  # If x is not divisible by 3 and its last digit is not 3
            k = len(s)  # Get the size of string s

            while k > 0:  # Start a while loop that runs as long as the size of string s is greater than 0
                k -= 1  # Decrease the size of string s by 1
                j = int(math.pow(10, k))  # Calculate the value of the power of 10 raised to the power of the current digit position

                if (x // j) % 10 == 3:  # Check if the digit in the current position of x is 3
                    print(i, end=' ')  # If true, print i followed by a space
                    break  # Exit the while loop and move to the next iteration of the for loop

    print()  # Print a newline character after the loop is finished

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
