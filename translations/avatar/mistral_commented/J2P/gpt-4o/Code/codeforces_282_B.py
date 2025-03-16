# Importing the necessary module
import sys

def main():
    n = int(input())  # Reading the number of test cases from the standard input

    # Initializing variables
    s1, s2 = 0, 0  # To keep track of the sum of x and y coordinates respectively
    ch = []  # List to store characters
    flag = 0  # Flag to indicate if the difference exceeds 500

    # Reading input for each test case
    for _ in range(n):
        x, y = map(int, input().split())  # Reading the values of 'x' and 'y'

        temp1 = s1 + x  # Calculating the sum of 's1' and 'x'
        temp2 = s2 + y  # Calculating the sum of 's2' and 'y'

        # Checking if the difference between the sums is within the limit of 500
        if abs(temp1 - temp2) <= 500:
            s1 += x  # Updating the value of 's1'
            ch.append('A')  # Adding 'A' to the list 'ch'
            continue  # Moving to the next iteration

        # Checking if the difference between the absolute values of the sums is within the limit of 500
        if abs(temp1 - s2) <= 500:
            s2 += y  # Updating the value of 's2'
            ch.append('G')  # Adding 'G' to the list 'ch'
            continue  # Moving to the next iteration

        flag = 1  # Setting the flag to 1 if the difference between the sums is greater than 500
        break  # Exiting the loop if the difference is greater than 500

    # Checking if the flag is set to 1
    if flag == 1:
        print(-1)  # Printing -1 if the difference is greater than 500
    else:
        ans = ''.join(ch)  # Converting the list 'ch' to a string 'ans'
        print(ans)  # Printing the string 'ans' as the answer for the current test case

if __name__ == "__main__":
    main()

# <END-OF-CODE>
